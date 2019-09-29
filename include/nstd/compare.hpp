#pragma once

namespace nstd {

template <typename T>
class Comparable {
public:
  virtual int compare(const T& rhs) const = 0;

  bool operator==(const T& rhs) const { return compare(rhs) == 0; }
  bool operator!=(const T& rhs) const { return compare(rhs) != 0; }
  bool operator< (const T& rhs) const { return compare(rhs) <  0; }
  bool operator> (const T& rhs) const { return compare(rhs) >  0; }
  bool operator<=(const T& rhs) const { return compare(rhs) <= 0; }
  bool operator>=(const T& rhs) const { return compare(rhs) >= 0; }
};

template <typename T>
int compare(const T& lhs, const T& rhs) {
  return (lhs != rhs) ? (lhs < rhs ? -1 : 1) : 0;
}

}  // namespace nstd
