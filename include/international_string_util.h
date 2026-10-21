#ifndef GUARD_INTERNATIONAL_STRING_UTIL_H
#define GUARD_INTERNATIONAL_STRING_UTIL_H

// RFVF+: the two bits of Emerald's international_string_util that its Battle Frontier code uses
#include "text.h"
#include "string_util.h"

#define GetStringRightAlignXOffset(fontId, str, totalWidth) ((totalWidth) - GetStringWidth(fontId, str, 0))
// Emerald converts Japanese record-mixing names; no record mixing here: a plain copy
#define TVShowConvertInternationalString(dest, src, language) StringCopy(dest, src)

#endif // GUARD_INTERNATIONAL_STRING_UTIL_H
