#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

#include "../include/nstd/string.hpp"
#include "../include/nstd/type.hpp"

namespace {

void test_between() {
  assert(nstd::between("abcdef", "ab", "ef") == "cd");
}

void test_contains() {
  assert(nstd::contains("abcd", "bc"));
  assert(nstd::contains("abcd", 'b'));
}

template <typename T>
void test_conversion(std::function<T(std::string_view)> f) {
  const std::vector<T> values{
      std::numeric_limits<T>::min(),
      static_cast<T>(-1),
      static_cast<T>(0),
      static_cast<T>(1),
      std::numeric_limits<T>::max(),
    };
  for (const auto value : values) {
    assert(f(nstd::to_string(value)) == value);
  }
}
void test_conversion() {
  test_conversion<int>(nstd::to_int);
  test_conversion<int8_t>(nstd::to_int8);
  test_conversion<int16_t>(nstd::to_int16);
  test_conversion<int32_t>(nstd::to_int32);
  test_conversion<int64_t>(nstd::to_int64);
  test_conversion<unsigned int>(nstd::to_uint);
  test_conversion<uint8_t>(nstd::to_uint8);
  test_conversion<uint16_t>(nstd::to_uint16);
  test_conversion<uint32_t>(nstd::to_uint32);
  test_conversion<uint64_t>(nstd::to_uint64);
}

void test_join() {
  assert(nstd::join({"1", "2", "3"}, {}) == "123");
  assert(nstd::join({"1", "2", "3"}, "-") == "1-2-3");
}

void test_partition() {
  const auto p = nstd::partition("abcdef", "cd");
  assert(p.size() == 3);
  assert(p[0] == "ab");
  assert(p[1] == "cd");
  assert(p[2] == "ef");
}

void test_remove_affix() {
  assert(nstd::remove_prefix("abcd", "ab") == "cd");
  assert(nstd::remove_suffix("abcd", "cd") == "ab");
}

void test_repeat() {
  assert(nstd::repeat("abc", 3) == "abcabcabc");
}

void test_replace() {
  assert(nstd::replace("abcbcbcd", "bc", "ef") == "aefefefd");
  assert(nstd::replace("abcbcbcd", "bc", "ef",  0) == "abcbcbcd");
  assert(nstd::replace("abcbcbcd", "bc", "ef",  1) == "aefbcbcd");
  assert(nstd::replace("abcbcbcd", "bc", "ef",  2) == "aefefbcd");
  assert(nstd::replace("abcbcbcd", "bc", "ef",  3) == "aefefefd");
  assert(nstd::replace("abcbcbcd", "bc", "ef",  4) == "aefefefd");
  assert(nstd::replace("abcbcbcd", "bc", "ef", -1) == "abcbcbcd");
}

void test_slice() {
  assert(nstd::slice("abc",  0,  0) == "");
  assert(nstd::slice("abc",  0,  1) == "a");
  assert(nstd::slice("abc",  0,  2) == "ab");
  assert(nstd::slice("abc",  0,  3) == "abc");
  assert(nstd::slice("abc", -1,  3) == "c");
  assert(nstd::slice("abc", -2,  3) == "bc");
  assert(nstd::slice("abc", -3,  3) == "abc");
  assert(nstd::slice("abc", -4,  3) == "abc");
  assert(nstd::slice("abc",  0, -1) == "ab");
  assert(nstd::slice("abc",  0, -2) == "a");
  assert(nstd::slice("abc",  0, -3) == "");
  assert(nstd::slice("abc",  0, -4) == "");
}

void test_split() {
  using sv = std::vector<std::string>;
  assert(nstd::split("   1   2   3   ") == sv({"1", "2", "3"}));
  assert(nstd::split("1-2-3", "-") == sv({"1", "2", "3"}));
  assert(nstd::split_if("1-2-3", nstd::ispunct) == sv({"1", "2", "3"}));
  assert(nstd::split("1--2-", "-") == sv({"1", "", "2", ""}));
  assert(nstd::split_if("1--2-", nstd::ispunct) == sv({"1", "", "2", ""}));
  assert(nstd::split("1<>2<>3", "<>") == sv({"1", "2", "3"}));
}

void test_start_end() {
  assert(nstd::starts_with("abc", "ab"));
  assert(nstd::starts_with("abc", 'a'));
  assert(nstd::ends_with("abc", "bc"));
  assert(nstd::ends_with("abc", 'c'));
}

void test_string_types() {
  using namespace nstd::string_constants;

  assert(!nstd::isalnum_string(""));
  assert(!nstd::isalpha_string(""));
  assert(!nstd::islower_string(""));
  assert(!nstd::isupper_string(""));
  assert(!nstd::isdigit_string(""));
  assert(!nstd::isxdigit_string(""));
  assert(!nstd::iscntrl_string(""));
  assert(!nstd::isgraph_string(""));
  assert(!nstd::isspace_string(""));
  assert(!nstd::isblank_string(""));
  assert(!nstd::isprint_string(""));
  assert(!nstd::ispunct_string(""));

  assert(nstd::isalnum_string(digits + letters));
  assert(nstd::isalpha_string(letters));
  assert(nstd::islower_string(lowercase));
  assert(nstd::isupper_string(uppercase));
  assert(nstd::isdigit_string(digits));
  assert(nstd::isxdigit_string(hexdigits));
  assert(nstd::isgraph_string(digits + letters + punctuation));
  assert(nstd::isspace_string(whitespace));
  assert(nstd::isblank_string(" \t"));
  assert(nstd::isprint_string(digits + letters + punctuation + " "));
  assert(nstd::ispunct_string(punctuation));

  std::string control_chars;
  for (int c = 0; c <= std::numeric_limits<char>::max(); ++c) {
    if (!nstd::isprint(c)) {
      control_chars.push_back(c);
    }
  }
  assert(nstd::iscntrl_string(control_chars));
}

void test_strip() {
  using namespace nstd::string_constants;
  const auto str = "  abc\r\n";
  assert(nstd::strip(str) == "abc");
  assert(nstd::strip(str, whitespace) == "abc");
  assert(nstd::strip_if(str, nstd::isspace) == "abc");
  assert(nstd::strip_left(str) == "abc\r\n");
  assert(nstd::strip_left(str, whitespace) == "abc\r\n");
  assert(nstd::strip_left_if(str, nstd::isspace) == "abc\r\n");
  assert(nstd::strip_right(str) == "  abc");
  assert(nstd::strip_right(str, whitespace) == "  abc");
  assert(nstd::strip_right_if(str, nstd::isspace) == "  abc");
}

void test_transform() {
  using namespace nstd::string_constants;
  assert(nstd::transform(uppercase, nstd::tolower) == lowercase);
  assert(nstd::transform(lowercase, nstd::toupper) == uppercase);
  assert(nstd::tolower_string(uppercase) == lowercase);
  assert(nstd::toupper_string(lowercase) == uppercase);
}

}  // namespace

int main() {
  test_between();
  test_contains();
  test_conversion();
  test_join();
  test_partition();
  test_remove_affix();
  test_repeat();
  test_replace();
  test_slice();
  test_split();
  test_start_end();
  test_string_types();
  test_strip();
  test_transform();
  return 0;
}
