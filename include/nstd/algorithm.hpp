#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <vector>

namespace nstd {

template <typename Key, typename T>
bool contains(const std::map<Key, T>& container, const Key& key) {
  return container.find(key) != container.end();
}

template <typename Key>
bool contains(const std::set<Key>& container, const Key& key) {
  return container.find(key) != container.end();
}

template <typename T>
bool contains(const std::vector<T>& container, const T& value) {
  return std::find(container.begin(), container.end(),
                   value) != container.end();
}

}  // namespace nstd
