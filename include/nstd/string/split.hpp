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

#include "constants.hpp"

namespace nstd {

namespace detail {

using string_predicate_t = std::function<bool(const char)>;

}  // namespace detail

std::vector<std::string> split(std::string_view str) {
  std::vector<std::string> output;

  while (true) {
    size_t pos = str.find_first_of(string_constants::whitespace);
    if (pos == std::string_view::npos) {
      if (!str.empty()) {
        output.push_back(std::string{str});
      }
      break;
    }
    if (pos > 0) {
      output.push_back(std::string{str.substr(0, pos)});
      str.remove_prefix(pos);
    }
    pos = str.find_first_not_of(string_constants::whitespace);
    str.remove_prefix(std::min(pos, str.size()));
  }

  return output;
}

std::vector<std::string> split(std::string_view str,
                               const std::string_view delimiter) {
  std::vector<std::string> output;

  while (true) {
    const size_t pos = str.find(delimiter);
    if (pos == std::string_view::npos) {
      output.push_back(std::string{str});
      break;
    }
    output.push_back(std::string{str.substr(0, pos)});
    str.remove_prefix(pos + delimiter.size());
  }

  return output;
}

std::vector<std::string> split_if(std::string_view str,
    const detail::string_predicate_t predicate) {
  std::vector<std::string> output;

  while (true) {
    const auto it = std::find_if(str.begin(), str.end(), predicate);
    if (it == str.end()) {
      output.push_back(std::string{str});
      break;
    }
    const auto pos = std::distance(str.begin(), it);
    output.push_back(std::string{str.substr(0, pos)});
    str.remove_prefix(pos + 1);
  }

  return output;
}

}  // namespace nstd
