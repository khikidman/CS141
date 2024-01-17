/*
Second lecture of CS 141
*/

#include <iostream>
#include <climits>

using namespace std;

int main() {
    int a; // declaration
    a = 10;

    int b = 10; // initialization

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    int int_var;
    long long_var;
    float float_var;
    double double_var;

    cout << "int size: " << sizeof(int) << endl;
    cout << "long size: " << sizeof(long) << endl;
    cout << "float size: " << sizeof(float) << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "char size: " << sizeof(char) << endl;

    int_var = INT_MAX;
    int_var += 1; // int overflow
    cout << "int_var: " << int_var << endl;

    cout << "exp1: " << 3/4 << endl;
    cout << "exp2: " << 3./4. << endl;

    double x, y;
    x = 10.0;
    y = x * 3/4;
    cout << "exp3: " << y << endl;

    return 0;
}