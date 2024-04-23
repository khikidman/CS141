#include <iostream>

using namespace std;

int main() {
    bool b = true;
    b = false;

    if (b) {
        cout << "b is true" << endl;
    } else {
        cout << "b is false" << endl;
    }

    b = false;
    bool b2 = false;
    bool b3 = false;
    if (b) {
        cout << "b2 is true" << endl;
    } else if (b2) {
        cout << "b is false and b2 is true" << endl;
    } else if (b3) {
        cout << "b is false, b2 is false, b3 is true" << endl;
    } else {
        cout << "b is false, b2 is false, and b3 is false" << endl;
    }

    int x = 128;
    if (x) {
        cout << "A) x is true" << endl;
    } else {
        cout << "B) x is false" << endl;
    }

    int y = -38;
    if (y) {
        cout << "A) y is true" << endl;
    } else {
        cout << "B) y is false" << endl;
    }

    float f = 3.4e-18;
    if (f) {
        cout << "C) f is true" << endl;
    } else {
        cout << "D) f is false" << endl;
    }

    float f2 = 3.4e-48;
    if (f2) {
        cout << "C) f2 is true" << endl;
    } else {
        cout << "D) f2 is false" << endl;
    }

    double d = 3.4e-48;
    if (d) {
        cout << "C) d is true" << endl;
    } else {
        cout << "D) d is false" << endl;
    }

    
    return 0;
}