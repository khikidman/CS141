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
#define MSG_WITHDRAWING_INFO "Withdrawing: "
#define MSG_ATM_BYE "Thank you for using the ATM!"


int main() {
	int attempts = 0;
	int pin;
	double balance = INITIAL_BALANCE;

	cout << MSG_WELCOME << endl;

	while (attempts < MAX_PIN_TRIAL) {
		cout << MSG_ENTER_PIN;
		int pin1, pin2, pin3, pin4;
		cin >> pin1 >> pin2 >> pin3 >> pin4;
		if (pin1 == PIN1 && pin2 == PIN2 && pin3 == PIN3 && pin4 == PIN4) {
			cout << MSG_PIN_ACCEPTED << endl;
			cout << MSG_CURRENT_BALANCE << INITIAL_BALANCE << endl;
			break;
		} else {
			cout << MSG_PIN_DENIED << endl;
			attempts++;
			cout << MSG_REMAINING_ATTEMPTS << MAX_PIN_TRIAL - attempts << endl;
			if (attempts == MAX_PIN_TRIAL) {
				cout << MSG_LOCKED << endl;
				cout << MSG_ATM_BYE << endl;
				return 0;
			} else {
				cout << MSG_CONTINUE << endl;
				char response;
				while (response != 'y' && response != 'n') {
					if (response) {
						cout << MSG_CONTINUE_INFO << endl;
					}
					cin >> response;
				}
				if (response == 'y') {
					continue;
				} else if (response == 'n'){
					cout << MSG_ATM_BYE << endl;
					return 0;
				}
			}
		}
	}

	char response = 'y';

	while (response == 'y') {
		cout << MSG_WITHDRAWAL_PROMPT << endl;
		int withdraw_amt;
		cin >> withdraw_amt;
		if (withdraw_amt % 10 != 0) {
			cout << MSG_INVALID_AMOUNT << endl;
			cout << MSG_CONTINUE << endl;
			cin >> response;
			continue;
		}
		if (withdraw_amt > balance) {
			cout << MSG_INSUFFICIENT_BALANCE << endl;
			cout << MSG_CONTINUE << endl;
			cin >> response;
			continue;
		}

		balance -= withdraw_amt;
		int ct_50, ct_20, ct_10;
		
		ct_50 = static_cast<int>(withdraw_amt) / 50;
		ct_20 = (static_cast<int>(withdraw_amt) % 50) / 20;
		ct_10 = ((static_cast<int>(withdraw_amt) % 50) % 20) / 10;

		cout << MSG_WITHDRAWING_INFO << ct_50 << " " << BILL50 << " " << ct_20 << " " << BILL20 << " " << ct_10 << " " << BILL10 << endl;
		
		cout << MSG_REMAINING_BALANCE << balance << endl;
		cout << MSG_CONTINUE << endl;

		cin >> response;
		while (response != 'y' && response != 'n') {
			if (response) {
				cout << MSG_CONTINUE_INFO << endl;
			}
			cin >> response;
		}
	}

	cout << MSG_ATM_BYE << endl;
	
	return 0;

} 
