#include <cassert>
#include <iostream>
#include <string>

#include "../include/nstd/filesystem.hpp"

namespace {

void test_read() {
  std::string hello;
  assert(nstd::read_file("data/hello.txt", hello));
  assert(hello == "Hello world!");
}

}  // namespace

int main() {
  test_read();
  return 0;
}
