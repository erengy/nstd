#pragma once

#include <array>
#include <charconv>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>

namespace nstd {

namespace detail {

template <typename T>
T from_chars(const std::string_view str) {
  T value{0};
  std::from_chars(str.data(), str.data() + str.size(), value, 10);
  return value;
}

template <typename T>
std::string to_chars(const T value) {
  std::array<char, std::numeric_limits<T>::digits10 + 2> str;
  const auto [ptr, errc] = std::to_chars(
      str.data(), str.data() + str.size(), value);
  return errc == std::errc() ?
      std::string(str.data(), ptr - str.data()) : std::string{};
}

}  // namespace detail

inline int to_int(const std::string_view str) { return detail::from_chars<int>(str); }
inline int8_t to_int8(const std::string_view str) { return detail::from_chars<int8_t>(str); }
inline int16_t to_int16(const std::string_view str) { return detail::from_chars<int16_t>(str); }
inline int32_t to_int32(const std::string_view str) { return detail::from_chars<int32_t>(str); }
inline int64_t to_int64(const std::string_view str) { return detail::from_chars<int64_t>(str); }
inline uint8_t to_uint8(const std::string_view str) { return detail::from_chars<uint8_t>(str); }
inline unsigned int to_uint(const std::string_view str) { return detail::from_chars<unsigned int>(str); }
inline uint16_t to_uint16(const std::string_view str) { return detail::from_chars<uint16_t>(str); }
inline uint32_t to_uint32(const std::string_view str) { return detail::from_chars<uint32_t>(str); }
inline uint64_t to_uint64(const std::string_view str) { return detail::from_chars<uint64_t>(str); }

inline std::string to_string(const int8_t value) { return detail::to_chars<int8_t>(value); }
inline std::string to_string(const int16_t value) { return detail::to_chars<int16_t>(value); }
inline std::string to_string(const int32_t value) { return detail::to_chars<int32_t>(value); }
inline std::string to_string(const int64_t value) { return detail::to_chars<int64_t>(value); }
inline std::string to_string(const uint8_t value) { return detail::to_chars<uint8_t>(value); }
inline std::string to_string(const uint16_t value) { return detail::to_chars<uint16_t>(value); }
inline std::string to_string(const uint32_t value) { return detail::to_chars<uint32_t>(value); }
inline std::string to_string(const uint64_t value) { return detail::to_chars<uint64_t>(value); }

}  // namespace nstd
