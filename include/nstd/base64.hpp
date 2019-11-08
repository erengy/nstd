#pragma once

#include <algorithm>
#include <array>
#include <string>
#include <string_view>

namespace nstd::base64 {

namespace detail {

constexpr std::array<char, 64> alphabet{
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

constexpr std::array<char, 256> alphabet_index{
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
  -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
  -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

constexpr char padding = '=';

}  // namespace detail

inline std::string decode(const std::string_view input) {
  using namespace detail;

  std::string output((input.size() / 4) * 3, '\0');

  const size_t size = input.find_last_not_of(padding) + 1;
  size_t output_size = 0;

  for (size_t i = 0; i < size; i += 4) {
    const bool b2 = i + 2 < size;
    const bool b3 = i + 3 < size;

    uint32_t s  = static_cast<uint32_t>(alphabet_index[input[i    ]]) << 18;
             s |= static_cast<uint32_t>(alphabet_index[input[i + 1]]) << 12;
    if (b2)  s |= static_cast<uint32_t>(alphabet_index[input[i + 2]]) <<  6;
    if (b3)  s |= static_cast<uint32_t>(alphabet_index[input[i + 3]]);

            output[output_size++] = static_cast<char>((s >> 16) & 0xFF);
    if (b2) output[output_size++] = static_cast<char>((s >>  8) & 0xFF);
    if (b3) output[output_size++] = static_cast<char>( s        & 0xFF);
  }

  if (output.size() > output_size) {
    output.resize(output_size);
  }

  return output;
}

inline std::string encode(const std::string_view input) {
  using namespace detail;

  std::string output(((input.size() + 2) / 3) * 4, '\0');

  for (size_t i = 0, o = 0; i < input.size(); i += 3) {
    const bool b1 = i + 1 < input.size();
    const bool b2 = i + 2 < input.size();

    uint32_t s  = static_cast<uint32_t>(input[i    ]) << 16;
    if (b1)  s |= static_cast<uint32_t>(input[i + 1]) <<  8;
    if (b2)  s |= static_cast<uint32_t>(input[i + 2]);

    output[o++] =      alphabet[(s >> 18) & 0x3F];
    output[o++] =      alphabet[(s >> 12) & 0x3F];
    output[o++] = b1 ? alphabet[(s >>  6) & 0x3F] : padding;
    output[o++] = b2 ? alphabet[(s      ) & 0x3F] : padding;
  }

  return output;
}

inline bool validate(const std::string_view input) {
  using namespace detail;

  if (input.empty() || input.size() % 4 != 0) {
    return false;
  }

  const size_t size = input.find_last_not_of(padding);

  if (size == std::string_view::npos || size <= input.size() - 4) {
    return false;
  }

  return std::all_of(input.cbegin(), input.cbegin() + size + 1,
      [](const char c) {
        return ('A' <= c && c <= 'Z') ||
               ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9') ||
               c == '+' || c == '/';
      });
}

}  // namespace nstd::base64
