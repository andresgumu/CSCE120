// this file is provided, do NOT submit it to Gradescope
#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <iostream>
#include <cmath>

#define report(X) { auto value = X; std::cout << #X  << "=" << value << std::endl; }
#define report_unexpected_exception std::cout << "[FAIL] (" << __func__ << ":" << __LINE__ << ") caught an unexpected exception." << std::endl; throw;
#define report_not_near(expression,expected,actual) std::cout << "[FAIL] (" << __func__ << ":" << __LINE__ << ") expected " << expression << " to be within 0.00005 of " << expected << ", got " << actual << std::endl;
#define report_missing_throw(expression,expected) std::cout << "[FAIL] (" << __func__ << ":" << __LINE__ << ") expected " << expression << " to throw " << expected << ", got nothing" << std::endl;

#define expect_near(A,X) {\
    double actual, expected;\
    try { actual = A; expected = X; } catch (...) { report_unexpected_exception }\
    if (std::abs(actual - expected) > 0.00005) { report_not_near(#A,expected,actual) } }

#define expect_throw(A,X) {\
try { A; report_missing_throw(#A,#X) } catch (const X& err) {  } catch (...) { report_unexpected_exception } }

#endif  // TEST_HELPERS_H
