#include <iostream>
#include <string>
#include <vector>
#include "big_integer.cpp"
#include <algorithm>

using namespace std;

void check_number(const string& s) {
    int i = 0;
    if (s[i] == '-') {
        i++;
    }
    for (i; i < s.size(); i++) {
        if (s[i] < '0' || '9' < s[i]) {
            cout << "Error! It is not a number!";
            exit(0);
        }
    }
}

void check_operation(const string& s) {
    if (!(s == "+" || s == "-" || s == ">" || s == "<" || s == ">=" || s == "<=" || s == "==")) {
        cout << "Error! It is not a correct operation!";
        exit(0);
    }
}

void s_out(const string& s) {
    cout << "Enter " << s << "\n";
}
void out_ans(bool fl) {
    if (fl)
        cout << "Yes\n";
    else
        cout << "No\n";
}

bool operator ==(const big_integer& a, const big_integer& b) {
    if (a.sing != b.sing || a.v.size() != b.v.size())
        return false;
    for (int i = 0; i < a.v.size(); i++) {
        if (a.v[i] != b.v[i])
            return false;
    }
    return true;
}

bool operator >(const big_integer& a, const big_integer& b) {
    if (a == b || (a.sing && !b.sing))
        return false;
    if (!a.sing && b.sing)
        return true;
    if (!a.sing && !b.sing && a.v.size() > b.v.size())
        return true;
    if (a.sing && b.sing && a.v.size() < b.v.size())
        return true;

    if (a.sing && b.sing && a.v.size() == b.v.size()) {
        for (int i = 0; i < a.v.size(); i++) {
            if (a.v[i] < b.v[i])
                return true;
        }
    }

    if (!a.sing && !b.sing && a.v.size() == b.v.size()) {
        for (int i = 0; i < a.v.size(); i++) {
            if (a.v[i] > b.v[i])
                return true;
        }
    }

    return false;
}

bool operator <(const big_integer& a, const big_integer& b) {
    if (a == b || a > b)
        return false;
    return true;
}

bool operator >=(const big_integer& a, const big_integer& b) {
    if (a == b || a > b)
        return true;
    return false;
}

bool operator <=(const big_integer& a, const big_integer& b) {
    if (a == b || a < b)
        return true;
    return false;
}

big_integer operator +(big_integer& a, big_integer& b) {
    if (a.sing && b.sing) {
        a.sing = false;
        b.sing = false;
        big_integer c = a + b;
        c.sing = true;
        return c;
    }
    big_integer c;
    int i = a.v.size() - 1;
    int j = b.v.size() - 1;
    c.v.resize(max(a.v.size(), b.v.size()));
    int k = c.v.size() - 1;
    while (i >= 0 && j >= 0 && k >= 0) {
        c.v[k] = a.v[i] + b.v[j] + c.carry;
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
        c.v[k] = a.v[i] + c.carry;
        c.carry = 0;
        if (c.v[k] >= 10) {
            c.carry = c.v[k] / 10;
            c.v[k] %= 10;
        }
        i--;
        k--;
    }
    while (j >= 0 && k >= 0) {
        c.v[k] = b.v[j] + c.carry;
        c.carry = 0;
        if (c.v[k] >= 10) {
            c.carry = c.v[k] / 10;
            c.v[k] %= 10;
        }
        i--;
        k--;
    }
    return c;
}


big_integer operator -(big_integer& a, big_integer& b) {
    if (!a.sing && b.sing) {
        return a + b;
    }
    if (a.sing && !b.sing) {
        a.sing = false;
        big_integer c = a + b;
        c.sing = true;
        return c;
    }
    if (a.sing && b.sing) {
        a.sing = false;
        b.sing = false;
        big_integer c = b - a;
        return c;
    }

    if (a < b) {
        big_integer c = b - a;
        c.sing = true;
        return c;
    }

    big_integer c;
    int i = a.v.size() - 1;
    int j = b.v.size() - 1;
    c.v.resize(max(a.v.size(), b.v.size()));
    int k = c.v.size() - 1;
    while (i >= 0 && j >= 0 && k >= 0) {
        if (a.v[i] + c.carry >= b.v[j]) {
            c.v[k] = a.v[i] + c.carry - b.v[j];
            c.carry = 0;
        }
        else {
            c.v[k] = a.v[i] + 10 + c.carry - b.v[j];
            c.carry = -1;
        }
        i--;
        j--;
        k--;
    }
    while (i >= 0 && k >= 0) {
        c.v[k] = a.v[i] + c.carry;
        c.carry = 0;
        i--;
        k--;
    }
    while (j >= 0 && k >= 0) {
        if (c.carry >= b.v[j]) {
            c.v[k] = c.carry - b.v[j];
            c.carry = 0;
        }
        else {
            c.v[k] = 10 + c.carry - b.v[j];
            c.carry = -1;
        }
        j--;
        k--;
    }
    return c;
}

int main() {
    string s_a, s_op, s_b;
    s_out("number a");
    cin >> s_a;
    check_number(s_a);
    s_out("operation ('+', '-', '<', '>', '<=', '>=', '==')");
    cin >> s_op;
    check_operation(s_op);
    s_out("number b");
    cin >> s_b;
    check_number(s_b);

    big_integer a;
    a.make_number(s_a);
    big_integer b;
    b.make_number(s_b);

    if (s_op == "==") {
        bool fl = a == b;
        out_ans(fl);
    }
    else if (s_op == ">") {
        bool fl = a > b;
        out_ans(fl);
    }
    else if (s_op == "<") {
        bool fl = a < b;
        out_ans(fl);
    }
    else if (s_op == ">=") {
        bool fl = a >= b;
        out_ans(fl);
    }
    else if (s_op == "<=") {
        bool fl = a <= b;
        out_ans(fl);
    }
    else if (s_op == "+") {
        big_integer c;
        if (a.sing && !b.sing) {
            a.sing = false;
            c = b - a;
        }
        else if (!a.sing && b.sing) {
            b.sing = false;
            c = a - b;
        }
        else
            c = a + b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "-") {
        big_integer c = a - b;
        cout << c.make_string() << "\n";
    }
}