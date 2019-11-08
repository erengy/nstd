#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../include/nstd/algorithm.hpp"

namespace {

void test_contains() {
  const std::map<int, std::string> map{
    {0, "zero"}, {1, "one"}, {2, "two"},
  };
  assert(nstd::contains(map, 0));
  assert(nstd::contains(map, 1));
  assert(nstd::contains(map, 2));
  assert(!nstd::contains(map, 3));

  const std::set<int> set{0, 1, 2};
  assert(nstd::contains(set, 0));
  assert(nstd::contains(set, 1));
  assert(nstd::contains(set, 2));
  assert(!nstd::contains(set, 3));

  const std::vector<int> vector{0, 1, 2};
  assert(nstd::contains(vector, 0));
  assert(nstd::contains(vector, 1));
  assert(nstd::contains(vector, 2));
  assert(!nstd::contains(vector, 3));
}

}  // namespace

int main() {
  test_contains();
  return 0;
}
