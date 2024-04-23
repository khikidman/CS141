/*
 * Student Author: 
 * Lab Section: 
 */


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


//The class for our complex number which has real and imaginary part
class ComplexNumber {
	public:
		int real;
		int imaginary;
};


//calcuate the squared magnitude of the given complex number
int calcSquaredMagnitude(ComplexNumber complex_number) {
	//complete me
	return (complex_number.real * complex_number.real) + (complex_number.imaginary * complex_number.imaginary);
}


//Compare two complex numbers if complex number a is smaller than complex number b then compare returns -1 otherwise returns 1
//We use squared magnitude to compare two complex numbers. If the numbers have the same magnitude then we break the tie using real part first, and if the real parts are equal we use imaginary part. 
//Example: (1-1i) < (1+1i)
int compare(ComplexNumber complex_number_a, ComplexNumber complex_number_b) {
	//complete me
	int magnitude_a = calcSquaredMagnitude(complex_number_a);
	int magnitude_b = calcSquaredMagnitude(complex_number_b);

	if ( magnitude_a < magnitude_b )
		return -1;
	else if ( magnitude_a > magnitude_b )
		return 1;
	else {
		if (complex_number_a.real < complex_number_b.real)
			return -1;
		else if (complex_number_a.real > complex_number_b.real)
			return 1;
		else {
			if (complex_number_a.imaginary < complex_number_b.imaginary)
				return -1;
			else if (complex_number_a.imaginary > complex_number_b.imaginary)
				return 1;
		}
	}
	return 1;
}

//Swap function swaps two complex numbers.
//Here swap function receives the pointer to two complex numbers and swap their values.
//Note: you can use -> to access the member of the class using its pointer
void swap(ComplexNumber* a, ComplexNumber* b) {
	int tmp_real = b->real;
	int tmp_imaginary = b->imaginary;
	b->real = a->real;
	b->imaginary = a->imaginary;
	a->real = tmp_real;
	a->imaginary = tmp_imaginary;
}


//Sort the vector of complex number inplace.
//Start and end are the indices to the first and the last element of the vector, respectively
void selectionSort(vector<ComplexNumber>& complex_numbers, int start, int end) {
	while (start < end) {
		int min = start;
		for (int i = start + 1; i <= end; ++i) {
			if (compare(complex_numbers[i], complex_numbers[min]) < 0) {
				min = i;
			}
		}
		swap(complex_numbers[start], complex_numbers[min]);
		start++;
	}
}

//Print the complex numbers in the format (a+bi) or (a-bi) for positive and negative imaginary part, respectively
//Each complex number is separate by space.
//Sample output: (1-1i) (1+1i) (0+2i)
void print_vec(vector<ComplexNumber> complex_numbers, int start, int end) {
	for (int i=start; i <= end; i++ ) {

		if (complex_numbers.at(i).imaginary < 0) {

			cout << "(" << complex_numbers.at(i).real << "-" << -complex_numbers.at(i).imaginary << "i)" << " ";
		} else {
			cout << "(" << complex_numbers.at(i).real << "+" << complex_numbers.at(i).imaginary << "i)" << " ";
				
		}
	}	
	cout << endl;

}

//DO NOT MODIFY THE MAIN FUNCTION
int main() {
	vector<ComplexNumber> numbers;

	vector<int> real_vec = {-1,4,1,2,4,3,-1,-2,5,2,-1,1,0,2,1,-1,-1};
	vector<int> imaginary_vec = {1,-2,-1,-3,2,1,3,4,-1,-2,0,1,5,4,-2,4,-1};

	for (int i=0; i < real_vec.size(); i++) {
		ComplexNumber c;
		c.real = real_vec.at(i);
		c.imaginary = imaginary_vec.at(i);
		numbers.push_back(c);
	}	

	selectionSort(numbers, 0, numbers.size()-1); 
	print_vec(numbers,0, numbers.size()-1);
	return 0;	

}
