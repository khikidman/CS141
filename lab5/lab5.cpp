#include <iostream>

using namespace std;

int main() {
    int largest_num = 0;
    int second_largest = 0;
    int third_largest = 0;
    int total_inputs = 0;

    while (true) {
        int input;
        int temp_num;

        cin >> input;
        if (input >= 0) {
            total_inputs++;
            if (input > third_largest) {
                if (input > second_largest) {
                    if (input > largest_num) {
                        // temp_num = largest_num;
                        third_largest = second_largest;
                        second_largest = largest_num;
                        largest_num = input;
                    } else {
                        third_largest = second_largest;
                        second_largest = input;
                    }
                } else {
                    third_largest = input;
                }
            }
        } else {
            break;
        }
    }
    if (total_inputs >= 1) {
        cout << "Largest number: " << largest_num << endl;
        if (total_inputs >= 2) {
            cout << "Second largest number: " << second_largest << endl;
            if (total_inputs >= 3) {
                cout << "Third largest number: " << third_largest << endl;
            }
        }
    }
    return 0;

    int error;

    switch (error) {
        case 0:
            cout << "No error" << endl;
            break;
        case 1:
            cout << "Exited with error code 1" << endl;
            break;
        // case n:
        // ...
    }

    return error;


}