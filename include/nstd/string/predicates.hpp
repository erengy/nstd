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
