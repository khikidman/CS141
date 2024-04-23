/***********************
 * Student Author: Khi Kidman
 * Lab Section: 3pm
 ************************/


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//We are encrypting charactures with ASCII code between 32 and 126
const int code_length = 126 - 32;


//EncryptText receives a string and array as key and return the encrypted text
//In the encrypted text we replace every char in text according to key
//for example if key[0] = 'A'; then in the encrypted text replaces space (code 32) with characted 'A';
//or if key['A'-32] = 'b' then in the encrypted text 'A' is replaced by 'b'
string encryptText(string text, char key[]) {
	//complete me
	string output = text;
	for (int i = 0; i < text.size(); ++i) {
		output[i] = key[text[i] - 32];
	}
	return output;
}

//genKey randomly generates the key map and its reverse key;
//key is used to encrypt the text and reverse key is used to decrypt the text
//If key[0] = 'A' then rev_key['A'-32] = 0 + 32
//If key['A' - 32] = 'b' then rev_key['b'-32] = 'A';
void genKey(char* key, char* rev_key) {
	//complete me
	for (int i = 0; i < code_length; ++i) {
		key[i] = 0;
		rev_key[i] = 0;
	}

	for (int i = 0; i < code_length; ++i) {
		while(true) {
			int c = rand() % code_length;
			if (rev_key[c] == 0){
				key[i] = c + 32;
				rev_key[c] = i + 32;
				break;
			}
		}
	}
}


int main() {
	srand(time(0));
	
	//Create the arrays for key and its reverse
	char* key = new char[code_length];
	char* rev_key = new char[code_length];

	//Generate the random key and its reverse
	genKey(key, rev_key);

	string plain_text = "I love C++ programming";
	string encrypted_text = encryptText(plain_text, key);
   	cout << "Encrypted text: " << encrypted_text << endl;
	
	if (!plain_text.compare(encrypted_text)) {
		cout << "Plain text and encrypted text cannot be equal!" << endl;  
	}

	string decrypted_text = encryptText(encrypted_text, rev_key);
	cout << "Decrypted text: " << decrypted_text << endl;

	if (plain_text.compare(decrypted_text) ) {
		cout << "Error! Decrypted text is not equal to the plain text!" << endl;
	}

	//Generate another key and reverse key
	char* key2 = new char[code_length];
	char* rev_key2 = new char[code_length];
	genKey(key2, rev_key2);

	
	string encrypted_text2 = encryptText(plain_text, key2);
	cout << "Encrypted text with key2: " << encrypted_text2 << endl;

	if (!encrypted_text.compare(encrypted_text2)) {
		cout << "Error! Encrypted texts with different keys cannot be equal!" << endl; 
	}

	string decrypted_text2 = encryptText(encrypted_text2, rev_key2);
	cout << "Decrypted text with key2: " << decrypted_text2 << endl;
	

	delete[] key;
	delete[] key2;
	delete[] rev_key2;
	delete[] rev_key;

    return 0;
}
