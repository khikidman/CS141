//Your name: 
//Lab section:


#include <iostream>
#include <iomanip>

using namespace std;

//create a dynamic 2d-array and fill it using the provided patterns
//n is the number of rows
//m is the number of cols
char** generateSpiralMatrix(int n, int m) {
	//Complete Me
    int left = -1;
    int right = 1;
    int top = 1;
    int bottom = 1;

    char** arr = new char* [n];

    for (int i = 0; i < n; ++i) {
        arr[i] = new char[m];
        for (int j = 0; j < m; ++j) {
            arr[i][j] = '-';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == m - right && j > left) {
                arr[i][j] = '.';
                right++;
                left++;
            } else if (j == left && j < m - right) {
                arr[i][j] = '.';
            } else if (j > m - right) {
                arr[i][j] = '|';
            } else if (j < left + 1) {
                arr[i][j] = '|';
            }
        }
    }

    right = 1;
    left = 0;

    for (int i = n - 1; i >= n/2; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if ((j == m - right && j > left) || (j == left && j < m - right)) {
                arr[i][j] = '.';
            }
            else if (j > left && j < m - right) {
                arr[i][j] = '-';
            }
        }
        right++;
        left++;
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }

	return arr;
}

//delete the matrix
void deleteMatrix(char** matrix, int n) {
	for (int i = 0; i < n; ++i) {
        delete(matrix[i]);
    }
}

void drawMatrix(int n, int m) {
    char** spiralMatrix = generateSpiralMatrix(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << spiralMatrix[i][j];
        }
        cout << endl;
    }
    deleteMatrix(spiralMatrix, n);
}


//Do not modify the main function.
int main() {
   cout << "10x6:" << endl;
   drawMatrix(10,6);
   cout << endl;
   cout << endl; 
   cout << "8x16:" << endl;
   drawMatrix(8,16);
   cout << endl;
   cout << endl;
   cout << "12x4:" << endl;
   drawMatrix(12, 4);
   return 0;
}

