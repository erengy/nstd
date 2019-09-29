#pragma once

#include <iostream>
#include <utility>

namespace nstd {

template <typename... Ts>
void print(Ts&&... args) {
  (std::cout << ... << std::forward<Ts>(args));
}

template <typename... Ts>
void println(Ts&&... args) {
  print(args..., '\n');
}

}  // namespace nstd
