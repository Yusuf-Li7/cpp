#include <string>
#include "big_integer.h"
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <random>
#include <future>
#include <cmath>

namespace big_num {

big_integer::big_integer(const std::string &number) {
    make_number(number);
}

big_integer::big_integer(unsigned long long int &number) {
    std::string str;
    while (number > 0) {
        str += (char)(number % 10 + '0');
        number /= 10;
    }
    reverse(str.begin(), str.end());
    make_number(str);
}

big_integer::big_integer(signed long long int &number) {
    std::string str;
    if (number < 0) {
        str = "-";
        number = -number;
    }
    while (number > 0) {
        str += (char)(number % 10 + '0');
        number /= 10;
    }
    reverse(str.begin(), str.end());
    make_number(str);
}

big_integer::big_integer() {

}

void big_integer::make_number(std::string s) {
    int i = 0;
    if (!s.empty() && s[i] == '-') {
        sing = true;
        i++;
    }
    while (s[i] == 0) {
        i++;
    }
    for (i; i < s.size(); i++) {
        v.push_back((int) (s[i] - '0'));
    }
}

std::string big_integer::make_string() {
    string s;
    bool fl = false;
    if (sing)
        s += "-";

    for (int i: v) {
        if (i != 0)
            fl = true;
        if (!fl)
            continue;
        s += to_string(i);
    }
    return s;
}

void big_integer::update_v() {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > 9) {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    if (v[v.size() - 1] > 9) {
        v.push_back(v[v.size() - 1] / 10);
        v[v.size() - 2] %= 10;
    }

    int i = (int)v.size() - 1;
    while (v[i] == 0) {
        v.pop_back();
        i--;
    }
}

void big_integer::update_and_reverse_v() {
    update_v();
    reverse(v.begin(), v.end());
}

/*
std::ostream &big_integer::operator<<(ostream &ostream, const big_integer &number) {
    std::string ans = "";
    if (number.sing)
        ans = "-";
    for (auto i : number.v)
        ans += i;

    return ostream;
}
*/

bool big_integer::operator==(big_integer& other) {
    if (sing != other.sing || v.size() != other.v.size())
        return false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != other.v[i])
            return false;
    }
    return true;
}

bool big_integer::operator>(big_integer& other) {
    if (*this == other || (sing && !other.sing))
        return false;
    if (!sing && other.sing)
        return true;
    if (!sing && !other.sing && v.size() > other.v.size())
        return true;
    if (sing && other.sing && v.size() < other.v.size())
        return true;

    if (sing && other.sing && v.size() == other.v.size()) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < other.v[i])
                return true;
        }
    }

    if (!sing && !other.sing && v.size() == other.v.size()) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > other.v[i])
                return true;
        }
    }

    return false;
}

bool big_integer::operator<(big_integer& other) {
    if (*this == other || *this > other)
        return false;
    return true;
}

bool big_integer::operator>=(big_integer& other) {
    if (*this == other || *this > other)
        return true;
    return false;
}

bool big_integer::operator<=(big_integer& other) {
    if (*this == other || *this < other)
        return true;
    return false;
}

big_integer big_integer::operator+(big_integer& other){
    if (sing && !other.sing) {
        sing = false;
        return other - *this;
    }
    else if (!sing && other.sing) {
        other.sing = false;
        return *this - other;
    }

    if (sing && other.sing) {
        sing = false;
        other.sing = false;
        big_integer c = *this + other;
        c.sing = true;
        return c;
    }

    big_integer c;
    c.v.resize(max(v.size(), other.v.size()));

    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());

    for (int i = 0; i < max(v.size(), other.v.size()); i++) {
        if (i < v.size() && i < other.v.size())
            c.v[i] = v[i] + other.v[i];
        if (i < v.size() && i >= other.v.size())
            c.v[i] = v[i];
        if (i >= v.size() && i < other.v.size())
            c.v[i] = other.v[i];
    }
    c.update_and_reverse_v();
    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());

    return c;
    /*
    int i = v.size() - 1;
    int j = other.v.size() - 1;
    c.v.resize(max(v.size(), other.v.size()));
    int k = c.v.size() - 1;
    while (i >= 0 && j >= 0 && k >= 0) {
        c.v[k] = v[i] + other.v[j] + c.carry;
        c.carry = 0;
        if (c.v[k] >= 10) {
            c.carry = c.v[k] / 10;
            c.v[k] %= 10;
        }
        i--;
        j--;
        k--;
    }
    while (i >= 0 && k >= 0) {
        c.v[k] = v[i] + c.carry;
        c.carry = 0;
        if (c.v[k] >= 10) {
            c.carry = c.v[k] / 10;
            c.v[k] %= 10;
        }
        i--;
        k--;
    }
    while (j >= 0 && k >= 0) {
        c.v[k] = other.v[j] + c.carry;
        c.carry = 0;
        if (c.v[k] >= 10) {
            c.carry = c.v[k] / 10;
            c.v[k] %= 10;
        }
        i--;
        k--;
    }
    */
}



big_integer big_integer::operator-(big_integer& other){
    if (!sing && other.sing) {
        other.sing = false;
        return *this + other;
    }
    if (sing && !other.sing) {
        sing = false;
        big_integer c = *this + other;
        c.sing = true;
        return c;
    }
    if (sing && other.sing) {
        sing = false;
        other.sing = false;
        big_integer c = other - *this;
        return c;
    }
    if (*this < other) {
        big_integer c = other - *this;
        c.sing = true;
        return c;
    }

    big_integer c;

    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());
    c.v.resize(max(v.size(), other.v.size()));
    uint8_t crr = 0; // в уме
    for (int i = 0; i < max(v.size(), other.v.size()); i++) {
        if (i < v.size() && i < other.v.size()) {
            if(v[i] - other.v[i] - crr >= 0) {
                c.v[i] = v[i] - other.v[i] - crr;
                crr = 0;
            } else {
                c.v[i] = 10 + v[i] - other.v[i] - crr;
                crr = 1;
            }
        }
        if (i < v.size() && i >= other.v.size()) {
            if(v[i] - crr >= 0) {
                c.v[i] = v[i] - crr;
                crr = 0;
            } else {  // вроде не актуальное else
                c.v[i] = 10 + v[i] - crr;
                crr = 1;
            }
        }
    }

    c.update_and_reverse_v();
    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());

    return c;
    /*
    int i = v.size() - 1;
    int j = other.v.size() - 1;
    c.v.resize(max(v.size(), other.v.size()));
    int k = c.v.size() - 1;
    while (i >= 0 && j >= 0 && k >= 0) {
        if (v[i] + c.carry >= other.v[j]) {
            c.v[k] = v[i] + c.carry - other.v[j];
            c.carry = 0;
        }
        else {
            c.v[k] = v[i] + 10 + c.carry - other.v[j];
            c.carry = -1;
        }
        i--;
        j--;
        k--;
    }
    while (i >= 0 && k >= 0) {
        c.v[k] = v[i] + c.carry;
        c.carry = 0;
        i--;
        k--;
    }
    while (j >= 0 && k >= 0) {
        if (c.carry >= other.v[j]) {
            c.v[k] = c.carry - other.v[j];
            c.carry = 0;
        }
        else {
            c.v[k] = 10 + c.carry - other.v[j];
            c.carry = -1;
        }
        j--;
        k--;
    }
    */
}

big_integer big_integer::operator+=(big_integer &other) {
    return *this = (*this + other);
}

big_integer big_integer::operator-=(big_integer &other) {
    return *this = (*this - other);
}

big_integer big_integer::operator*(big_integer& other){
    big_integer c;
    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < other.v.size(); j++) {
            if (c.v.size() <= i + j)
                c.v.push_back(0);
            c.v[i + j] += v[i] * other.v[j];
        }
    }

    c.update_and_reverse_v();

    reverse(v.begin(), v.end());
    reverse(other.v.begin(), other.v.end());

    if (sing != other.sing)
        c.sing = true;
    return c;
}

big_integer big_integer::operator*=(big_integer &other) {
    return *this = (*this * other);
}

big_integer big_integer::operator/(big_integer &other) {
    big_integer c(0);
    if (*this < other)
        return c;

    return c;
}

} // namespace big_num
