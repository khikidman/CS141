#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int max = 2;
    int num_primes = 0;

    cout << "Enter the maximum number: ";
    cin >> max;

    for (int i = 2; i < max; i++) {
        bool divisible = false;
        // i = 5
        // 5/2, 5/3, 5/4
        for (int j = 2; j < i / 2; j++) {
            // cout << i << " " << j << endl;
            if (i % j == 0) {
                divisible = true;
                break;
            }
        }
        if (!divisible) {
            num_primes++;
            cout << setw(4) << i;  
            if (num_primes % 10 == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;

    return 0;
}