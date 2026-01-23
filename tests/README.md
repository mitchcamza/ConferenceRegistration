# Unit Tests for Conference Registration

This directory contains unit tests for the core domain logic of the Conference Registration application using GoogleTest.

## Overview

The test suite focuses on **pure business logic** without UI or Qt event loop dependencies. Tests are deterministic, fast, and run headlessly in CI.

## Test Coverage

### Person Tests (6 tests)
- Basic construction and getters
- Empty and whitespace strings
- Special characters (unicode, accents)
- Long strings (boundary testing)
- `toString()` formatting

### Registration Tests (17 tests)
- **StandardRegistration**: construction, fee calculation ($100), toString
- **StudentRegistration**: construction, fee calculation ($50 - 50% discount), qualification handling
- **GuestRegistration**: construction, fee calculation ($10 - 10% discount), category handling
- Booking date validation and edge cases
- Fee calculation consistency and ratios

### RegistrationFactory Tests (19 tests)
- Singleton pattern verification
- Registration creation for all types (standard, student, guest)
- Case-insensitive type handling
- Invalid type handling (returns nullptr)
- Edge cases: empty strings, special characters, long strings, invalid dates
- Multiple registration creation

## Building and Running Tests

### Prerequisites
- CMake 3.5+
- C++17 compatible compiler
- Qt 5 or Qt 6 (Core module only)
- GoogleTest (automatically fetched via CMake FetchContent)

### Build Tests
```bash
mkdir build && cd build
cmake ..
make unit_tests
```

### Run Tests via CTest
```bash
cd build
ctest --output-on-failure
```

### Run Tests Directly
```bash
cd build/tests/unit
./unit_tests
```

### Run Specific Test
```bash
./unit_tests --gtest_filter=PersonTest.*
./unit_tests --gtest_filter=RegistrationFactoryTest.CreateStandardRegistration*
```

### Run with Verbose Output
```bash
./unit_tests --gtest_verbose
```

## CI Integration

Tests are automatically run in GitHub Actions on every pull request:
```yaml
- name: Run unit tests
  run: |
    cd build
    ctest --output-on-failure
```

## Test Philosophy

- **Focused**: Each test validates a single behavior
- **Independent**: Tests don't depend on each other
- **Deterministic**: No random data, no time-based dependencies
- **Fast**: All tests complete in < 1 second
- **Clear**: Descriptive test names and assertion messages

## Adding New Tests

1. Create a new test file in `tests/unit/` (e.g., `myclass_test.cpp`)
2. Add the file to `TEST_SOURCES` in `tests/unit/CMakeLists.txt`
3. Add any new source files to `CORE_SOURCES` if needed
4. Follow existing naming conventions:
   - Test file: `<class>_test.cpp`
   - Test fixture: `<Class>Test`
   - Test case: `<TestFixture>.<DescriptiveTestName>`

## Test Structure Example

```cpp
#include "myclass.h"
#include <gtest/gtest.h>

class MyClassTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(MyClassTest, DescriptiveTestName) {
    // Arrange
    MyClass obj("input");
    
    // Act
    auto result = obj.doSomething();
    
    // Assert
    EXPECT_EQ(result, expected);
}
```

## Known Limitations

- These tests do **not** cover:
  - UI components (Qt Widgets)
  - File I/O operations
  - Qt Model/View classes
  - Serialization logic
  
These areas require separate integration or functional tests.

## Resources

- [GoogleTest Documentation](https://google.github.io/googletest/)
- [GoogleTest Primer](https://google.github.io/googletest/primer.html)
- [CMake Testing Documentation](https://cmake.org/cmake/help/latest/manual/ctest.1.html)
