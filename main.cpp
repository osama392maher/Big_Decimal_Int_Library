#include<bits/stdc++.h>

using namespace std;

class BigDecimalInt{
private:
    string digits = "";
public:
    // Constructors
    BigDecimalInt(unsigned long long n);
    BigDecimalInt(string s);

    // Print
    friend ostream& operator << (ostream& out, BigDecimalInt n);

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

int main()
{
    BigDecimalInt n(1234);
    cout << n;
}


