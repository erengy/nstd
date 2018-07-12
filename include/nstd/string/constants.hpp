/*
MIT License

Copyright (c) 2018 Eren Okka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
