#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include "big_integer.h"
#include <algorithm>
#include <math.h>

void check_number(const string& s) {
    int t = 0;
    if (s[t] == '-') {
        t++;
    }
    for (int i = t; i < s.size(); i++) {
        if (s[i] < '0' || '9' < s[i]) {
            cout << "Error! It is not a number!";
            exit(0);
        }
    }
}

void check_operation(const string& s) {
    if (!(s == "+" || s == "-" || s == ">" || s == "<" || s == ">=" || s == "<=" || s == "==" || s == "+=" ||
    s == "-=" || s == "*" || s == "*=" || s == "/" || s == "/=" || s == "%" || s == "%=")) {
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

int main() {
    string s_a, s_op, s_b;
    s_out("number a");
    cin >> s_a;
    check_number(s_a);
    s_out("operation ('+', '+=', '-', '-=', '*', '*=', '/', '/=', '%', '%=', '<', '>', '<=', '>=', '==')");
    cin >> s_op;
    check_operation(s_op);
    s_out("number b");
    cin >> s_b;
    check_number(s_b);

    big_num::big_integer a(s_a);
    big_num::big_integer b(s_b);

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
        big_num::big_integer c = a + b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "-") {
        big_num::big_integer c = a - b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "+=") {
        a += b;
        cout << a.make_string() << "\n";
    }
    else if (s_op == "-=") {
        a -= b;
        cout << a.make_string() << "\n";
    }
    else if (s_op == "*") {
        big_num::big_integer c = a * b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "*=") {
        a *= b;
        cout << a.make_string() << "\n";
    }
    else if (s_op == "/") {
        big_num::big_integer c = a / b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "/=") {
        a /= b;
        cout << a.make_string() << "\n";
    }
    else if (s_op == "%") {
        big_num::big_integer c = a % b;
        cout << c.make_string() << "\n";
    }
    else if (s_op == "%=") {
        a %= b;
        cout << a.make_string() << "\n";
    }
    return 0;
}