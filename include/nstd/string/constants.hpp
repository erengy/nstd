#pragma once

#include <string>

namespace nstd::string_constants {

inline const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
inline const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline const std::string letters = lowercase + uppercase;

inline const std::string digits = "0123456789";
inline const std::string hexdigits = digits + "abcdefABCDEF";
inline const std::string octdigits = "01234567";

inline const std::string punctuation = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)";
inline const std::string whitespace = " \t\n\r\v\f";
inline const std::string printable =
    digits + letters + punctuation + whitespace;

}  // namespace nstd::string_constants
