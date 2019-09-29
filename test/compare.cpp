#include <cassert>
#include <iostream>

#include "../include/nstd/compare.hpp"

namespace {

void test_compare_int() {
  class Integer : public nstd::Comparable<Integer> {
  public:
    constexpr Integer(int value) : value_{value} {}
    constexpr int value() const { return value_; }
    int compare(const Integer& rhs) const override {
      return nstd::compare(value(), rhs.value());
    }
  private:
    int value_ = 0;
  };

  assert(Integer{0} == Integer{0});
  assert(Integer{0} != Integer{1});
  assert(Integer{0} <  Integer{1});
  assert(Integer{1} >  Integer{0});
  assert(Integer{0} <= Integer{1});
  assert(Integer{1} <= Integer{1});
  assert(Integer{1} >= Integer{0});
  assert(Integer{1} >= Integer{1});
}

}  // namespace

int main() {
  test_compare_int();
  return 0;
}
