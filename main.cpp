#include <iostream>
#include <string>
#include "bigIntHeader.h"
using namespace std;

//_______________________________________________________

int main() {
    string n1, n2;
    while (cin >> n1 >> n2) {
        BigDecimalInt x(n1), y(n2);
        cout << x + y << endl;
        cout << x - y << endl;
        cout << y - x << endl;
    }
}
