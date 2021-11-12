#include <gtest/gtest.h>
#include <string>
#include "..//big_integer.h"

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


TEST(TestTest, test16) {
    big_num::big_integer a(0);
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test17) {
    big_num::big_integer a(33);
    big_num::big_integer b(3);
    big_num::big_integer c = a / b;
    ASSERT_EQ(c.make_string(), "11");
}

TEST(TestTest, test18) {
    big_num::big_integer a(33);
    big_num::big_integer b(3);
    big_num::big_integer c = a % b;
    ASSERT_EQ(c.make_string(), "0");
}

TEST(TestTest, test19) {
    big_num::big_integer a(35);
    big_num::big_integer b(3);
    a /= b;
    ASSERT_EQ(a.make_string(), "11");
}


TEST(TestTest, test20) {
    big_num::big_integer a(35);
    big_num::big_integer b(3);
    a %= b;
    ASSERT_EQ(a.make_string(), "2");
}

TEST(TestTest, test21) {
    big_num::big_integer a(35);
    a += 2;
    ASSERT_EQ(a.make_string(), "37");
}

TEST(TestTest, test22) {
    big_num::big_integer a(35);
    a -= 2;
    ASSERT_EQ(a.make_string(), "33");
}

TEST(TestTest, test23) {
    big_num::big_integer a(35);
    a *= 2;
    ASSERT_EQ(a.make_string(), "70");
}

TEST(TestTest, test24) {
    big_num::big_integer a(35);
    a /= 2;
    ASSERT_EQ(a.make_string(), "17");
}

TEST(TestTest, test25) {
    big_num::big_integer a(35);
    a %= 2;
    ASSERT_EQ(a.make_string(), "1");
}

TEST(TestTest, test26) {
    big_num::big_integer a(-35);
    a *= 2;
    ASSERT_EQ(a.make_string(), "-70");
}

TEST(TestTest, test27) {
    unsigned int n = 3;
    big_num::big_integer a(n);
    a -= 2;
    ASSERT_EQ(a.make_string(), "1");
}

TEST(TestTest, test28) {
    unsigned long long n = 30000;
    big_num::big_integer a(n);
    a %= 149;
    ASSERT_EQ(a.make_string(), "51");
}

TEST(TestTest, test29) {
    signed long long n = -30000;
    big_num::big_integer a(n);
    a /= -149;
    ASSERT_EQ(a.make_string(), "201");
}

TEST(TestTest, test30) {
    big_num::big_integer a(149);
    big_num::big_integer b(2);
    big_num::big_integer c = a * b;
    ASSERT_EQ(c.make_string(), "298");
}

TEST(TestTest, test31) {
    big_num::big_integer a(149);
    big_num::big_integer b = a * 2;
    ASSERT_EQ(b.make_string(), "298");
}

TEST(TestTest, test32) {
    big_num::big_integer a(298);
    big_num::big_integer b(300);
    ASSERT_EQ(a <= b, true);
}

TEST(TestTest, test33) {
    signed long long n = 30000;
    big_num::big_integer a(n);
    a /= 149;
    ASSERT_EQ(a.make_string(), "201");
}

TEST(TestTest, test34) {
    signed long long n = 30000;
    big_num::big_integer a(n);
    a /= 0;
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test35) {
    big_num::big_integer a(298);
    big_num::big_integer b(300);
    a -= b;
    ASSERT_EQ(a.make_string(), "-2");
}

TEST(TestTest, test36) {
    big_num::big_integer a(298);
    big_num::big_integer b(-300);
    a -= b;
    ASSERT_EQ(a.make_string(), "598");
}

TEST(TestTest, test37) {
    big_num::big_integer a(298);
    big_num::big_integer b(-300);
    a -= b;
    ASSERT_EQ(a.make_string(), "598");
}

TEST(TestTest, test38) {
    big_num::big_integer a(-298);
    big_num::big_integer b(-300);
    ASSERT_EQ(a > b, true);
}

TEST(TestTest, test39) {
    big_num::big_integer a(-298);
    big_num::big_integer b(-300);
    ASSERT_EQ(a > b, true);
}

TEST(TestTest, test40) {
    big_num::big_integer a(-598);
    big_num::big_integer b(-300);
    ASSERT_EQ(a > b, false);
}

TEST(TestTest, test41) {
    big_num::big_integer a(-298);
    big_num::big_integer b(-30000);
    ASSERT_EQ(a > b, true);
}

TEST(TestTest, test42) {
    big_num::big_integer a(0);
    big_num::big_integer b(0);
    ASSERT_EQ(a > b, false);
}

TEST(TestTest, test43) {
    signed long long n = 0;
    big_num::big_integer a(n);
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test44) {
    unsigned long long n = 0;
    big_num::big_integer a(n);
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test45) {
    unsigned int n = 0;
    big_num::big_integer a(n);
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test46) {
    big_num::big_integer a("0000123");
    ASSERT_EQ(a.make_string(), "123");
}

TEST(TestTest, test47) {
    big_num::big_integer a(-1);
    big_num::big_integer b(1);
    ASSERT_EQ(a >= b, false);
}

TEST(TestTest, test48) {
    big_num::big_integer a(1);
    big_num::big_integer b(2);
    a /= b;
    ASSERT_EQ(a.make_string(), "0");
}

TEST(TestTest, test49) {
    big_num::big_integer a(5);
    big_num::big_integer b(-2);
    a /= b;
    ASSERT_EQ(a.make_string(), "-2");
}