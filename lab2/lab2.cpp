/**********************************
 * Lab 2 for UIC CS 141
 * Author: Pedram Rooshenas
 * *******************************/



#include <iostream>
#include <climits>

using namespace std;

int main() {
	//declare an 16-bit integer named b16x
	int16_t b16x; //1 point
	
	//lets check the size of b16x variable:
	cout << "Size of b16x is " << sizeof(int16_t) << endl; //change this statement approperiately (1 point)	
	
	//find the binary value of 135 and assign it to b16x
	//the assigned value must be a binary literal 
 	b16x = 0b0000000010000111; //2 points
	
	//declare another 16-bit integer named h16x
	int16_t h16x;
	
	//find the hexadecimal value of 135 
	//Hint: every 4-bit of your previous binary literal equals to one hexadecimal digit
	//For example, 0b01011110 equals to 0x5E (0101->5, 1110->E);
	//Assign the hexadecimal literal of 135 to h16x;
	h16x = 0x87; // 2 points
	
	//Let's check your work
	cout << "Binary: " << b16x << endl; //change this statement approperiately
	//I will give you the answer for this one: cout << "Binary: " << b16x << endl;
	
	cout << "Hexadecimal: " << h16x << endl; //change this statement approperiately
	//if the values are not equal, you have an error in your calculation.
	
	//delcare another 16-bit integer variable named nb16x
	int16_t nb16x;
	
	//now find the 2's complement binary representation of 135 and assign it to nb16x
	nb16x = 0b1111111101111001; // 2 points
	
	//let's check the output
	cout << "The value of nb16x: " << nb16x << endl; //change this statement approperiately
	//The printed value must be -135 for a correct calculation
	
	
	//now declare a 32-bit integer variable named b32x
	//and assign the 2'complement binary representation from previous step to it
	int32_t b32x = 0b1111111101111001; //2 points
	
	//What do you expect to see? a negative value or a positive value?
	//! I expect a positive value since the MSB will now be 0 by default for the 32-bit integer unless otherwise modified
	//lets check
	cout << "The value of b32x: " << (int)b32x << endl; //change this statement approperiately
	return 0;
	
}
