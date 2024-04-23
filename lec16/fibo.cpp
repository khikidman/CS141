#include <iostream>

using namespace std;

void drawLine (int level, char ch='-') {
    for (int i = 0; i < level; i++) {
        cout << ch;
    }
}

int fibo(int n, int level=0) {
    if (n <= 0) {
        drawLine(level);
        cout << "Base case n = 0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "Base case n = 1" << endl;
        return 1;
    }

    int res;

    drawLine(level);
    cout << "Calling fibo of n = " << n - 1 << endl;
    int part1 = fibo(n-1);
    drawLine(level);
    cout << "returning to fibo of n = " << n << endl;

    drawLine(level);
    int part2 = fibo(n-2);

    drawLine(level);
    cout << "r"
}

int main() {
    int k = 6;
    cout << "n = " << k << " " << fibo(k) << endl;
    return 0;
}