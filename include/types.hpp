#ifndef TYPES_HPP
#define TYPES_HPP

#include <map>
#include <functional>

using i8_t  = char;
using u8_t  = unsigned char;
using i16_t = short;
using u16_t = unsigned short;
using i32_t = int;
using u32_t = unsigned int;
using i64_t = long long;
using u64_t = unsigned long long;
using Function_Table = std::map<std::string, std::function<u64_t(std::string)>>;

#endif
