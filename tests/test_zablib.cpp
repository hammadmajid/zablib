#include <gtest/gtest.h>
#include <sstream>
#include "zablib.h"

class ZabLibTest : public ::testing::Test {
protected:
    void SetUp() override {
        orig_buf = std::cin.rdbuf(input.rdbuf());
    }

    void TearDown() override {
        std::cin.rdbuf(orig_buf);
    }

    std::stringstream input;
    std::streambuf* orig_buf;
};

TEST_F(ZabLibTest, GetIntTest) {
    input.str("42\n-1\n100\nabc\n");
    EXPECT_EQ(zablib::get_int("Enter an integer: "), 42);
    EXPECT_EQ(zablib::get_int("Enter an integer: "), -1);
    EXPECT_EQ(zablib::get_int("Enter an integer: "), 100);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_int("Enter an integer: "), 42);
}

TEST_F(ZabLibTest, GetUnsignedIntTest) {
    input.str("42\n0\n100\n-1\nabc\n");
    EXPECT_EQ(zablib::get_unsigned_int("Enter an unsigned integer: "), 42);
    EXPECT_EQ(zablib::get_unsigned_int("Enter an unsigned integer: "), 0);
    EXPECT_EQ(zablib::get_unsigned_int("Enter an unsigned integer: "), 100);
    input.str("-1\n42\n");
    EXPECT_EQ(zablib::get_unsigned_int("Enter an unsigned integer: "), 42);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_unsigned_int("Enter an unsigned integer: "), 42);
}

TEST_F(ZabLibTest, GetShortIntTest) {
    input.str("42\n-1\n32767\n-32768\n100\nabc\n");
    EXPECT_EQ(zablib::get_short_int("Enter a short integer: "), 42);
    EXPECT_EQ(zablib::get_short_int("Enter a short integer: "), -1);
    EXPECT_EQ(zablib::get_short_int("Enter a short integer: "), 32767);
    EXPECT_EQ(zablib::get_short_int("Enter a short integer: "), -32768);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_short_int("Enter a short integer: "), 42);
}

TEST_F(ZabLibTest, GetShortUnsignedIntTest) {
    input.str("42\n0\n100\n65535\n-1\nabc\n");
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 42);
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 0);
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 100);
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 65535);
    input.str("-1\n42\n");
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 42);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_short_unsigned_int("Enter a short unsigned integer: "), 42);
}

TEST_F(ZabLibTest, GetLongTest) {
    input.str("42\n-1\n2147483647\n-2147483648\nabc\n");
    EXPECT_EQ(zablib::get_long("Enter a long integer: "), 42);
    EXPECT_EQ(zablib::get_long("Enter a long integer: "), -1);
    EXPECT_EQ(zablib::get_long("Enter a long integer: "), 2147483647);
    EXPECT_EQ(zablib::get_long("Enter a long integer: "), -2147483648);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_long("Enter a long integer: "), 42);
}

TEST_F(ZabLibTest, GetUnsignedLongTest) {
    input.str("42\n0\n100\n4294967295\n-1\nabc\n");
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 42);
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 0);
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 100);
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 4294967295);
    input.str("-1\n42\n");
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 42);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_unsigned_long("Enter an unsigned long integer: "), 42);
}

TEST_F(ZabLibTest, GetLongLongTest) {
    input.str("42\n-1\n9223372036854775807\n-9223372036854775808\nabc\n");
    EXPECT_EQ(zablib::get_long_long("Enter a long long integer: "), 42);
    EXPECT_EQ(zablib::get_long_long("Enter a long long integer: "), -1);
    EXPECT_EQ(zablib::get_long_long("Enter a long long integer: "), 9223372036854775807);
    EXPECT_EQ(zablib::get_long_long("Enter a long long integer: "), -9223372036854775808);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_long_long("Enter a long long integer: "), 42);
}

TEST_F(ZabLibTest, GetUnsignedLongLongTest) {
    input.str("42\n0\n100\n18446744073709551615\n-1\nabc\n");
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 42);
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 0);
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 100);
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 18446744073709551615U);
    input.str("-1\n42\n");
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 42);
    input.str("abc\n42\n");
    EXPECT_EQ(zablib::get_unsigned_long_long("Enter an unsigned long long integer: "), 42);
}

TEST_F(ZabLibTest, GetCharTest) {
    input.str("a\nb\n1\n\n");
    EXPECT_EQ(zablib::get_char("Enter a character: "), 'a');
    EXPECT_EQ(zablib::get_char("Enter a character: "), 'b');
    EXPECT_EQ(zablib::get_char("Enter a character: "), '1');
    input.str("\n\n");
    EXPECT_EQ(zablib::get_char("Enter a character: "), '\n');
}

TEST_F(ZabLibTest, GetBoolTest) {
    input.str("1\n0\ny\nn\nabc\n");
    EXPECT_TRUE(zablib::get_bool("Enter a boolean (1/0): "));
    EXPECT_FALSE(zablib::get_bool("Enter a boolean (1/0): "));
    input.str("y\nn\n");
    EXPECT_TRUE(zablib::get_bool("Enter a boolean (1/0): "));
    EXPECT_FALSE(zablib::get_bool("Enter a boolean (1/0): "));
    input.str("abc\n1\n");
    EXPECT_TRUE(zablib::get_bool("Enter a boolean (1/0): "));
}

TEST_F(ZabLibTest, GetStringTest) {
    input.str("hello\nworld\n123\n");
    EXPECT_EQ(zablib::get_string("Enter a string: "), "hello");
    EXPECT_EQ(zablib::get_string("Enter a string: "), "world");
    EXPECT_EQ(zablib::get_string("Enter a string: "), "123");
}

TEST_F(ZabLibTest, GetLineTest) {
    input.str("this is a line\nanother line\n123\n");
    EXPECT_EQ(zablib::get_line("Enter a line: "), "this is a line");
    EXPECT_EQ(zablib::get_line("Enter a line: "), "another line");
    EXPECT_EQ(zablib::get_line("Enter a line: "), "123");
}

TEST_F(ZabLibTest, GetChoiceTest) {
    const char* options[] = {"option1", "option2", "option3"};
    input.str("option2\noption1\noption3\n");
    EXPECT_EQ(zablib::get_choice(options, "Choose an option: "), "option2");
    EXPECT_EQ(zablib::get_choice(options, "Choose an option: "), "option1");
    EXPECT_EQ(zablib::get_choice(options, "Choose an option: "), "option3");
    input.str("invalid\noption1\n");
    EXPECT_EQ(zablib::get_choice(options, "Choose an option: "), "option1");
}

TEST_F(ZabLibTest, GetConfirmationTest) {
    input.str("y\nn\nyes\nno\nabc\n");
    EXPECT_TRUE(zablib::get_confirmation("Confirm (y/n): "));
    EXPECT_FALSE(zablib::get_confirmation("Confirm (y/n): "));
    input.str("yes\nno\n");
    EXPECT_TRUE(zablib::get_confirmation("Confirm (y/n): "));
    EXPECT_FALSE(zablib::get_confirmation("Confirm (y/n): "));
    input.str("abc\ny\n");
    EXPECT_TRUE(zablib::get_confirmation("Confirm (y/n): "));
}

TEST_F(ZabLibTest, PauseConsoleTest) {
    input.str("\n");
    zablib::pause_console("Press any key to continue...");
    SUCCEED();
}

TEST_F(ZabLibTest, ClearConsoleTest) {
    zablib::clear_console();
    SUCCEED();
}

TEST_F(ZabLibTest, GetDateTest) {
    input.str("2024-07-06\n2023-01-01\ninvalid\n2024-07-06\n");
    EXPECT_EQ(zablib::get_date("Enter a date: "), "2024-07-06");
    EXPECT_EQ(zablib::get_date("Enter a date: "), "2023-01-01");
    input.str("invalid\n2024-07-06\n");
    EXPECT_EQ(zablib::get_date("Enter a date: "), "2024-07-06");
}

TEST_F(ZabLibTest, GetTimeTest) {
    input.str("12:34\n23:59\ninvalid\n12:34\n");
    EXPECT_EQ(zablib::get_time("Enter a time: "), "12:34");
    EXPECT_EQ(zablib::get_time("Enter a time: "), "23:59");
    input.str("invalid\n12:34\n");
    EXPECT_EQ(zablib::get_time("Enter a time: "), "12:34");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
