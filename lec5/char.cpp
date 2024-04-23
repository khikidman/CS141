#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char ch;
    ch = 'A';
    cout << ch << endl;
    ch = 'a';
    cout << ch << endl;
    ch = 0x4C;
    cout << ch << endl;
    ch = '\t';
    cout << "This" << ch << "is" << endl;


    int b = ch;
    char cCh = 'C';
    char cLow = cCh + 'a' - 'A';

    cout << cLow << endl;

    return 0;

}