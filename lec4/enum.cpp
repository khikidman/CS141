#include <iostream>

using namespace std;

#define RED 1
#define YELLOW 2
#define GREEN 3

#define TRIANGLE 1
#define RECTANGLE 2
#define PENTAGON 3

enum Color {
    Red=2,
    Yellow,
    Green
};

enum Shape {
    Triangle=3,
    Rectangle,
    Pentagon
};

int main() {
    int color = RED;
    int shape = TRIANGLE;

    int shape2 = RED;

    Color c = Red;
    Shape s = Rectangle;
    Color c3 = Yellow;

    // Color c2 = Rectangle;
    // cout << "1) c2" << c2 << endl;

    cout << "2) " << c << endl;
    cout << "3) " << c3 << endl;

    cout << "4) size: " << sizeof(Color) << endl;

    return 0;
}