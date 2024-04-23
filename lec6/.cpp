#include <iostream>

using namespace std;

int main() {
    int x = 1;
    x++;
    ++x;

    int y = x;
    y = x + 1;

    y = x++;
    cout << "1) x: " << x << " y: " << y << endl;

    x = 1;
    y = ++x;
    cout << "2) x: " << x << " y: " << y << endl;

    x = 1;
    y = x++ + ++x * 2;
    cout << "3) x: " << x << " y: " << y << endl;


    x = 0;
    y = 1;

    if (x && y) {
        cout << "True branch\n";
    } else {
        cout << "False branch\n";
    }

    x = 2;
    y = 0;
    if (y != 0) {
        if (x / y > 5) {
            cout << "A) True branch\n" << x / y << endl;
        } else {
            cout << "B) False branch\n" << "Error" << endl;
        }
        cout << "x / y" << x / y << endl;
    } else {
        cout << "Error Y is zero";
    }

    if (y != 0 && x / y > 5) {
        cout << "A) True branch\n" << x / y << endl;
    } else {
        cout << "B) False branch\n" << "Error" << endl;
    }
    cout << "x / y" << x / y << endl;

    x = 1;
    y = 0;
    if (y-- && x++) {
        cout << "A) True branch\n";
    } else {
        cout << "B) False branch\n";
    }
    cout << "x / y" << x / y << endl;

    float f;
    f = -110 * 2e-120;
    cout << f << endl;
    return 0;
}