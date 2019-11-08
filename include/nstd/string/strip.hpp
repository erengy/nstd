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

inline std::string_view strip(std::string_view str,
                              const std::string_view chars,
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

inline std::string_view strip_if(std::string_view str,
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

inline std::string_view strip(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Both);
}

inline std::string_view strip(const std::string_view str,
                              const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Both);
}

inline std::string_view strip_if(const std::string_view str,
                                 const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Both);
}

inline std::string_view strip_left(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Left);
}

inline std::string_view strip_left(const std::string_view str,
                                   const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Left);
}

inline std::string_view strip_left_if(
    const std::string_view str, const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Left);
}

inline std::string_view strip_right(const std::string_view str) {
  return detail::strip(str, string_constants::whitespace, detail::Strip::Right);
}

inline std::string_view strip_right(const std::string_view str,
                                    const std::string_view chars) {
  return detail::strip(str, chars, detail::Strip::Right);
}

inline std::string_view strip_right_if(
    const std::string_view str, const detail::string_predicate_t predicate) {
  return detail::strip_if(str, predicate, detail::Strip::Right);
}

}  // namespace nstd
