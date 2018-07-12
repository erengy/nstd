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
#include <functional>
#include <string>
#include <string_view>
#include <vector>

#include "string/constants.hpp"
#include "string/predicates.hpp"
#include "string/replace.hpp"
#include "string/split.hpp"
#include "string/strip.hpp"
#include "string/type.hpp"

namespace nstd {

std::string_view between(const std::string_view str,
                         const std::string_view before,
                         const std::string_view after) {
  auto begin = str.find(before);
  if (begin != std::string_view::npos) {
    begin += before.size();
    const auto end = str.find(after, begin);
    if (end != std::string_view::npos) {
      return str.substr(begin, end - begin);
    }
  }
  return {};
}

std::string join(const std::vector<std::string>& container,
                 const std::string_view delimiter) {
  std::string output;
  for (auto it = container.begin(); it != container.end(); ++it) {
    if (!delimiter.empty() && it != container.begin()) {
      output += delimiter;
    }
    output += *it;
  }
  return output;
}

std::vector<std::string> partition(const std::string_view str,
                                   const std::string_view delimiter) {
  const auto pos = str.find(delimiter);
  if (pos != std::string_view::npos) {
    return {
      std::string{str.substr(0, pos)},
      std::string{delimiter},
      std::string{str.substr(pos + delimiter.size())},
    };
  }
  return {};
}

[[nodiscard]] constexpr std::string_view remove_prefix(
    std::string_view str, const std::string_view prefix) {
  if (starts_with(str, prefix)) {
    str.remove_prefix(prefix.size());
  }
  return str;
}

[[nodiscard]] constexpr std::string_view remove_suffix(
    std::string_view str, const std::string_view suffix) {
  if (ends_with(str, suffix)) {
    str.remove_suffix(suffix.size());
  }
  return str;
}

std::string repeat(const std::string_view pattern, const size_t n) {
  std::string output(n * pattern.size(), '\0');
  for (size_t pos = 0; pos < output.size(); pos += n) {
    output.replace(pos, n, pattern);
  }
  return output;
}

std::string_view slice(const std::string_view str, int start, int end) {
  const auto len = static_cast<int>(str.size());
  if (start < 0) {
    start = std::max(start + len, 0);
  }
  if (end < 0) {
    end = std::max(end + len, 0);
  } else if (end > len) {
    end = len;
  }
  return str.substr(start, end - start);
}

std::string transform(std::string str,
                      const std::function<char(const char)> predicate) {
  std::transform(str.begin(), str.end(), str.begin(), predicate);
  return str;
}

}  // namespace nstd
