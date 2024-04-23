//In order to use AI feedback I consent to participate in research study (via surveys) regarding the usefullness of the AI feedback in my progress
//change the value to true to request help from AI 
const bool request_ai_feedback = false; 


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

//Do not change the message variables.
const string critrion_msg_length = "The selected password must be at least eight characters long.";
const string critrion_msg_upper = "The selected password must have at least one uppercase letter.";
const string critrion_msg_lower = "The selected password must have at least one lowercase letter.";
const string critrion_msg_digit = "The selected password must have at least one digit.";
const string critrion_msg_special_chars = "The selected password must have at least one of special characters: [@,!,#,^,&,*,$]";
const string critrion_msg_dictionary = "The selected password cannot contain a dictionary word.";
const string critrion_msg_leaked = "The selected password has been leaked.";

//Use this enum for check the characters of the password
const int CHECKS_NUM = 5;
enum check_names {CHECK_LENGTH, CHECK_UPPER, CHECK_LOWER, CHECK_DIGIT, CHECK_SPECIAL_CHAR};


//This functions reads in string in the file specified by the filename and fill word_dic dictionary. It going to be used to read both leaked passwords and word dictionary.
//Change any call type of parameters at your discretion (call by value or call by refrence); Do not change the name of the function.
int readWordList(string filename, vector<string>& word_dic) {

	ifstream fin(filename);
	
	if(fin.is_open()) {

		string word;
		while (fin >> word) {
			word_dic.push_back(word);
		}
		return 0;
	}

	return -1;	
}


int compare(string word, string query) {

	string word_normalized = "";
	for (char c : word) {
		if (isalnum(c)){
			word_normalized += c;
		}
	}

	for (int i = 0; i < word.length() && i < query.length(); ++i) {

		char wordc = tolower(word[i]);
		char queryc = tolower(query[i]);

		if (wordc < queryc) {
			return -1;
		} else if (wordc > queryc) {
			return 1;
		}

	}

	return 0;
}


//for each rule if the passwords satisfy the rule set the corresponding entry in the checks array to true
void checkPasswordChars(bool checks[CHECKS_NUM], string password) {

	for (int i = 0; i < CHECKS_NUM; ++i) {
		checks[i] = false;
	}

	if (password.length() >= 8)
		checks[CHECK_LENGTH] = true;
	
	for (char c : password) {
		if (isupper(c)){
			checks[CHECK_UPPER] = true;
		} else if (islower(c)) {
			checks[CHECK_LOWER] = true;
		} else if (isdigit(c)) {
			checks[CHECK_DIGIT] = true;
		} else if (c == '@' || c == '!' || c == '#' || c == '^' || c == '&' || c == '*' || c == '$') {
			checks[CHECK_SPECIAL_CHAR] = true;
		}
	}
	
}

//This function checks if the passowrd is among the leaked password provided by password dic
//Change any call type of parameters at your discretion (call by value or call by refrence); Do not change the name of the function.
bool isInLeakedDic(vector<string> password_dic, string password){

	string password_normalized = "";
    for (char c : password) {
        if (isalnum(c)){
        	password_normalized += c;
		}
    }

	int start = 0;
	int end = password_dic.size() - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		string mid_password = password_dic.at(mid);

		int result = compare(mid_password, password_normalized);
		if (result == 0) {
			return true;
		} else if (result < 0) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return false;

}


//This function checks if the password contains a dictionary word provided by english_dic
//Change any call type of parameters at your discretion (call by value or call by refrence); Do not change the name of the function.
bool isInEnglishDic(vector<string> english_dic, string password) {

	string password_normalized = "";
	for (char c : password) {
		password_normalized += tolower(c);
	}
	
	for (int i = 0; i < english_dic.size(); ++i) {

		if (password_normalized.find(english_dic[i]) != string::npos) {
			return true;
		}

	}
	return false;
}



/* do not change the main file */
int main(int argc, char* argv[]) {

	if (argc < 3){
		cout << "Usage: program-name path-to-leaked-password-file path-to-english-word-file" << endl;
		return 1;
	}
	string leaked_password_file = argv[1]; 
	string english_word_file = argv[2]; 
	
	string password;


	vector<string> leaked_password_dic;
	vector<string> english_dic;

	clock_t  start = clock();
	readWordList(leaked_password_file, leaked_password_dic);
	//cout << "leaked password size: " << leaked_password_dic.size() << endl;
	
	readWordList(english_word_file, english_dic);
	//cout << "english word size: " << english_dic.size() << endl;
	
	clock_t stop = clock();

	cout << "Loading data files in " << (double)(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;

	cout << "Enter password: ";
	cin >> password;

	bool checks[CHECKS_NUM];

	checkPasswordChars(checks, password);


	bool failed = false;
	if (!checks[CHECK_LENGTH]) {
		failed = true;
		cout << critrion_msg_length << endl;
	}
	if (!checks[CHECK_UPPER]) {
		failed = true;
		cout << critrion_msg_upper << endl;
	}

	if (!checks[CHECK_LOWER]) {
		failed = true;
		cout << critrion_msg_lower << endl;
	}

	if (!checks[CHECK_DIGIT]) {
		failed = true;
		cout << critrion_msg_digit << endl;
	}

	if (!checks[CHECK_SPECIAL_CHAR]) {
		failed = true;
		cout << critrion_msg_special_chars << endl;
	}

	bool is_leaked = false;
	bool is_english = true;
	if (!failed) {
		start = clock();
		is_english = isInEnglishDic(english_dic, password);
		stop = clock();

		cout << "Checking against dictionary words took " <<  (double)(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;
		if (is_english) {
			cout << critrion_msg_dictionary << endl;
			is_english = true;
		}
		
		start = clock();
		is_leaked = isInLeakedDic(leaked_password_dic, password);
	    	stop = clock();
	    	
		cout << "Checking against leaked passwords took " <<  (double)(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << endl;		
		if (is_leaked) {
			cout << critrion_msg_leaked << endl;
		}

	}
	if (!failed && !is_leaked && !is_english) {
		cout << "Password accepted!" << endl;
	}
	else {
		cout << "Password rejected!" << endl;
	}

	
	return 0;	
}
