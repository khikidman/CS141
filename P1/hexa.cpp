#include <iostream>
#include <iomanip>

using namespace std;


int main () {
    int x;
    char c0, c1, c2, c3, c4, c5;
    int i2, i3, i4, i5;
    cin >> c0 >> c1 >> c2 >> c3 >> c4 >> c5;
    int error = 0;

    // Check for hex literal notation
    if (!(c0 == '0' && c1 == 'x')) {
        cout << "Hexadecimal literal must start with 0x" << endl;
        error = 1;
    }

    // Check validity of hex digits
    if (c2 >= 48 && c2 <= 57) {
        i2 = c2 - 48;
    } else if (c2 >= 65 && c2 <= 70) {
        i2 = (c2 - 65) + 10;
    } else {
        error = 1;
    }
    if (c3 >= 48 && c3 <= 57) {
        i3 = c3 - 48;
    } else if (c3 >= 65 && c3 <= 70) {
        i3 = (c3 - 65) + 10;
    } else {
        error = 1;
    }
    if (c4 >= 48 && c4 <= 57) {
        i4 = c4 - 48;
    } else if (c4 >= 65 && c4 <= 70) {
        i4 = (c4 - 65) + 10;
    } else {
        error = 1;
    }
    if (c5 >= 48 && c5 <= 57) {
        i5 = c5 - 48;
    } else if (c5 >= 65 && c5 <= 70) {
        i5 = (c5 - 65) + 10;
    } else {
        error = 1;
    }



    x = (i2 * 16 * 16 * 16) + (i3 * 16 * 16) + (i4 * 16) + i5;
    if (!error) {
        cout << "Decimal value: " << x << endl;
    } else {
        cout << "Hexadecimal digits must be in [0-9 or A-F]" << endl;
    }

    return 0;
    
}