#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
using namespace std;
namespace big_num{

class big_integer {
public:
    explicit big_integer(const std::string& number);
    explicit big_integer(unsigned int number);
    explicit big_integer(signed int number);
    explicit big_integer(unsigned long long number);
    explicit big_integer(signed long long number);
    big_integer();

    std::vector<uint8_t> v; // число
    bool sing = false; // знак числа

    void make_number(std::string s);

    std::string make_string();

    //friend std::ostream& operator <<(std::ostream& ostream, const big_integer& number);

    big_integer operator+(big_integer& other);

    big_integer operator-(big_integer& other);

    big_integer operator+=(big_integer& other);

    big_integer operator-=(big_integer& other);

    big_integer operator*(big_integer& other);

    big_integer operator*=(big_integer& other);

    big_integer operator/(big_integer& other);

    big_integer operator/=(big_integer& other);

    big_integer operator%(big_integer& other);

    big_integer operator%=(big_integer& other);

    big_integer operator+(int other);

    big_integer operator-(int other);

    big_integer operator+=(int other);

    big_integer operator-=(int other);

    big_integer operator*(int other);

    big_integer operator*=(int other);

    big_integer operator/(int other);

    big_integer operator/=(int other);

    big_integer operator%(int other);

    big_integer operator%=(int other);

    bool operator==(big_integer& other);

    bool operator<(big_integer& other);

    bool operator>(big_integer& other);

    bool operator<=(big_integer& other);

    bool operator>=(big_integer& other);

private:
    void update_and_reverse_v();
    void update_v();
};

} // namespace big_num