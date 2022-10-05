#include<bits/stdc++.h>

using namespace std;

class BigInt{
        private:
            string digits = "";

        public:

            // Constructors
            BigInt(unsigned long long n = 0)
            {
                while(n)
                {
                    digits.push_back(n % 10);
                    n /= 10;
                }
            }
    
            BigInt(string s)
            {
                for(int i = 0; i < s.length(); i++)
                {
                    if(isdigit(s[i]))
                    {
                        digits.push_back(s[i] - '0');
                    }
                }
            }

            // Print
            friend ostream& operator<<(ostream& out, BigInt n)
            {
                for (int i = 0; i < n.digits.size(); i++)
                {
                    out << n.digits[i];
                }
                out << endl;
                return out;
            }

    };

int main()
{
    BigInt n(1234);
    cout << n;
}
