#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float f = 0.02;
    float f2 = 0.0000001;
    float f3 = 2.3e-18;
    float f4 = 23e-1;

    cout << "1) f: " << f << endl;
    cout << "2) f2: " << f2 << endl;
    cout << "3) f3: " << f3 << endl;
    cout << "4) f4: " << f4 << endl;

    // scientific from std namespace
    cout << "5) f: " << scientific << f << endl;
    // fixed from std namespace default precision of 6
    cout << "6) f2: " << fixed << f2 << endl;
    // setprecision() from iomanip library
    cout << "7) f2: " << fixed << setprecision(10) << f2 << endl;

    return 0;
}