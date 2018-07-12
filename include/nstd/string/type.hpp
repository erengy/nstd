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

#include <algorithm>
#include <string>
#include <string_view>

#include "../type.hpp"

namespace nstd {

constexpr bool isalnum_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isalnum);
}

constexpr bool isalpha_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isalpha);
}

constexpr bool islower_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::islower);
}

constexpr bool isupper_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isupper);
}

constexpr bool isdigit_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isdigit);
}

constexpr bool isxdigit_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isxdigit);
}

constexpr bool iscntrl_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::iscntrl);
}

constexpr bool isgraph_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isgraph);
}

constexpr bool isspace_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isspace);
}

constexpr bool isblank_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isblank);
}

constexpr bool isprint_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isprint);
}

constexpr bool ispunct_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::ispunct);
}

[[nodiscard]] std::string tolower_string(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), nstd::tolower);
  return str;
}

[[nodiscard]] std::string toupper_string(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), nstd::toupper);
  return str;
}

}  // namespace nstd
