#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <cln/integer.h>
#include <cln/integer_io.h>

bool is_decimal_permutation(unsigned long long a, unsigned long long b);

int decimal_digits(unsigned long long n);

bool is_palindrome(std::string s);

cln::cl_I sum_digits(cln::cl_I val);

#endif
