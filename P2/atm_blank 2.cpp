#include<iostream>
using namespace std;

//#ifndef checks if PIN1 has not defined before
#ifndef PIN1 
#define PIN1 0
#endif //end of ifndef block 

#ifndef PIN2 
#define PIN2 0
#endif 

#ifndef PIN3 
#define PIN3 0
#endif 

#ifndef PIN4 
#define PIN4 0
#endif 

#ifndef INITIAL_BALANCE
#define INITIAL_BALANCE 100.0
#endif

#ifndef MAX_PIN_TRIAL
#define MAX_PIN_TRIAL 3
#endif

#define BILL10 "$10-Bill"
#define BILL20 "$20-Bill"
#define BILL50 "$50-Bill"



//Messasges to be shown to the user. 
//DO NOT MODIFY THE MESSAGES
#define MSG_WELCOME "Welcome to the ATM!" 
#define MSG_PIN_ACCEPTED "PIN accepted!"
#define MSG_PIN_DENIED "Incorrect PIN!"
#define MSG_INVALID_AMOUNT "Invalid amount!" 
#define MSG_INSUFFICIENT_BALANCE "Insufficient balance!"
#define MSG_REMAINING_ATTEMPTS "Attempts left: " 
#define MSG_ENTER_PIN  "Enter your PIN: "
#define MSG_CONTINUE "Do you want to continue? (y|n)"
#define MSG_CONTINUE_INFO "Please type y for yes or n for no."
#define MSG_CURRENT_BALANCE "Current balance: " 
#define MSG_LOCKED "You have exceeded the maximum number of PIN attempts."
#define MSG_WITHDRAWAL_PROMPT "Enter the amount to withdraw (multiples of 10): "
#define MSG_REMAINING_BALANCE "Remaining Balance: "
#define MSG_WITHRAWING_INFO "Withdrawing: "
#define MSG_ATM_BYE "Thank you for using the ATM!"


int main() {
	return 0;
} 
