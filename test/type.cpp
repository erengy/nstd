#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>

#include "../include/nstd/type.hpp"

namespace {

void test_chars() {
  for (int c = 0; c <= std::numeric_limits<char>::max(); ++c) {
    assert(nstd::isalnum(c) == (std::isalnum(c) != 0));
    assert(nstd::isalpha(c) == (std::isalpha(c) != 0));
    assert(nstd::islower(c) == (std::islower(c) != 0));
    assert(nstd::isupper(c) == (std::isupper(c) != 0));
    assert(nstd::isdigit(c) == (std::isdigit(c) != 0));
    assert(nstd::isxdigit(c) == (std::isxdigit(c) != 0));
    assert(nstd::iscntrl(c) == (std::iscntrl(c) != 0));
    assert(nstd::isgraph(c) == (std::isgraph(c) != 0));
    assert(nstd::isspace(c) == (std::isspace(c) != 0));
    assert(nstd::isblank(c) == (std::isblank(c) != 0));
    assert(nstd::isprint(c) == (std::isprint(c) != 0));
    assert(nstd::ispunct(c) == (std::ispunct(c) != 0));
    assert(nstd::tolower(c) == std::tolower(c));
    assert(nstd::toupper(c) == std::toupper(c));
  }
}

}  // namespace

int main() {
  test_chars();
  return 0;
}
