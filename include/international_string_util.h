#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

// RFVF+: the two bits of Emerald's international_string_util that its Battle Frontier code uses
#include "text.h"
#include "string_util.h"

// Emerald's: 0 when the string is wider than totalWidth (a negative x would wrap as a u8)
#define GetStringRightAlignXOffset(fontId, str, totalWidth) GetStringWidthDifference(fontId, str, totalWidth, 0)
// Emerald converts Japanese record-mixing names; no record mixing here: a plain copy
#define TVShowConvertInternationalString(dest, src, language) StringCopy(dest, src)

#endif // GUARD_INTERNATIONAL_STRING_UTIL_H
