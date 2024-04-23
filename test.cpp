#include <iostream>

using namespace std;

class Test {
    private:
        float size = 1.0;
    public:
        float area() {
            return size * size;
        }

        float setSize(float size) {
            size = size;
        }

        float getSize() {
            return size;
        }

};

int main() {
    Test test;
    test.setSize(5);
    cout << test.getSize();

}