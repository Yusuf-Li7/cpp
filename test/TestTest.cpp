#include <gtest/gtest.h>
#include <string>
#include "..//big_integer.h"
//#include "..//main.cpp"

TEST(TestTest, test) {
    std::string s_a = "91";
    std::string s_op = "+";
    std::string s_b = "2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a + b;
    ASSERT_EQ(c.make_string(), "93");
}

TEST(TestTest, test2) {
    std::string s_a = "91";
    std::string s_op = "+";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a + b;
    ASSERT_EQ(c.make_string(), "89");
}

TEST(TestTest, test3) {
    std::string s_a = "-91";
    std::string s_op = "+";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a + b;
    ASSERT_EQ(c.make_string(), "-93");
}

TEST(TestTest, test4) {
    std::string s_a = "-91";
    std::string s_op = "+";
    std::string s_b = "2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a + b;
    ASSERT_EQ(c.make_string(), "-89");
}

TEST(TestTest, test5) {
    std::string s_a = "91";
    std::string s_op = ">";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    bool ans = a > b;
    ASSERT_EQ(ans, true);
}

TEST(TestTest, test6) {
    std::string s_a = "91";
    std::string s_op = "<";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    bool ans = a < b;
    ASSERT_EQ(ans, false);
}

TEST(TestTest, test7) {
    std::string s_a = "91";
    std::string s_op = "==";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    bool ans = a == b;
    ASSERT_EQ(ans, false);
}

TEST(TestTest, test8) {
    std::string s_a = "91";
    std::string s_op = ">=";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    bool ans = a >= b;
    ASSERT_EQ(ans, true);
}

TEST(TestTest, test9) {
    std::string s_a = "91";
    std::string s_op = "<=";
    std::string s_b = "-2";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    bool ans = a <= b;
    ASSERT_EQ(ans, false);
}

TEST(TestTest, test10) {
    std::string s_a = "91";
    std::string s_op = "+=";
    std::string s_b = "-20";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    a += b;
    ASSERT_EQ(a.make_string(), "71");
}

TEST(TestTest, test11) {
    std::string s_a = "-50";
    std::string s_op = "*=";
    std::string s_b = "3";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    a *= b;
    ASSERT_EQ(a.make_string(), "-150");
}

TEST(TestTest, test12) {
    std::string s_a = "-5";
    std::string s_op = "*";
    std::string s_b = "30";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a * b;
    ASSERT_EQ(c.make_string(), "-150");
}

TEST(TestTest, test13) {
    std::string s_a = "-5";
    std::string s_op = "-";
    std::string s_b = "30";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a - b;
    ASSERT_EQ(c.make_string(), "-35");
}

TEST(TestTest, test14) {
    std::string s_a = "-5";
    std::string s_op = "-";
    std::string s_b = "-30";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a - b;
    ASSERT_EQ(c.make_string(), "25");
}

TEST(TestTest, test15) {
    std::string s_a = "-5";
    std::string s_op = "+";
    std::string s_b = "-30";
    big_num::big_integer a;
    a.make_number(s_a);
    big_num::big_integer b;
    b.make_number(s_b);
    big_num::big_integer c;
    c = a + b;
    ASSERT_EQ(c.make_string(), "-35");
}