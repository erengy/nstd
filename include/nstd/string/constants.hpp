#pragma once

#include <string>

namespace nstd::string_constants {

const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string letters = lowercase + uppercase;

const std::string digits = "0123456789";
const std::string hexdigits = digits + "abcdefABCDEF";
const std::string octdigits = "01234567";

const std::string punctuation = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)";
const std::string whitespace = " \t\n\r\v\f";
const std::string printable = digits + letters + punctuation + whitespace;

}  // namespace nstd::string_constants
