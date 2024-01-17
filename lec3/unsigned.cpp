#include <iostream>

using namespace std;

int main() {

    // short uses shorter size integer in memory
    short int x;
    cout << "size of short int: " << sizeof(x) << endl;

    x = 0x7FFF;
    cout << "1) " << x << endl;
    x = x + 1;
    cout << "2) " << x << endl;
    
    unsigned short int y = 0x7FFF;
    cout << "3) " << y << endl;
    y = y + 1;
    cout << "4) " << y << endl;

    return 0;
}