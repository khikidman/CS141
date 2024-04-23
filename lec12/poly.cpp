#include <iostream>

using namespace std;

int main() {
    float coeff = 0.0f;
    float x = 0.0f;
    float x_pow = 1.0;
    int degree = 0;
    float partial_sum = 0.0f;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    cout << "Enter the evaluation point: ";
    cin >> x;
    cout << "Enter " << degree + 1 << " coefficient(s): ";

    for (int n=0; n <= degree; n++) {
        cin >> coeff;

        partial_sum += coeff * x_pow;
        x_pow = x_pow * x;
    }

    cout << "The value is: " << partial_sum << endl;
    return 0;
}