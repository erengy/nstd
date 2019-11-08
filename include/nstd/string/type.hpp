#pragma once

#include <algorithm>
#include <string>
#include <string_view>

#include "../type.hpp"

namespace nstd {

constexpr bool isalnum_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isalnum);
}

constexpr bool isalpha_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isalpha);
}

constexpr bool islower_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::islower);
}

constexpr bool isupper_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isupper);
}

constexpr bool isdigit_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isdigit);
}

constexpr bool isxdigit_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isxdigit);
}

constexpr bool iscntrl_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::iscntrl);
}

constexpr bool isgraph_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isgraph);
}

constexpr bool isspace_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isspace);
}

constexpr bool isblank_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isblank);
}

constexpr bool isprint_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::isprint);
}

constexpr bool ispunct_string(const std::string_view str) {
  return !str.empty() && std::all_of(str.begin(), str.end(), nstd::ispunct);
}

[[nodiscard]] inline std::string tolower_string(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), nstd::tolower);
  return str;
}

[[nodiscard]] inline std::string toupper_string(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), nstd::toupper);
  return str;
}

}  // namespace nstd
