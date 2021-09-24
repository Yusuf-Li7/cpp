#include <iostream>
#include <vector>
#include <string>

using namespace std;

class big_integer{
public:
    vector<int> v;
    bool sing = false;
    int carry = 0;
    void make_number(string s) {
        vector<int> new_v;
        int i = 0;
        if (!s.empty() && s[i] == '-') {
            sing = true;
            i++;
        }
        for (i; i < s.size(); i++) {
            v.push_back((int)(s[i] - '0'));
        }
    }
    string make_string() {
        string s;
        bool fl = false;
        if (sing)
            s += "-";
        if (carry != 0) {
            cout << carry;
            fl = true;
        }
        for (int i : v) {
            if (i != 0)
                fl = true;
            if (!fl)
                continue;
            s += to_string(i);
        }
        return s;
    }
};