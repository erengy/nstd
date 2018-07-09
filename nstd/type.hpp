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

namespace nstd {

bool isalnum(char c) {
  return ('0' <= c && c <= '9') ||
         ('A' <= c && c <= 'Z') ||
         ('a' <= c && c <= 'z');
}

bool isalpha(char c) {
  return ('A' <= c && c <= 'Z') ||
         ('a' <= c && c <= 'z');
}

bool islower(char c) {
  return 'a' <= c && c <= 'z';
}

bool isupper(char c) {
  return 'A' <= c && c <= 'Z';
}

bool isdigit(char c) {
  return '0' <= c && c <= '9';
}

bool isxdigit(char c) {
  return ('0' <= c && c <= '9') ||
         ('A' <= c && c <= 'F') ||
         ('a' <= c && c <= 'f');
}

bool iscntrl(char c) {
  return (0x00 <= c && c <= 0x1F) || c == 0x7F;
}

bool isgraph(char c) {
  return ( '0' <= c && c <=  '9') ||
         ( 'A' <= c && c <=  'Z') ||
         ( 'a' <= c && c <=  'z') ||
         (0x21 <= c && c <= 0x2F) ||
         (0x3A <= c && c <= 0x40) ||
         (0x5B <= c && c <= 0x60) ||
         (0x7B <= c && c <= 0x7E);
}

bool isspace(char c) {
  return c ==  ' ' ||  // space
         c == '\f' ||  // form feed
         c == '\n' ||  // line feed
         c == '\r' ||  // carriage return
         c == '\t' ||  // horizontal tab
         c == '\v';    // vertical tab
}

bool isblank(char c) {
  return c == ' ' || c == '\t';
}

bool isprint(char c) {
  return ( '0' <= c && c <=  '9') ||
         ( 'A' <= c && c <=  'Z') ||
         ( 'a' <= c && c <=  'z') ||
         (0x21 <= c && c <= 0x2F) ||
         (0x3A <= c && c <= 0x40) ||
         (0x5B <= c && c <= 0x60) ||
         (0x7B <= c && c <= 0x7E) ||
                       c ==  ' ';
}

bool ispunct(char c) {
  return (0x21 <= c && c <= 0x2F) ||  // !"#$%&'()*+,-./
         (0x3A <= c && c <= 0x40) ||  // :;<=>?@
         (0x5B <= c && c <= 0x60) ||  // [\]^_`
         (0x7B <= c && c <= 0x7E);    // {|}~
}

char tolower(char c) {
  return ('A' <= c && c <= 'Z') ? c + ('a' - 'A') : c;
}

char toupper(char c) {
  return ('a' <= c && c <= 'z') ? c - ('a' - 'A') : c;
}

}  // namespace nstd
