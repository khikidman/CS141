
#include <iostream>
using namespace std;

//This function prints a polynomial represented using its coefficient array, coeffs, and its degree arrays. 
//Size indicates the number of terms in the polynomial
void print_polynomial(double coeffs[], int degrees[], int size ) {
	for (int i = 0; i < size; i++) {
		cout << coeffs[i] << "*X^" << degrees[i];
		if (i < size - 1) {
			cout << " + ";
		} else {
			cout << endl;
		}
	}
}	

//resulf_coeffs: the coefficients of output polynomial
//result_degrees: the degrees of output polynomial
//result_size: the number of terms in the output polynomial 
//coeff_A: the coeffients of polynomial A
//degrees_A: the degrees of polynomial A
//size_A: the number of terms in polynomial A
//coeff_B: the coeffients of polynomial B
//degrees_B: the degrees of polynomial B
//size_B: the number of terms in polynomial B
void add(double result_coeffs[],int result_degrees[], int& result_size, double coeffs_A[], int degrees_A[], int size_A, double coeffs_B[], int degrees_B[], int size_B){
	
	// get result_size by finding biggest degree of A and B lists
	result_size = 0;

	for (int i = 0; i < size_A; ++i) {
		result_size++;
	}

	for (int i = 0; i < size_B; ++i) {
		bool match = false;
		for (int j = 0; j < size_A; ++j) {
			if (degrees_B[i] == degrees_A[j]){
				match = true;
				break;
			}
		}
		if (match == false) {
			result_size++;
		}
	}

	for (int i = 0; i < size_A; ++i) {
		result_degrees[degrees_A[i]] = degrees_A[i];
	}
	for (int i = 0; i < size_B; ++i) {
		result_degrees[degrees_B[i]] = degrees_B[i];
	}

	// loop through degrees of result_degrees
	for (int i = 0; i < result_size; ++i) {
		cout << result_degrees[i] << endl;
		// loop through degrees of A
		for (int j = 0; j < size_A; ++j) {
			// check if A degree is equal to result_degrees degree
			if (result_degrees[i] == degrees_A[j]) {
				// set coefficient of result_degrees at correct degree to A coefficient
				result_coeffs[i] += coeffs_A[j];
			}
		}

		// loop through degrees of B
		for (int j = 0; j < size_B; ++j) {
			// check if B degree is equal to result_degrees degree
			if (result_degrees[i] == degrees_B[j]) {
				// set coefficient of result_degrees at correct degree to A coefficient 
				result_coeffs[result_degrees[i]] += coeffs_B[j];
			}
		}
	}
}	


void test1() {
	double coeffs_A[4] = {0.1, 0.2, 0.3, 0.4};
	int degrees_A[4] = {0,2,5,6};

	double coeffs_B[2] = {0.2, 0.4};
	int degrees_B[2] = {1, 5};
	
	int degrees_r[6];
	double coeffs_r[6];
	int size_r = 0;

	cout << "Sample output 1:" << endl;
	cout << "Polynomial A:" << endl;	
	print_polynomial(coeffs_A, degrees_A, 4);
	cout << "Polynomial B:" << endl;
	print_polynomial(coeffs_B, degrees_B, 2);
	cout << "Output polynomial: " << endl;
	add(coeffs_r, degrees_r, size_r, coeffs_A, degrees_A, 4, coeffs_B, degrees_B, 2);
	print_polynomial(coeffs_r, degrees_r, size_r);
	cout << "-----------------" << endl;

}

void test2() {
	double coeffs_A[4] = {0.1, 0.2, 0.3, 0.4};
	int degrees_A[4] = {0,2,5,6};

	double coeffs_B[4] = {0.2, 0.4, 0.1, -1.0};
	int degrees_B[4] = {1, 3, 5, 6};
	
	int degrees_r[8];
	double coeffs_r[8];
	int size_r = 0;

	cout << "Sample output 2:" << endl;
	cout << "Polynomial A:" << endl;	
	print_polynomial(coeffs_A, degrees_A, 4);
	cout << "Polynomial B:" << endl;
	print_polynomial(coeffs_B, degrees_B, 4);
	cout << "Output polynomial: " << endl;
	add(coeffs_r, degrees_r, size_r, coeffs_A, degrees_A, 4, coeffs_B, degrees_B, 4);
	print_polynomial(coeffs_r, degrees_r, size_r);
	cout << "-----------------" << endl;
}

void test3() {
	double coeffs_A[1] = {0.3};
	int degrees_A[1] = {2};

	double coeffs_B[4] = {0.2, 0.4, 0.1, -1.0};
	int degrees_B[4] = {1, 3, 5, 6};
	
	int degrees_r[8];
	double coeffs_r[8];
	int size_r = 0;

	cout << "Sample output 3:" << endl;
	cout << "Polynomial A:" << endl;	
	print_polynomial(coeffs_A, degrees_A, 1);
	cout << "Polynomial B:" << endl;
	print_polynomial(coeffs_B, degrees_B, 4);
	cout << "Output polynomial: " << endl;
	add(coeffs_r, degrees_r, size_r, coeffs_A, degrees_A, 1, coeffs_B, degrees_B, 4);
	print_polynomial(coeffs_r, degrees_r, size_r);
	cout << "-----------------" << endl;
}


int main() {
	test1();
	test2();
	test3();
	return 0;
}
