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

inline std::vector<std::string> split(std::string_view str) {
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

inline std::vector<std::string> split(std::string_view str,
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

inline std::vector<std::string> split_if(
    std::string_view str, const detail::string_predicate_t predicate) {
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
