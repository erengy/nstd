#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>

#include "string/constants.hpp"
#include "string/conversion.hpp"
#include "string/predicates.hpp"
#include "string/replace.hpp"
#include "string/split.hpp"
#include "string/strip.hpp"
#include "string/type.hpp"

namespace nstd {

inline std::string_view between(const std::string_view str,
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

inline std::string join(const std::vector<std::string>& container,
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

inline std::vector<std::string> partition(const std::string_view str,
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

inline std::string repeat(const std::string_view pattern, const size_t n) {
  std::string output(n * pattern.size(), '\0');
  for (size_t pos = 0; pos < output.size(); pos += n) {
    output.replace(pos, n, pattern);
  }
  return output;
}

inline std::string_view slice(const std::string_view str, int start, int end) {
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

inline std::string transform(std::string str,
                             const std::function<char(const char)> predicate) {
  std::transform(str.begin(), str.end(), str.begin(), predicate);
  return str;
}

}  // namespace nstd
