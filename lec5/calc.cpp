#include <iostream>

using namespace std;

int main () {
    // int x, y;
    // cout << "Enter a number: ";
    // cin >> x;
    // cout << "Enter another number: ";
    // cin >> y;
    // cout << "You entered: " << x << ", " << y << endl;

    float x, y;
    char operation;

    cout << "Enter operation";
    cin >> operation;
    cout << "Enter two operands";
    cin >> x;
    cin >> y;

    float result = 0.0;
    int error = 0;
    if (operation == '+') {
        result = x + y;
    } else if (operation == '-') {
        result = x - y;
    } else {
        cout << "Operation not recognized" << endl;
        error = 1;
    }

    if (!error) {
        cout << "result: " << result << endl;
    }

    return 0;
}