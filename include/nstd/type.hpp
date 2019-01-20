#pragma once

namespace nstd {

constexpr bool isalnum(const char c) {
  return ('0' <= c && c <= '9') ||
         ('A' <= c && c <= 'Z') ||
         ('a' <= c && c <= 'z');
}

constexpr bool isalpha(const char c) {
  return ('A' <= c && c <= 'Z') ||
         ('a' <= c && c <= 'z');
}

constexpr bool islower(const char c) {
  return 'a' <= c && c <= 'z';
}

constexpr bool isupper(const char c) {
  return 'A' <= c && c <= 'Z';
}

constexpr bool isdigit(const char c) {
  return '0' <= c && c <= '9';
}

constexpr bool isxdigit(const char c) {
  return ('0' <= c && c <= '9') ||
         ('A' <= c && c <= 'F') ||
         ('a' <= c && c <= 'f');
}

constexpr bool iscntrl(const char c) {
  return (0x00 <= c && c <= 0x1F) || c == 0x7F;
}

constexpr bool isgraph(const char c) {
  return ( '0' <= c && c <=  '9') ||
         ( 'A' <= c && c <=  'Z') ||
         ( 'a' <= c && c <=  'z') ||
         (0x21 <= c && c <= 0x2F) ||
         (0x3A <= c && c <= 0x40) ||
         (0x5B <= c && c <= 0x60) ||
         (0x7B <= c && c <= 0x7E);
}

constexpr bool isspace(const char c) {
  return c ==  ' ' ||  // space
         c == '\f' ||  // form feed
         c == '\n' ||  // line feed
         c == '\r' ||  // carriage return
         c == '\t' ||  // horizontal tab
         c == '\v';    // vertical tab
}

constexpr bool isblank(const char c) {
  return c == ' ' || c == '\t';
}

constexpr bool isprint(const char c) {
  return ( '0' <= c && c <=  '9') ||
         ( 'A' <= c && c <=  'Z') ||
         ( 'a' <= c && c <=  'z') ||
         (0x21 <= c && c <= 0x2F) ||
         (0x3A <= c && c <= 0x40) ||
         (0x5B <= c && c <= 0x60) ||
         (0x7B <= c && c <= 0x7E) ||
                       c ==  ' ';
}

constexpr bool ispunct(const char c) {
  return (0x21 <= c && c <= 0x2F) ||  // !"#$%&'()*+,-./
         (0x3A <= c && c <= 0x40) ||  // :;<=>?@
         (0x5B <= c && c <= 0x60) ||  // [\]^_`
         (0x7B <= c && c <= 0x7E);    // {|}~
}

constexpr char tolower(const char c) {
  return ('A' <= c && c <= 'Z') ? c + ('a' - 'A') : c;
}

constexpr char toupper(const char c) {
  return ('a' <= c && c <= 'z') ? c - ('a' - 'A') : c;
}

}  // namespace nstd
