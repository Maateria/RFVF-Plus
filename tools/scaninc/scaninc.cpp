// Copyright(c) 2015-2017 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include <tuple>
#include <fstream>
#include "scaninc.h"
#include "source_file.h"

bool CanOpenFile(std::string path)
{
    FILE *fp = std::fopen(path.c_str(), "rb");

    if (fp == NULL)
        return false;

    std::fclose(fp);
    return true;
}

const char *const USAGE = "Usage: scaninc [-I INCLUDE_PATH] [-M DEPENDENCY_OUT_PATH] FILE_PATH\n";

int main(int argc, char **argv)
{
    std::queue<std::string> filesToProcess;
    std::set<std::string> dependencies;
    std::set<std::string> dependencies_includes;
    std::set<std::string> missing_includes;

    std::vector<std::string> includeDirs;

    bool makeformat = false;
    std::string make_outfile;

    argc--;
    argv++;

    while (argc > 1)
    {
        std::string arg(argv[0]);
        if (arg.substr(0, 2) == "-I")
        {
            std::string includeDir = arg.substr(2);
            if (includeDir.empty())
            {
                argc--;
                argv++;
                includeDir = std::string(argv[0]);
            }
            if (!includeDir.empty() && includeDir.back() != '/')
            {
                includeDir += '/';
            }
            includeDirs.push_back(includeDir);
        }
        else if(arg.substr(0, 2) == "-M")
        {
            makeformat = true;
            argc--;
            argv++;
            make_outfile = std::string(argv[0]);
        }
        else
        {
            FATAL_ERROR(USAGE);
        }
        argc--;
        argv++;
    }

    if (argc != 1) {
        FATAL_ERROR(USAGE);
    }

    std::string initialPath(argv[0]);

    filesToProcess.push(initialPath);

    while (!filesToProcess.empty())
    {
        std::string filePath = filesToProcess.front();
        SourceFile file(filePath);
        filesToProcess.pop();

        includeDirs.push_back(file.GetSrcDir());
        for (auto incbin : file.GetIncbins())
        {
            dependencies.insert(incbin);
        }
        for (auto include : file.GetIncludes())
        {
            bool exists = false;
            std::string path("");
            for (auto includeDir : includeDirs)
            {
                path = includeDir + include;
                if (CanOpenFile(path))
                {
                    exists = true;
                    break;
                }
            }
            if (!exists && (file.FileType() == SourceFileType::Asm || file.FileType() == SourceFileType::Inc))
            {
                path = include;
                if (CanOpenFile(path))
                    exists = true;
            }
            if (!exists)
            {
                // Remember every place it was looked for (see the dependency list rule below)
                for (auto includeDir : includeDirs)
                    missing_includes.insert(includeDir + include);
                if (file.FileType() == SourceFileType::Asm || file.FileType() == SourceFileType::Inc)
                    missing_includes.insert(include);
                continue;
            }

            dependencies_includes.insert(path);
            bool inserted = dependencies.insert(path).second;
            if (inserted && exists)
            {
                filesToProcess.push(path);
            }
        }
        includeDirs.pop_back();
    }

    if(!makeformat)
    {
        for (const std::string &path : dependencies)
        {
            std::printf("%s\n", path.c_str());
        }
        std::cout << std::endl;
    }
    else
    {
        // Write out make rules to a temporary file, renamed to the .d file once complete: an interrupted or failed
        // write cannot leave a truncated .d file, which make would read as an incomplete dependency list
        std::string tmp_outfile = make_outfile + ".tmp";
        std::ofstream output(tmp_outfile);

        // Print a make rule for the object file
        size_t ext_pos = make_outfile.find_last_of(".");
        auto object_file = make_outfile.substr(0, ext_pos + 1) + "o";
        output << object_file.c_str() << ":";
        for (const std::string &path : dependencies)
        {
            output << " " << path;
        }
        output << '\n';

        // Dependency list rule.
        // Although these rules are identical, they need to be separate, else make will trigger the rule again after the file is created for the first time.
        output << make_outfile.c_str() << ":";
        for (const std::string &path : dependencies_includes)
        {
            output << " " << path;
        }
        // An include found nowhere is left out above (it would be remade, and this file rescanned, on every run).
        // If it appears later in any place it was looked for, this wildcard, expanded each time make reads this
        // file, makes this file out of date, so it is rescanned and the new include is tracked from then on.
        if (!missing_includes.empty())
        {
            output << " $(wildcard";
            for (const std::string &path : missing_includes)
            {
                output << " " << path;
            }
            output << ")";
        }
        output << '\n';

        // The Makefile checks once which of all the listed includes are gone (make itself ignores a missing
        // prerequisite here, because of .SECONDARY:), and rescans the .d files that list one of them
        if (!dependencies_includes.empty())
        {
            output << "SCANINC_LISTED +=";
            for (const std::string &path : dependencies_includes)
            {
                output << " " << path;
            }
            output << '\n';
        }

        // Dummy rules
        // If a dependency is deleted, make will try to make it, instead of rescanning the dependencies before trying to do that.
        for (const std::string &path : dependencies)
        {
            output << path << ":\n";
        }

        output.close();
        if (!output || std::rename(tmp_outfile.c_str(), make_outfile.c_str()) != 0)
        {
            std::remove(tmp_outfile.c_str());
            FATAL_ERROR("Failed to write \"%s\".\n", make_outfile.c_str());
        }
    }
}
