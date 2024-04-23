#include <iostream>
using std::cout;
using std::cin;

int f(int* v, int* x, int i) {
    x[i]++;
    return v[i];
}

void main() {
    int a[5] = {1, 2, 3, 2, 1};
    int b[5] = {0, 0, 0, 0, 0};

    int max = -1;

    for (int i = 0; i < 5; i++) {
        if (f(a, b, i) > max) {
            max = f(a, b, i);
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << b[i] << ' ';
    }
}