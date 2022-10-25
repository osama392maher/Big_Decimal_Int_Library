#include<bits/stdc++.h>

using namespace std;

class BigDecimalInt {

private:
    int bigIntSign = 0;
    string digits = "";

public:

    // Constructors
    BigDecimalInt(long long n);

    BigDecimalInt(string s);

    // Print
    friend ostream &operator<<(ostream &out, BigDecimalInt n);

    //Assigning
    BigDecimalInt &operator=(const BigDecimalInt &b);

    //opreations
    friend BigDecimalInt operator+(BigDecimalInt a, BigDecimalInt b);

    friend BigDecimalInt operator-(BigDecimalInt a, BigDecimalInt b);

    //comparsion
    bool operator==(const BigDecimalInt &a);

    bool operator<(BigDecimalInt &a);

    bool operator>(BigDecimalInt &a);

    //Other functions
    int size() const;

    int sign() const;
};

//_______________________________________________________
// Constructors

BigDecimalInt::BigDecimalInt(string s) {

    if (s[0] != '-')
        bigIntSign = 1;
    else
        bigIntSign = -1;

    int st = !isdigit(s[0]);
    for (int i = st; i < s.size(); ++i) {
        // find the first digit which isn't leading zero
        if (s[i] != '0' || i == s.size() - 1) {
            digits = s.substr(i, s.size() - i);
            break;
        }
    }

    if (digits == "0")
        bigIntSign = 0;
}

BigDecimalInt::BigDecimalInt(long long n) {

    if (n == 0)
        bigIntSign = 0;
    else if (n < 0)
        bigIntSign = -1;
    else
        bigIntSign = 1;

    n = abs(n);
    while (n) {
        digits.push_back((n % 10) + '0');
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
}

//_______________________________________________________
// print

ostream &operator<<(ostream &out, BigDecimalInt n) {
    if (n.bigIntSign == -1)
        out << '-';
    for (int i = 0; i < n.digits.length(); i++) {
        out << n.digits[i];
    }
    return out;
}

//_______________________________________________________
// operations

BigDecimalInt operator+(BigDecimalInt a, BigDecimalInt b) {
    BigDecimalInt c(0);
    int carry = 0;
    // ADD NEGATIVE NUMBERS
    if (a.bigIntSign == -1 && b.bigIntSign == -1) {
        c.bigIntSign = -1;
        a.bigIntSign = 1;
        b.bigIntSign = 1;
        c = a + b;
        return c;
    }
    // add positive number to negative number
    if (a.bigIntSign == -1) {
        a.bigIntSign = 1;
        c = b - a;
        return c;
    }
    // add negative number to positive number
    if (b.bigIntSign == -1) {
        b.bigIntSign = 1;
        c = a - b;
        return c;
    }
    if (a.size() < b.size()) {
        a.digits = string(b.size() - a.size(), '0') + a.digits;
    } else {
        b.digits = string(a.size() - b.size(), '0') + b.digits;
    }

    int n = a.size();
    for (int i = n - 1; i >= 0; i--) {

        int temp = (a.digits[i] - '0') + (b.digits[i] - '0') + carry;
        if (temp < 10) {
            c.digits.push_back(temp + '0');
            carry = 0;
        } else {
            c.digits.push_back((temp % 10) + '0');
            temp /= 10;
            carry = temp;
        }
    }
    if (carry) {
        c.digits.push_back(carry + '0');
    }
    reverse(c.digits.begin(), c.digits.end());
    return c;
}


string subtract(string &a, string &b, int idx, bool srch_brrw) { // 1500 - 1300
    if (idx == -1)
        return "";

    if (srch_brrw) {
        if (a[idx] > '0') {
            a[idx]--;
            srch_brrw = false;
        } else {
            a[idx] = '9';
        }
    }

    if (a[idx] >= b[idx]) {
        return subtract(a, b, idx - 1, srch_brrw) + char(a[idx] - b[idx] + '0');
    } else {
        return subtract(a, b, idx - 1, true) + char(10 + a[idx] - b[idx] + '0');
    }
}

BigDecimalInt operator-(BigDecimalInt a, BigDecimalInt b) {
    BigDecimalInt res("");

    if (a < b)
        res.bigIntSign = -1;
    else if (a > b)
        res.bigIntSign = 1;
    else
        res.bigIntSign = 0;

    // make bigInt (a) is the absolute_bigger int
    if (a.size() < b.size() || (a.size() == b.size() && a.digits < b.digits)) {
        swap(a, b);
    }

    b.digits = string(a.size() - b.size(), '0') + b.digits;
    res.digits = subtract(a.digits, b.digits, a.size() - 1, false);

    return res;
}

//_______________________________________________________
// comparison

bool BigDecimalInt::operator==(const BigDecimalInt &a) {

    return (digits == a.digits && bigIntSign == a.bigIntSign);
}

bool BigDecimalInt::operator<(BigDecimalInt &a) {
    if (bigIntSign < a.bigIntSign)
        return true;
    if (bigIntSign > a.bigIntSign || bigIntSign == 0)
        return false;

    // now both nums has same sign, and both aren't zero
    if (bigIntSign == 1) {
        // both nums are positive
        if ((*this).size() < a.size() || ((*this).size() == a.size() && digits < a.digits))
            return true;
        else
            return false;
    } else {
        // both nums are negative
        if ((*this).size() > a.size() || ((*this).size() == a.size() && digits > a.digits))
            return true;
        else
            return false;
    }
}

bool BigDecimalInt::operator>(BigDecimalInt &a) {
    return a < (*this);
}

//_______________________________________________________
// assing

BigDecimalInt &BigDecimalInt::operator=(const BigDecimalInt &b) {
    digits = b.digits;
    return *this;
}

//_______________________________________________________
// other functions

int BigDecimalInt::size() const {
    return digits.size();
}

int BigDecimalInt::sign() const {

    return bigIntSign;
}

//_______________________________________________________

int main() {
    BigDecimalInt a("123456789012345678901234567890");
    BigDecimalInt b("123456789012345678901234567890");
    BigDecimalInt c("965499929492005200425255425255");
    BigDecimalInt d("479621491764978164891694816948");
    BigDecimalInt e("471929104180431040140140140140");
    BigDecimalInt f("748999238183813881388138813881");
    BigDecimalInt g("243221312312312312312312312312");
    BigDecimalInt h("313142598598598598598598598598");
    BigDecimalInt i("63284137127313");
    BigDecimalInt x = a + b;
    BigDecimalInt y = c - d;
    BigDecimalInt z = e + (f + h);
    BigDecimalInt w = g - (x + a);
    BigDecimalInt v = i - (i + i);
    BigDecimalInt t = (a + b) - (c - d);
    BigDecimalInt s = (e + (f + h)) - (g - (x + a));
    BigDecimalInt r = (i - (i + i)) - (i - (i + i));
    BigDecimalInt q = (a + b) - (c - d) + (e + (f + h)) - (g - (x + a)) + (i - (i + i)) - (i - (i + i));
    BigDecimalInt p =
            (a + b) - (c - d) + (e + (f + h)) - (g - (x + a)) + (i - (i + i)) - (i - (i + i)) + (a + b) - (c - d) +
            (e + (f + h)) - (g - (x + a)) + (i - (i + i)) - (i - (i + i));
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << w << endl;
    cout << v << endl;
    cout << t << endl;
    cout << s << endl;
    cout << r << endl;
    cout << q << endl;
    cout << p << endl;
    return 0;
}
