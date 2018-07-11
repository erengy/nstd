#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

#include "../include/nstd/base64.hpp"

namespace {

void test_ascii() {
  std::string ascii_chars;
  for (int c = 0; c <= std::numeric_limits<char>::max(); ++c) {
    ascii_chars.push_back(c);
  }

  const auto encoded = nstd::base64::encode(ascii_chars);
  const auto decoded = nstd::base64::decode(encoded);

  for (size_t i = 0; i < ascii_chars.size(); ++i) {
    assert(decoded[i] == ascii_chars[i]);
  }
}

void test_rfc4648() {
  // https://tools.ietf.org/html/rfc4648#section-10
  const std::vector<std::pair<std::string_view, std::string_view>> pairs{
    {"", ""},
    {"f", "Zg=="},
    {"fo", "Zm8="},
    {"foo", "Zm9v"},
    {"foob", "Zm9vYg=="},
    {"fooba", "Zm9vYmE="},
    {"foobar", "Zm9vYmFy"},
  };

  for (const auto& pair : pairs) {
    assert(nstd::base64::encode(pair.first) == pair.second);
    assert(nstd::base64::validate(pair.second) || pair.second.empty());
    assert(nstd::base64::decode(pair.second) == pair.first);
  }
}

}  // namespace

int main() {
  test_ascii();
  test_rfc4648();
  return 0;
}
