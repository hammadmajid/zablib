# ZabLib

> [!CAUTION]
> Use at your own risk! This library is still in development.

A simple, robust input/output library designed for SZABIST students to handle console input validation and user interaction in C++.

## Features

- **Type-safe input validation** - Robust validation for all numeric types
- **Error handling** - Clear error messages and automatic retry on invalid input
- **Cross-platform compatibility** - Works on Windows, Linux, and macOS
- **Header-only library** - Easy to integrate into any project
- **Multiple input types** - Support for integers, strings, characters, booleans, dates, and times
- **Interactive menus** - Built-in choice selection and confirmation dialogs
- **Console utilities** - Screen clearing and pause functionality

## Quick Start

1. Download the `zablib.h` file
2. Include it in your C++ project:
   ```cpp
   #include "zablib.h"
   ```
3. Create a ZabLib instance and start using it:
   ```cpp
   ZabLib io;
   int age = io.get_int("Enter your age: ");
   ```

## Usage Examples

### Basic Input Types

```cpp
#include "zablib.h"

int main() {
    ZabLib io;
    
    // Get different types of input
    int age = io.get_int("Enter your age: ");
    std::string name = io.get_line("Enter your full name: ");
    char grade = io.get_char("Enter your grade (A-F): ");
    bool isStudent = io.get_bool("Are you a student? (y/n): ");
    
    std::cout << "Hello " << name << ", age " << age << std::endl;
    return 0;
}
```

### Menu Selection

```cpp
#include "zablib.h"

int main() {
    ZabLib io;
    
    const char* options[] = {
        "View Profile",
        "Edit Settings", 
        "Logout",
        "Exit"
    };
    
    int choice = io.get_choice(options, 4, "Main Menu:");
    
    switch(choice) {
        case 0: std::cout << "Viewing profile..." << std::endl; break;
        case 1: std::cout << "Editing settings..." << std::endl; break;
        case 2: std::cout << "Logging out..." << std::endl; break;
        case 3: std::cout << "Goodbye!" << std::endl; break;
    }
    
    return 0;
}
```

### Date and Time Input

```cpp
#include "zablib.h"

int main() {
    ZabLib io;
    
    std::string birthDate = io.get_date("Enter your birth date");
    std::string appointmentTime = io.get_time("Enter appointment time");
    
    std::cout << "Appointment scheduled for " << appointmentTime 
              << " on " << birthDate << std::endl;
    
    return 0;
}
```

## API Reference

### Integer Input Functions

| Function | Description | Return Type |
|----------|-------------|-------------|
| `get_int(msg)` | Get a valid integer input | `int` |
| `get_unsigned_int(msg)` | Get a valid unsigned integer | `unsigned int` |
| `get_long_long(msg)` | Get a valid long long integer | `long long` |
| `get_unsigned_long_long(msg)` | Get a valid unsigned long long | `unsigned long long` |

### String and Character Input

| Function | Description | Return Type |
|----------|-------------|-------------|
| `get_char(msg)` | Get a single character | `char` |
| `get_word(msg)` | Get a single word (no spaces) | `std::string` |
| `get_line(msg)` | Get a full line of text | `std::string` |

### Boolean and Choice Input

| Function | Description | Return Type |
|----------|-------------|-------------|
| `get_bool(msg)` | Get boolean input (true/false, y/n, 1/0) | `bool` |
| `get_choice(choices[], count, msg)` | Display menu and get user choice | `int` |
| `get_confirmation(msg)` | Get yes/no confirmation | `bool` |

### Date and Time Input

| Function | Description | Return Type | Format |
|----------|-------------|-------------|---------|
| `get_date(msg)` | Get date input with validation | `std::string` | MM/DD/YYYY |
| `get_time(msg)` | Get time input with validation | `std::string` | HH:MM |

### Utility Functions

| Function | Description |
|----------|-------------|
| `pause_console(msg)` | Pause execution until user presses Enter |
| `clear_console()` | Clear the console screen |

## Input Validation

ZabLib automatically validates all input and provides helpful error messages:

- **Numeric validation**: Ensures input is within valid range for the data type
- **Format validation**: Checks date/time formats match expected patterns
- **Type validation**: Prevents invalid conversions and overflow
- **Retry mechanism**: Automatically prompts user to re-enter invalid input

## Error Messages

The library provides clear, user-friendly error messages:

```
Error: 'abc' is not a valid integer. Please try again.
Error: unsigned int cannot be negative. Please try again.
Error: Please enter date in MM/DD/YYYY format.
Error: Please enter 'y' or 'n'.
```

## Platform Support

- **Windows**: Uses `cls` command for screen clearing
- **Linux/macOS**: Uses `clear` command for screen clearing
- **All platforms**: Cross-platform compatible input handling

## Requirements

- C++11 or later
- Standard C++ library
- Console/terminal environment

## Installation

Simply download `zablib.h` and include it in your project. No compilation or linking required.

## Contributing

This library is designed for SZABIST students. Feel free to suggest improvements or report issues.

## License

Open source - feel free to use and modify for educational purposes.

---

*Made with ❤️ for SZABIST students*
