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
#include <string_view>

#include "constants.hpp"

namespace nstd {

namespace detail {

enum class Strip {
  Both,
  Left,
  Right,
};

using string_predicate_t = std::function<bool(const char)>;

std::string_view strip(std::string_view str, const std::string_view chars,
                       const Strip strip_position) {
  if (strip_position == Strip::Left || strip_position == Strip::Both) {
    const auto pos = str.find_first_not_of(chars);
    if (pos != std::string_view::npos && pos > 0) {
      str.remove_prefix(pos);
    }
  }
  if (strip_position == Strip::Right || strip_position == Strip::Both) {
    const auto pos = str.find_last_not_of(chars);
    if (pos != std::string_view::npos) {
      str.remove_suffix(str.size() - pos - 1);
    }
  }
  return str;
}

std::string_view strip_if(std::string_view str,
                          const detail::string_predicate_t predicate,
                          const Strip strip_position) {
  if (strip_position == Strip::Left || strip_position == Strip::Both) {
    const auto it = std::find_if_not(str.begin(), str.end(), predicate);
    if (it != str.end() && it != str.begin()) {
      str.remove_prefix(std::distance(str.begin(), it));
    }
  }
  if (strip_position == Strip::Right || strip_position == Strip::Both) {
    const auto it = std::find_if_not(str.rbegin(), str.rend(), predicate);
    if (it != str.rend()) {
      str.remove_suffix(std::distance(str.rbegin(), it));
    }
  }
  return str;
}

}  // namespace detail

std::string_view strip(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Both);
}

std::string_view strip(const std::string_view str,
                       const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Both);
}

std::string_view strip_if(const std::string_view str,
                          const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Both);
}

std::string_view strip_left(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Left);
}

std::string_view strip_left(const std::string_view str,
                            const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Left);
}

std::string_view strip_left_if(const std::string_view str,
                               const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Left);
}

std::string_view strip_right(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Right);
}

std::string_view strip_right(const std::string_view str,
                             const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Right);
}

std::string_view strip_right_if(const std::string_view str,
                                const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Right);
}

}  // namespace nstd
