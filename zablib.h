#ifndef ZABLIB_H
#define ZABLIB_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ZabLib {
private:
  // Helper method to clear input stream
  void clearInputStream();

  // Helper method to clear console (platform agnostic)
  void clearScreen();

  // Helper method to validate numeric input
  template <typename T>
  bool isValidNumeric(const std::string &input, T &result);

public:
  // Integer input functions
  int get_int(const std::string &msg);
  unsigned int get_unsigned_int(const std::string &msg);
  long long get_long_long(const std::string &msg);
  unsigned long long get_unsigned_long_long(const std::string &msg);

  // Character and string input functions
  char get_char(const std::string &msg);
  bool get_bool(const std::string &msg);
  std::string get_word(const std::string &msg);
  std::string get_line(const std::string &msg);

  // Choice and confirmation functions
  int get_choice(const char *choices[], int num_choices,
                 const std::string &msg);
  bool get_confirmation(const std::string &msg);

  // Utility functions
  void pause_console(const std::string &msg = "Press Enter to continue...");
  void clear_console();

  // Date and time functions (simplified format)
  std::string get_date(const std::string &msg);
  std::string get_time(const std::string &msg);
};

// Template implementation for numeric validation
template <typename T>
bool ZabLib::isValidNumeric(const std::string &input, T &result) {
  std::stringstream ss(input);
  ss >> result;

  // Check if the entire string was consumed and no error occurred
  return ss.eof() && !ss.fail();
}

// Helper method implementations
inline void ZabLib::clearInputStream() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void ZabLib::clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Integer input functions
inline int ZabLib::get_int(const std::string &msg) {
  int value;
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    if (isValidNumeric(input, value)) {
      // Additional check for range
      std::stringstream ss(input);
      long long temp;
      ss >> temp;

      if (temp >= std::numeric_limits<int>::min() &&
          temp <= std::numeric_limits<int>::max()) {
        return value;
      } else {
        std::cout << "Error: int value out of range. Please try again.\n";
      }
    } else {
      std::cout << "Error: '" << input
                << "' is not a valid integer. Please try again.\n";
    }
  }
}

inline unsigned int ZabLib::get_unsigned_int(const std::string &msg) {
  unsigned int value;
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    if (isValidNumeric(input, value)) {
      // Additional check for negative values
      if (input.find('-') == std::string::npos) {
        std::stringstream ss(input);
        unsigned long long temp;
        ss >> temp;

        if (temp <= std::numeric_limits<unsigned int>::max()) {
          return value;
        } else {
          std::cout
              << "Error: unsigned int value out of range. Please try again.\n";
        }
      } else {
        std::cout
            << "Error: unsigned int cannot be negative. Please try again.\n";
      }
    } else {
      std::cout << "Error: '" << input
                << "' is not a valid unsigned integer. Please try again.\n";
    }
  }
}

inline long long ZabLib::get_long_long(const std::string &msg) {
  long long value;
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    if (isValidNumeric(input, value)) {
      return value;
    } else {
      std::cout << "Error: '" << input
                << "' is not a valid long long integer. Please try again.\n";
    }
  }
}

inline unsigned long long
ZabLib::get_unsigned_long_long(const std::string &msg) {
  unsigned long long value;
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    if (isValidNumeric(input, value)) {
      if (input.find('-') == std::string::npos) {
        return value;
      } else {
        std::cout << "Error: unsigned long long cannot be negative. Please try "
                     "again.\n";
      }
    } else {
      std::cout << "Error: '" << input
                << "' is not a valid unsigned long long. Please try again.\n";
    }
  }
}

// Character and string input functions
inline char ZabLib::get_char(const std::string &msg) {
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    if (input.length() == 1) {
      return input[0];
    } else if (input.empty()) {
      std::cout << "Error: Please enter a character.\n";
    } else {
      std::cout << "Error: Please enter only one character.\n";
    }
  }
}

inline bool ZabLib::get_bool(const std::string &msg) {
  std::string input;

  while (true) {
    std::cout << msg;
    std::getline(std::cin, input);

    // Convert to lowercase for comparison
    for (char &c : input) {
      c = std::tolower(c);
    }

    if (input == "true" || input == "t" || input == "yes" || input == "y" ||
        input == "1") {
      return true;
    } else if (input == "false" || input == "f" || input == "no" ||
               input == "n" || input == "0") {
      return false;
    } else {
      std::cout
          << "Error: Please enter true/false, yes/no, y/n, t/f, or 1/0.\n";
    }
  }
}

inline std::string ZabLib::get_word(const std::string &msg) {
  std::string input;
  std::cout << msg;
  std::cin >> input;
  clearInputStream();
  return input;
}

inline std::string ZabLib::get_line(const std::string &msg) {
  std::string input;
  std::cout << msg;
  std::getline(std::cin, input);
  return input;
}

// Choice and confirmation functions
inline int ZabLib::get_choice(const char *choices[], int num_choices,
                              const std::string &msg) {
  int choice;

  while (true) {
    std::cout << msg << std::endl;
    for (int i = 0; i < num_choices; i++) {
      std::cout << (i + 1) << ". " << choices[i] << std::endl;
    }
    std::cout << "Enter your choice (1-" << num_choices << "): ";

    choice = get_int("");

    if (choice >= 1 && choice <= num_choices) {
      return choice - 1; // Return 0-based index
    } else {
      std::cout << "Error: Please enter a number between 1 and " << num_choices
                << ".\n";
    }
  }
}

inline bool ZabLib::get_confirmation(const std::string &msg) {
  std::string input;

  while (true) {
    std::cout << msg << " (y/n): ";
    std::getline(std::cin, input);

    for (char &c : input) {
      c = std::tolower(c);
    }

    if (input == "y" || input == "yes") {
      return true;
    } else if (input == "n" || input == "no") {
      return false;
    } else {
      std::cout << "Error: Please enter 'y' or 'n'.\n";
    }
  }
}

// Utility functions
inline void ZabLib::pause_console(const std::string &msg) {
  std::cout << msg;
  std::cin.get();
  clearInputStream();
}

inline void ZabLib::clear_console() { clearScreen(); }

// Date and time functions (simplified format)
inline std::string ZabLib::get_date(const std::string &msg) {
  std::string input;

  while (true) {
    std::cout << msg << " (MM/DD/YYYY): ";
    std::getline(std::cin, input);

    // Simple validation for MM/DD/YYYY format
    if (input.length() == 10 && input[2] == '/' && input[5] == '/') {
      bool valid = true;
      for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !std::isdigit(input[i])) {
          valid = false;
          break;
        }
      }
      if (valid) {
        return input;
      }
    }

    std::cout << "Error: Please enter date in MM/DD/YYYY format.\n";
  }
}

inline std::string ZabLib::get_time(const std::string &msg) {
  std::string input;

  while (true) {
    std::cout << msg << " (HH:MM): ";
    std::getline(std::cin, input);

    // Simple validation for HH:MM format
    if (input.length() == 5 && input[2] == ':') {
      bool valid = true;
      for (int i = 0; i < 5; i++) {
        if (i != 2 && !std::isdigit(input[i])) {
          valid = false;
          break;
        }
      }
      if (valid) {
        return input;
      }
    }

    std::cout << "Error: Please enter time in HH:MM format.\n";
  }
}

#endif // ZABLIB_H
