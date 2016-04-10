# nano-test
C++ testing framework with a minimalistic approach

### Example usage

```c++
// Include framework header
#include "nano-test.h"

// Testable function
int square(int value)
{
    return value * value;
}

// Start test suite
TEST_SUITE_BEGIN

// You are writing a program as usual, so any function calls can be here
std::cout << "= Testing square =" << std::endl;

// Let's test something
TEST(square(4) == 16) // That's Ok
TEST(square(2) == 16) // That's Fail
TEST_MSG(square(2) == 16, "Square of two is 4 not 16") // See a message

// Close test suite
TEST_SUITE_END
```
