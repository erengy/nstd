/*
MIT License

Copyright (c) 2018 Eren Okka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <fstream>
#include <string>
#include <string_view>

namespace nstd {

namespace detail {

bool ifstream(const std::string_view path,
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

bool ofstream(const std::string_view path,
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

bool read_file(const std::string_view path, std::string& output) {
  constexpr auto openmode = std::ios::in | std::ios::binary;
  return detail::ifstream(path, openmode, output);
}

bool append_to_file(const std::string_view path, const std::string_view input) {
  constexpr auto openmode = std::ios::out | std::ios::binary | std::ios::app;
  return detail::ofstream(path, openmode, input);
}

bool write_to_file(const std::string_view path, const std::string_view input) {
  constexpr auto openmode = std::ios::out | std::ios::binary;
  return detail::ofstream(path, openmode, input);
}

}  // namespace nstd
