#ifndef __STRINGCONVERTER_H_
#define __STRINGCONVERTER_H_
#include <string>

std::string utf16_to_utf8(const std::u16string& utf16_str);
std::u16string utf8_to_utf16(const std::string& utf8_str);

#endif//__STRINGCONVERTER_H_