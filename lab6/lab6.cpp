#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    float a = 3.0;
    float x = 0.9;
    int n = 5000;

    // Nested for loop
    double v1 = 0.0;
    clock_t start1 = clock();

    for (int i = 0; i <= n; i++) {
        double xi = 1.0;
        for (int j = 0; j < i; j++) {
            xi *= x;
        }
        v1 += xi * a;
    }

    clock_t end1 = clock();

    cout << "Variation 1: " << "Value: " << v1 << " Runtime: " << static_cast<double>(end1 - start1)/CLOCKS_PER_SEC << endl;

    // Pow loop
    double v2 = 0.0;
    clock_t start2 = clock();

    for (int i = 0; i <= n; i++) {
        double xi = pow(x, i);
        v2 += xi * a;
    }

    clock_t end2 = clock();

    cout << "Variation 2: " << "Value: " << v2 << " Runtime: " << static_cast<double>(end2 - start2)/CLOCKS_PER_SEC << endl;


    double v3 = 0.0;
    double xi = 1.0;

    clock_t start3 = clock();

    for (int i = 0; i <= n; i++) {
        v3 += a * xi;
        xi *= x;
    }

    clock_t end3 = clock();

    cout << "Variation 3: " << "Value: " << v3 << " Runtime: " << static_cast<double>(end3 - start3)/CLOCKS_PER_SEC << endl;

    return 0;

}