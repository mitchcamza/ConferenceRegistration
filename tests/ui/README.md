# UI Tests

This directory contains UI tests for the Conference Registration application using the Qt Test framework.

## Overview

The UI tests validate the graphical user interface components to ensure:
- Widgets are properly initialized
- User interactions work correctly
- Dialogs display and collect data appropriately
- UI elements are properly connected via signals and slots

## Test Structure

### mainwindow_test.cpp
Tests for the main application window:
- Window initialization and default state
- Menu bar and menu items (File, Edit, Reports, Help)
- Toolbar existence and functionality
- Registration table view and model
- Search functionality via line edit widget

### newregistrationdialog_test.cpp
Tests for the new registration dialog:
- Dialog initialization
- Form field existence (name, email, affiliation, date)
- Registration type combo box and switching
- Conditional field visibility (student qualification, guest category)
- Button functionality (Register, Cancel)
- Dialog acceptance and rejection

### statistics_dialogs_test.cpp
Tests for statistics dialogs:

**TotalFeesDialog:**
- Dialog initialization
- Registration type combo box
- Total fees display field
- Calculation updates when registration type changes

**TotalRegisteredDialog:**
- Dialog initialization
- Affiliation input field
- Total count display field
- Dynamic count updates based on affiliation

## Running UI Tests

### Prerequisites
- Qt 5 or Qt 6 with Qt Test module
- CMake 3.5 or higher
- C++17 compatible compiler

### Build and Run All UI Tests
```bash
cd build
ctest --output-on-failure -R UITests
```

### Run UI Tests Directly
```bash
cd build/tests/ui
./ui_tests
```

### Run Tests Headless (for CI)
```bash
export QT_QPA_PLATFORM=offscreen
cd build/tests/ui
./ui_tests
```

### Run Specific Test Case
```bash
cd build/tests/ui
./ui_tests -functions  # List all test functions
./ui_tests MainWindowTest::testWindowInitialization
```

## Test Approach

### Qt Test Framework
UI tests use Qt's built-in testing framework (`QTest`) which provides:
- Test fixtures with `init()` and `cleanup()` methods
- Assertion macros (`QVERIFY`, `QCOMPARE`)
- Widget interaction simulation (`QTest::mouseClick`, `QTest::keyClick`)
- Automatic test discovery via `QTEST_MAIN` macro

### Headless Testing
Tests run in headless mode using Qt's offscreen platform plugin:
- No display required
- Suitable for CI/CD pipelines
- Fast execution
- Full widget functionality without rendering

### Widget Testing Strategy
1. **Existence Tests**: Verify widgets are created and accessible
2. **State Tests**: Check initial states and default values
3. **Interaction Tests**: Simulate user actions (clicks, text input)
4. **Integration Tests**: Verify widget connections and signal/slot behavior

### Limitations
- Tests focus on widget structure and basic interactions
- Complex user workflows are better suited for integration tests
- Visual appearance and rendering are not validated
- Some modal dialog behaviors are difficult to test automatically

## Test Coverage

These UI tests complement the existing test suite:
- **Unit Tests (42)**: Core business logic
- **Integration Tests (16)**: XML persistence
- **UI Tests (30+)**: User interface components

Together, these provide comprehensive coverage of the application.

## CI Integration

UI tests run automatically in CI via GitHub Actions:
```yaml
- name: Run tests
  run: |
    cd build
    export QT_QPA_PLATFORM=offscreen
    ctest --output-on-failure
```

The `QT_QPA_PLATFORM=offscreen` environment variable enables headless testing.

## Future Enhancements

Potential improvements for UI testing:
- Add tests for keyboard navigation
- Test context menu actions
- Add tests for edit/delete functionality
- Test file dialog interactions (mocked)
- Add screenshot comparison tests
- Test responsive behavior with different window sizes
- Add accessibility tests (keyboard-only navigation)

## Contributing

When adding new UI components:
1. Create corresponding test file in `tests/ui/`
2. Follow existing naming conventions
3. Test widget existence, state, and basic interactions
4. Update this README with new test descriptions
5. Ensure tests run headless for CI compatibility

## References

- [Qt Test Tutorial](https://doc.qt.io/qt-6/qtest-tutorial.html)
- [Qt Test Overview](https://doc.qt.io/qt-6/qtest-overview.html)
- [QTest Class Reference](https://doc.qt.io/qt-6/qtest.html)
