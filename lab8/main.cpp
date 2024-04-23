//In this lab we try to read a list of numbers from input and then work with this numbers such as finding their sum, but unlike the previous approach we want to keep all the numbers in the memory rather than only keeping the running sum


#include <iostream>
// using namespace std;


//Here we assume the maximum number of values are 20 so we keep a constant variable that indicate that size and we declare 20 variables.


const int MAX_SIZE = 20;

//The reserved memory for the list of numbers
int a0;
int a1;
int a2;
int a3;
int a4;
int a5;
int a6;
int a7;
int a8;
int a9;
int a10;
int a11;
int a12;
int a13;
int a14;
int a15;
int a16;
int a17;
int a18;
int a19;



//Indicates how many variables from the reserved memory we have used so far.
int size;


//Our goal is to access all the variables via the pointer to the first variable using pointer arithmetics.
//For example, the variable a1 is accessible via the pointer of a0: *(&a0 + 1)
//Since pointers are variables, we can pass them to the functions as well.
//This function receive the starting point of our memory and an index (assume the subscript of the memory variables is the index) and returns the value of it.
//For example, to get the value of a10 we call get_value_at(&a0, 10);
int get_value_at(int* start, int index) {
   //complete me [2 points]
    start += index;
    return *start;
}


//This function sets the value of a variable in the reserved memory via the pointer to the start of the memory and the index of the variable.
//For example, to set the value of a10 to 5, we call set_value_at(&a0, 10, 5);
void set_value_at(int* start, int index, int value) {
   //complete me [2 points]
    int *address = start + index;
    *address = value;
}

//This functions set all of the reserved memory to zero (varible a0 thourgh a19)
void reset() {
   for (int i=0; i < MAX_SIZE; i++) {
      set_value_at(&a0, i, 0);
   }  
   size = 0;
}


//This function returns the sum of the first n values in the memory, where n is the size of used memory by our list of numbers.
//For example, if we only used our memory to store a list of 15 numbers then to find the sum of the numbers we call sum(&a0, 15);
int sum(int* start, int size) {
   //complete me [2 points]
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += get_value_at(start, i);
    }
    return sum;
}



//When we implement programs like this it is easy to make mistakes so we should test our functions carefully.
//Here is a test for get_value_at. The test returns -1 if fails and 0 if it is successful.
int test_get_value_at() {
    //to test if get_value_at works correctly, we have to assign values to resereved memory directly (without using set_value_at) to isolate the get_values_at from the rest of the program. In this way an error in set_value_at does not propagate to get_value_at.
    a0 = 1;
    a1 = 3;
    a2 = 2;
    //we have to set the size as well
    size = 3;
   
    //now we check the function to see if it returns the expected values
    bool check1 = get_value_at(&a0, 0) == 1;
    bool check2 = get_value_at(&a0, 1) == 3;
    bool check3 = get_value_at(&a0, 2) == 2;


    if (check1 && check2 && check3) {
        return 0;
    } else {
        return -1;
    }  
}


//The test for set_value_at
int test_set_value_at() {
   //complete me [2 points] (the test must check at least three cases, see test_get_value_at for an example)
    a0 = 1;
    a1 = 8;
    a2 = 4;


    set_value_at(&a0, 0, 7);
    set_value_at(&a0, 1, 13);
    set_value_at(&a0, 2, 5);

    bool check1 = get_value_at(&a0, 0) == 7;
    bool check2 = get_value_at(&a0, 1) == 13;
    bool check3 = get_value_at(&a0, 2) == 5;

    if (check1 && check2 && check3) {
        return 0;
    } else {
        return -1;
    }  
}


//The test for sum
int test_sum() {
   //comeplte me [2 points] (the test must check at least three cases, see test_get_value_at for an example.
   //remember to reset the memory before each test case.
   //you can design the tests based on the given sample outputs
    reset();
    a0 = 1;
    a1 = 2;
    a2 = 5;
    a3 = 3;

    bool check1 = sum(&a0, 3) == 8;

    reset();
    a0 = 6;
    a1 = 3;
    a2 = 1;
    a3 = 3;

    bool check2 = sum(&a0, 3) == 10;

    reset();
    a0 = 4;
    a1 = 1;
    a2 = 2;
    a3 = 6;

    bool check3 = sum(&a0, 3) == 7;

    if (check1 && check2 && check3) {
        return 0;
    } else {
        return -1;
    }  
    
    return -1;
}

//This function runs of all of tests that we have
void run_all_tests() {
   if (!test_get_value_at()) {
      std::cout << "Test 1 - Get value passed" << std::endl;
   } else {
      std::cout << "Test 1 - Get value failed" << std::endl;
   }

   if (!test_set_value_at()) {
      std::cout << "Test 2 - Set value passed" << std::endl;
   } else {
      std::cout << "Test 2 - Set value failed" << std::endl;
   }
   if (!test_sum()) {
      std::cout << "Test 3 - Sum passed" << std::endl;
   } else {
      std::cout << "Test 3 - Sum failed" << std::endl;
   }
}


//This function is the usage of reserved memory to store a list number and work with it.
//Here, we read a list of numbers from input. To indicate the end of the list, the user enters -1.
//For example, user enters 10 1 3 -1 to enter a list of three numbers.
//Our list has a variable size from 0 to MAX_SIZE, so we have to change the variable size as we read values from the input.
//When we read a new value we should store it at the first availble location, which would be at index = size. For example, the begining size if zero and the first variable goes to a0. For the second value the size is 1 to the value goes to a1, and so on so forth.
void read_and_sum() {
   reset();
   int x;
   size = 0;
   std::cin >> x;
   while (x > 0 && size < MAX_SIZE){
      set_value_at(&a0, size, x);    
      std::cin >> x;
      size++;
   }  
   std::cout << "Sum: " << sum(&a0, size) << std::endl;
}

int main () {
   run_all_tests();
   
   //since we have tests everything we can use our memory to store a list numbers that we read from input and output their sums should work without any trouble!
   //uncomment the next line only if your code passed all the tests.
   read_and_sum();
   return 0;
     
}