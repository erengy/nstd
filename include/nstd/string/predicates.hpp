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

#include <string_view>

namespace nstd {

constexpr bool contains(const std::string_view str,
                        const std::string_view pattern) {
  return str.find(pattern) != std::string_view::npos;
}

constexpr bool contains(const std::string_view str, const char c) {
  return str.find(c) != std::string_view::npos;
}

constexpr bool ends_with(const std::string_view str,
                         const std::string_view suffix) {
  return str.size() >= suffix.size() &&
         str.compare(str.size() - suffix.size(),
                     std::string_view::npos, suffix) == 0;
}

constexpr bool ends_with(const std::string_view str, const char c) {
  return !str.empty() && str.back() == c;
}

constexpr bool starts_with(const std::string_view str,
                           const std::string_view prefix) {
  return str.size() >= prefix.size() &&
         str.compare(0, prefix.size(), prefix) == 0;
}

constexpr bool starts_with(const std::string_view str, const char c) {
  return !str.empty() && str.front() == c;
}

}  // namespace nstd
