#include <iostream>
#include <cmath>

using namespace std;

int sequence(int n) {
    long int pow = 1;
    for (int i = 0; i < n; i++) {
        pow *= 10;
    }
    int rem = static_cast<int>(static_cast<long double>(M_PI) * pow) % 10;
    return rem;
}

int main() {
    for (int i = 0; i < 39; i++) {
        cout << "a of " << i << ": " << sequence(i) << endl;
    }
    return 0;
}