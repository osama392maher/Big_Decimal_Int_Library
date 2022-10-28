#ifndef BIG_INT_ASSIGNMENT_BIGINTHEADER_H
#define BIG_INT_ASSIGNMENT_BIGINTHEADER_H

#include<iostream>

class BigDecimalInt {
private:
    int bigIntSign = 0;
    std::string digits = "";

public:

    // Constructors
    BigDecimalInt(long long n);

    BigDecimalInt(std::string s);

    // Print
    friend std::ostream &operator<<(std::ostream &out, BigDecimalInt n);

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

#endif //BIG_INT_ASSIGNMENT_BIGINTHEADER_H
