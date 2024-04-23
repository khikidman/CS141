#include <iostream>

using namespace std;

int main() {
    int x, y;
    char operation;

    cout << "Enter operation: ";
    cin >> operation;
    cout << "Enter two operands: ";
    cin >> x;
    cin >> y;

    float result = 0.0;
    int error = 0;
    if (operation == '+') {
        result = x + y;
    } else if (operation == '-') {
        result = x - y;
    } else if (operation == '/') {
        result = x / y;
    } else if (operation == '*') {
        result = x * y;
    } else if (operation == '%') {
        result = x % y;
    } else {
        cout << "I don't recognize the operation" << endl;
        error = 1;
    }

    if (!error) {
        cout << x << " " << operation << " " << y << " = " << result << endl;
    }

    return 0;
}