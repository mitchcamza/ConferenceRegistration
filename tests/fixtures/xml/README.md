# Test Fixtures

This directory contains curated XML test fixtures used by integration tests to validate XML parsing behavior.

## Valid Fixtures

### `valid_standard.xml`
Single standard registration with complete data:
- Standard registration type
- Full attendee information (name, affiliation, email)
- Booking date
- Registration fee (100)

### `valid_student.xml`
Single student registration with complete data:
- Student registration type
- Full attendee information
- Qualification field ("PhD Candidate")
- Registration fee (50)

### `valid_guest.xml`
Single guest registration with complete data:
- Guest registration type
- Full attendee information
- Category field ("Keynote Speaker")
- Registration fee (10)

### `valid_multiple.xml`
Multiple registrations of different types:
- 1 standard registration
- 1 student registration
- 1 guest registration
- Tests parsing of multiple entries in one file

### `empty.xml`
Empty registration list:
- Valid XML structure
- No registration entries
- Tests handling of empty lists

## Invalid/Error Fixtures

### `malformed.xml`
Malformed XML with unclosed tag:
- Tests error handling for invalid XML
- Expected behavior: Returns empty list

### `missing_name.xml`
Registration with missing required name field:
- Tests handling of incomplete data
- Current behavior: Creates registration with empty name
- Documents actual system behavior for edge cases

### `missing_type.xml`
Registration without type attribute:
- Tests handling of missing type
- Expected behavior: Skips registration (factory returns null)

## Usage

Fixtures are referenced in tests using the `FIXTURES_PATH` compile definition:

```cpp
QString fixturePath = getFixturePath("valid_standard.xml");
RegistrationListReader reader(fixturePath);
QList<Registration*> registrations = reader.read();
```

## Adding New Fixtures

1. Create XML file following the schema used by `RegistrationListWriter`
2. Add descriptive comments in this README
3. Add corresponding test in `xml_persistence_test.cpp`
4. Verify test passes with `ctest`

## XML Schema

```xml
<?xml version="1.0" encoding="UTF-8"?>
<registrationlist>
    <registration type="standard|student|guest">
        <attendee>
            <name>Full Name</name>
            <affiliation>Institution</affiliation>
            <email>email@example.com</email>
        </attendee>
        <bookingdate>YYYY-MM-DD</bookingdate>
        <!-- Optional: for student -->
        <qualification>Qualification Text</qualification>
        <!-- Optional: for guest -->
        <category>Category Text</category>
        <registrationfee>Number</registrationfee>
    </registration>
</registrationlist>
```
