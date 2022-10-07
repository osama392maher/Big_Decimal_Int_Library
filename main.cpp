#include<bits/stdc++.h>

using namespace std;

class BigDecimalInt{
private:
    bool negative = false;
    string digits = "";
public:
    // Constructors
    BigDecimalInt(unsigned long long n);
    BigDecimalInt(string s);

    // Print
    friend ostream& operator << (ostream& out, BigDecimalInt n);

    //opreations
    friend BigDecimalInt operator +(BigDecimalInt a, BigDecimalInt b);
    bool operator ==(BigDecimalInt a);
    BigDecimalInt   operator= (const BigDecimalInt a);

};

BigDecimalInt::BigDecimalInt(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        digits.push_back(s[i]);
    }
}
BigDecimalInt::BigDecimalInt(unsigned long long n)
{
    while(n)
    {
        digits.push_back((n % 10) + '0');
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
}

ostream& operator << (ostream& out, BigDecimalInt n)
{
    for(int i = 0; i < n.digits.length(); i++)
    {
        out << n.digits[i];
    }
    out << endl;
    return out;
}

BigDecimalInt operator +(BigDecimalInt a, BigDecimalInt b)
{
    BigDecimalInt c(0);
    int carry = 0;
    int n = max(a.digits.length(), b.digits.length());
    while(a.digits.length() != n)
    {
        a.digits.insert(0, "0");
    }
    while(b.digits.length() != n)
    {
        b.digits.insert(0, "0");
    }
    for(int i = n - 1; i >= 0; i--)
    {

        int temp = (a.digits[i] - '0') + (b.digits[i] - '0') + carry;
        if(temp < 10)
        {
            c.digits.push_back(temp + '0');
            carry = 0;
        }
        else
        {
            c.digits.push_back((temp % 10) + '0');
            temp /= 10;
            carry = temp;
        }
    }
    if(carry)
    {
        c.digits.push_back(carry + '0');
    }
    reverse(c.digits.begin(), c.digits.end());
    return c;
}

bool BigDecimalInt :: operator ==(BigDecimalInt a) {

    return (digits==a.digits);
}

BigDecimalInt BigDecimalInt ::operator = (const BigDecimalInt b) {
    
    return b;
}


int main()
{
    BigDecimalInt a(9999);
    BigDecimalInt b(9999);
    BigDecimalInt c = a + b;
    cout << c;
    a.operator==(b);
    BigDecimalInt d=b.operator=(b);
    cout << d;
}

