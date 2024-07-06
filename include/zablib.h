#ifndef ZABLIB_HPP
#define ZABLIB_HPP

#include <iostream>

namespace zablib {
/**
 * @brief Get an integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The integer entered by the user.
 */
int get_int(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get an unsigned integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The unsigned integer entered by the user.
 */
unsigned int get_unsigned_int(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a short integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The short integer entered by the user.
 */
short int get_short_int(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a short unsigned integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The short unsigned integer entered by the user.
 */
unsigned short int get_short_unsigned_int(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a long integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The long integer entered by the user.
 */
long get_long(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get an unsigned long integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The unsigned long integer entered by the user.
 */
unsigned long get_unsigned_long(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a long long integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The long long integer entered by the user.
 */
long long get_long_long(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get an unsigned long long integer from the user.
 * @param prompt The prompt to display to the user.
 * @return The unsigned long long integer entered by the user.
 */
unsigned long long get_unsigned_long_long(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a character from the user.
 * @param prompt The prompt to display to the user.
 * @return The character entered by the user.
 */
char get_char(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a boolean value from the user.
 * @param prompt The prompt to display to the user.
 * @return The boolean value entered by the user.
 */
bool get_bool(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a string from the user.
 * @param prompt The prompt to display to the user.
 * @return The string entered by the user.
 */
std::string get_string(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a line of input from the user.
 * @param prompt The prompt to display to the user.
 * @return The line of input entered by the user.
 */
std::string get_line(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a choice from a list of options.
 * @param options The array of options to choose from.
 * @param prompt The prompt to display to the user.
 * @return The chosen option.
 */
std::string get_choice(const char *options[], const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get confirmation (yes/no) from the user.
 * @param prompt The prompt to display to the user.
 * @return True if the user confirms, false otherwise.
 */
bool get_confirmation(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Pause the console until the user presses a key.
 * @param prompt The prompt to display to the user.
 */
void pause_console(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Clear the console.
 */
void clear_console() {
    // TODO: Implement me
}

/**
 * @brief Get a date from the user.
 * @param prompt The prompt to display to the user.
 * @return The date entered by the user.
 */
std::string get_date(const std::string &prompt){
    // TODO: Implement me
}

/**
 * @brief Get a time from the user.
 * @param prompt The prompt to display to the user.
 * @return The time entered by the user.
 */
std::string get_time(const std::string &prompt){
    // TODO: Implement me
}
} // namespace zablib

#endif
