# Integration Tests

This directory contains integration tests that validate end-to-end functionality of the ConferenceRegistration application.

## Test Suites

### XML Persistence Tests (`xml_persistence_test.cpp`)

Integration tests that validate XML serialization and deserialization of registration data.

#### Test Categories

**1. Round-trip Integrity Tests**
- Create registrations in memory
- Write to XML file
- Read back from XML
- Verify deep equality of original and loaded data
- Covers: Standard, Student, Guest registrations, multiple registrations, empty lists

**2. Golden File Fixture Tests**
- Load known-good XML files from `../fixtures/xml/`
- Validate correct parsing behavior
- Verify all registration types and their properties

**3. Error and Edge Case Tests**
- Malformed XML handling
- Missing required fields
- Missing type attributes
- Empty XML files
- Non-existent files
- Read-only location handling
- Deterministic output verification

## Running Tests

Run all tests (unit + integration):
```bash
cd build
ctest --output-on-failure
```

Run only integration tests:
```bash
cd build
ctest --output-on-failure -R XmlPersistence
```

Run specific integration test:
```bash
cd build
./tests/integration/integration_tests --gtest_filter=XmlPersistenceTest.RoundTripStandardRegistration
```

## Test Fixtures

XML fixture files are located in `../fixtures/xml/`:
- `valid_standard.xml` - Single standard registration
- `valid_student.xml` - Single student registration  
- `valid_guest.xml` - Single guest registration
- `valid_multiple.xml` - Multiple registrations of different types
- `empty.xml` - Empty registration list
- `malformed.xml` - Malformed XML (unclosed tags)
- `missing_name.xml` - Registration with missing name field
- `missing_type.xml` - Registration with missing type attribute

## Adding New Tests

1. Add test method to appropriate test fixture class
2. Use GoogleTest assertions (`EXPECT_*`, `ASSERT_*`)
3. Clean up resources (use `cleanupRegistrations()` helper)
4. Rebuild and run tests to verify

## Design Principles

- **Isolation**: Uses `QTemporaryDir` for test file operations
- **Deterministic**: Tests produce consistent results across platforms
- **Clear Failures**: Assertions provide actionable error messages
- **No Hardcoded Paths**: Uses `FIXTURES_PATH` compile definition
- **Explicit Behavior**: Edge cases have explicitly asserted expected behaviors
