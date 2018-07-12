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

#include <limits>
#include <string>
#include <string_view>

namespace nstd {

namespace detail {

std::string replace(std::string str, const std::string_view old,
                    const std::string_view replacement, int count) {
  if (count < 1 || old.empty() || old.size() > str.size() ||
      old == replacement) {
    return str;
  }
  size_t offset = 0;
  while (count) {
    const size_t pos = str.find(old, offset);
    if (pos == std::string::npos) {
      break;
    }
    str.replace(pos, old.size(), replacement);
    offset = pos + replacement.size();
    --count;
  }
  return str;
}

}  // namespace detail

[[nodiscard]] std::string replace(std::string str, const std::string_view old,
                                  const std::string_view replacement) {
  constexpr auto count = std::numeric_limits<int>::max();
  return detail::replace(str, old, replacement, count);
}

[[nodiscard]] std::string replace(std::string str, const std::string_view old,
                                  const std::string_view replacement,
                                  int count) {
  return detail::replace(str, old, replacement, count);
}

}  // namespace nstd
