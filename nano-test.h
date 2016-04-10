/**
* nano-test - C++ testing framework with a minimalistic approach
* 
* Testing with nano-test is quite simple:
* 1. open test suite with TEST_SUITE_BEGIN
* 2. TEST(...)
*    TEST(...)
*    ...
* 3. close the suite with TEST_SUITE_END
*/

#pragma once

#include <iostream>

static size_t _PASSED_COUNT_ = 0;
static size_t _FAILED_COUNT_ = 0;

/**
* A test suite starts with that declaration
*/
#define TEST_SUITE_BEGIN int main() \
{ \
    std::cout << "Running test suite:\n" << std::endl;

/**
* Test is described by TEST(condition), if condition is false so TEST is failed
*/
#define TEST(cond) if (!(cond)) { \
    ++_FAILED_COUNT_; \
    std::cout << "- Line " << __LINE__ << ": [FAILED]" << std::endl; \
} else { \
    ++_PASSED_COUNT_; \
    std::cout << "- Line " << __LINE__ << ": [OK]" << std::endl; \
}

/**
* Like TEST, but you can specify a message when test is failed
*/
#define TEST_MSG(cond, message) if (!(cond)) { \
    ++_FAILED_COUNT_; \
    std::cout << "- Line " << __LINE__ << ": [FAILED] " << (message) << std::endl; \
} else { \
    ++_PASSED_COUNT_; \
    std::cout << "- Line " << __LINE__ << ": [OK]" << std::endl; \
}

/**
* This declaration must terminate a test suite
*/
#define TEST_SUITE_END std::cout << "\nFinished:\n- Tests PASSED: " << _PASSED_COUNT_ \
    << "\n- Tests FAILED: " << _FAILED_COUNT_ << std::endl; \
    return 0; \
}
