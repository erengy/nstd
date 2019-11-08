#pragma once

#include <limits>
#include <string>
#include <string_view>

namespace nstd {

namespace detail {

inline std::string replace(std::string str, const std::string_view old,
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

[[nodiscard]] inline std::string replace(std::string str,
                                         const std::string_view old,
                                         const std::string_view replacement) {
  constexpr auto count = std::numeric_limits<int>::max();
  return detail::replace(str, old, replacement, count);
}

[[nodiscard]] inline std::string replace(std::string str,
                                         const std::string_view old,
                                         const std::string_view replacement,
                                         int count) {
  return detail::replace(str, old, replacement, count);
}

}  // namespace nstd
