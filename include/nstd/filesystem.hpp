#pragma once

#include <fstream>
#include <string>
#include <string_view>

namespace nstd {

namespace detail {

inline bool ifstream(const std::string_view path,
                     const std::ios_base::openmode openmode,
                     std::string& output) {
  std::ifstream file{path.data(), openmode | std::ios::ate};

  if (!file) {
    return false;
  }

  output.resize(static_cast<size_t>(file.tellg()));
  file.seekg(0, std::ios::beg);
  file.read(output.data(), output.size());

  return file.good();
}

inline bool ofstream(const std::string_view path,
                     const std::ios_base::openmode openmode,
                     const std::string_view input) {
  std::ofstream file{path.data(), openmode};

  if (!file) {
    return false;
  }

  file.write(input.data(), input.size());

  return file.good();
}

}  // namespace detail

inline bool read_file(const std::string_view path, std::string& output) {
  constexpr auto openmode = std::ios::in | std::ios::binary;
  return detail::ifstream(path, openmode, output);
}

inline bool append_to_file(const std::string_view path,
                           const std::string_view input) {
  constexpr auto openmode = std::ios::out | std::ios::binary | std::ios::app;
  return detail::ofstream(path, openmode, input);
}

inline bool write_to_file(const std::string_view path,
                          const std::string_view input) {
  constexpr auto openmode = std::ios::out | std::ios::binary;
  return detail::ofstream(path, openmode, input);
}

}  // namespace nstd
