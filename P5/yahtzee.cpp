
/*************************
 * Student Author Name: Khi Kidman
 * Lab Section: 3pm
 * ***********************/

/*
 * The AI Feedback Generator is part of a research study investigating the effectiveness of AI-powered teaching assistance in computer science education. 
 * By requesting AI feedback, you consent to participate in this study. Participation involves submitting a survey to evaluate the feedback you received and its impact on your progress. The surveys will be anonymized before being released publicly for future research. 
 * If you choose not to submit the surveys, it means that you opt out of the study and will not be able to receive AI feedback for your future coursework.
 * To request AI feedback uncomment the following line.
 */

//#define REQUEST_AI_FEEDBACK

//To receive AI feedback, DO NOT implement the class methods inside the class definition. 


#include <string>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <iomanip>

using namespace std;



//#################################################################################################



class Dice{
	private:
		int value;
	
	public:

		//Randomly assigns a value between from 1 to 6 to the dice.
		void roll();
		int reveal() {return value;}

		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value) {this->value = value;}

};

void Dice::roll() {
	this->value = rand() % 6 + 1;
}

//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
	public:

		//Display the value of the five dice
		void show();	
		void play();
		Dice* getDice(int diceNum) {return dice[diceNum];};
		
		//selection is the string of dice numbers that the player wants to keep.
		//For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
		void setSelection(string selection);	

		Hand();	
	
	private:
		Dice* dice[5];
		bool selectedDiceIndices[5] = {false};
};

void Hand::show() {
	cout << "Hand: ";
	for (int i = 0; i < HAND_SIZE; ++i) {
		cout << this->getDice(i)->reveal() << " ";
	}
	cout << endl;
}

void Hand::play() {
	for (int i = 0; i < HAND_SIZE; ++i) {
		if (selectedDiceIndices[i] == false) {
			dice[i]->roll();
		}
	}
}

void Hand::setSelection(string selection) {
	
	for (int i = 0; i < HAND_SIZE; ++i) {
		if (selection.find(to_string(i + 1)) != string::npos) {
			selectedDiceIndices[i] = true;
		} else {
			selectedDiceIndices[i] = false;
		}
	}
}

Hand::Hand() {
	for (int i = 0; i < HAND_SIZE; ++i) {
		dice[i] = new Dice();
		dice[i]->roll();
	}
}

//######################################################################


//List of rows in the board
const int ONES = 0;
const int TWOS = 1;
const int THREES = 2;
const int FOURS = 3;
const int FIVES = 4;
const int SIXES = 5;
const int THREE_OF_KIND = 6;
const int FOUR_OF_KIND = 7;
const int FULL_HOUSE = 8;
const int SMALL_STRAIGHT = 9;
const int LARGE_STRAIGHT = 10;
const int CHANCE = 11;
const int YAHTZEE = 12;

const int BOARD_SIZE=13; 

class Game {

	public:

		//calcScore returns a score of a hand (5 dice) for given row in the board. 
		//Note the rows are indexed from zero. 
		//For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
		int calcScore(Hand* hand, int row); 
		
		
		//Display the board
		void show();
		
		//Set upper section row to value
		void setUpperSection(int row, int value) {
			upperSection[row] = value;
		};

		//Return upper section value at row
		int getUpperSection(int row) {
			return upperSection[row];
		};
		
		//Set lower section row to value
		void setLowerSection(int row, int value) {
			lowerSection[row] = value;
		};

		//Return lower section value at row
		int getLowerSection(int row) {
			return lowerSection[row];
		};

		//Returns the score of the upper part of the board
		int getUpperScore();
		
		//Returns the score of the upper part of the board
		int getLowerScore();
	

		//Returns the bonus points
		int getBonusScore();

		//Returns the total score
		int getTotalScore();

		//Play a hand based on the selected row
		void play(Hand* hand, int row);

		
		//Check to see if a row has been played or not (returns true if a row has been played)
		bool isPlayed(int row);
		
		//Check to see if all rows haven been played or not (returns true if all rows have been played)
		bool isFinished();


	private:
		int upperSection[6] = {0};
		int lowerSection[7] = {0};
		bool board[BOARD_SIZE] = {false};
};

int Game::calcScore(Hand* hand, int row) {
	int score = 0;
	switch (row) {
		case ONES: 
		case TWOS:
		case THREES:
		case FOURS:
		case FIVES:
		case SIXES: {
			for (int i = 0; i < HAND_SIZE; ++i) {
				if (hand->getDice(i)->reveal() == row + 1) {
					score += row + 1;
				}
			}
			break;
		}
		case THREE_OF_KIND: {
			int counts[6] = {0};
			for (int i = 0; i < HAND_SIZE; ++i) {
				counts[hand->getDice(i)->reveal() - 1]++;
			}
			bool hasThree = false;
			for (int i = 0; i < 6; ++i) {
				if (counts[i] >= 3) {
					hasThree = true;
				}
			}

			if (hasThree) {
				for (int i = 0; i < HAND_SIZE; ++i) {
					score += hand->getDice(i)->reveal();
				}
			}
			break;
		}
		case FOUR_OF_KIND: {
			int counts[6] = {0};
			for (int i = 0; i < HAND_SIZE; ++i) {
				counts[hand->getDice(i)->reveal() - 1]++;
			}
			bool hasFour = false;
			for (int i = 0; i < 6; ++i) {
				if (counts[i] >= 4) {
					hasFour = true;
				}
			}

			if (hasFour) {
				for (int i = 0; i < HAND_SIZE; ++i) {
					score += hand->getDice(i)->reveal();
				}
			}
			break;
		}
		case CHANCE: {
			for (int i = 0; i < HAND_SIZE; ++i) {
				score += hand->getDice(i)->reveal();
			}
			break;
		}
		case FULL_HOUSE: {
			int counts[6] = {0};
			for (int i = 0; i < HAND_SIZE; ++i) {
				counts[hand->getDice(i)->reveal() - 1]++;
			}
			bool hasThree = false;
			bool hasTwo = false;
			for (int i = 0; i < 6; ++i) {
				if (counts[i] == 3)
					hasThree = true;
				else if (counts[i] == 2)
					hasTwo = true;
			}
			if (hasThree && hasTwo) {
				score = 25;
			}
			break;
		}
		case SMALL_STRAIGHT: {

			int nums[6] = {0};

			for (int i = 0; i < HAND_SIZE; ++i) {
				nums[hand->getDice(i)->reveal() - 1]++;
			}

			bool sequenceFound = false;
			for (int i = 0; i < 3; ++i) {
				sequenceFound = true;
				for (int j = i; j < i + 4; ++j) {
					if (nums[j] == 0) {
						sequenceFound = false;
						break;
					}
				}
				if (sequenceFound) {
					score = 30;
					break;
				}
			}

			break;
		}
		case LARGE_STRAIGHT: {
			int nums[6] = {0};

			for (int i = 0; i < HAND_SIZE; ++i) {
				nums[hand->getDice(i)->reveal() - 1]++;
			}

			for (int i = 0; i < 2; ++i) {
				bool sequenceFound = true;
				for (int j = i; j < i + 5; ++j) {
					if (nums[j] == 0) {
						sequenceFound = false;
						break;
					}
				}
				if (sequenceFound) {
					score = 40;
					break;
				}
			}

			break;
		}
		case YAHTZEE: {
			int value = hand->getDice(0)->reveal();
			bool yahtzee = true;
			for (int i = 1; i < HAND_SIZE; ++i) {
				if (hand->getDice(i)->reveal() != value) {
					yahtzee = false;
					break;
				}
			}
			if (yahtzee) {
				score = 50;
			}
			break;
		}
	}
	return score;
};

void Game::show() {
	cout << "1.  " << "Ones:              " << getUpperSection(ONES) << endl;
	cout << "2.  " << "Twos:              " << getUpperSection(TWOS) << endl;
	cout << "3.  " << "Threes:            " << getUpperSection(THREES) << endl;
	cout << "4.  " << "Fours:             " << getUpperSection(FOURS) << endl;
	cout << "5.  " << "Fives:             " << getUpperSection(FIVES) << endl;
	cout << "6.  " << "Sixes:             " << getUpperSection(SIXES) << endl;
	cout << "    " << "Sum:               " << getUpperScore() << endl;
	cout << "    " << "Bonus:             " << getBonusScore() << endl;
	cout << "7.  " << "Three of a kind:   " << getLowerSection(THREE_OF_KIND-6) << endl;
	cout << "8.  " << "Four of a kind:    " << getLowerSection(FOUR_OF_KIND-6) << endl;
	cout << "9.  " << "Full house:        " << getLowerSection(FULL_HOUSE-6) << endl;
	cout << "10. " << "Small straight:    " << getLowerSection(SMALL_STRAIGHT-6) << endl;
	cout << "11. " << "Large straight:    " << getLowerSection(LARGE_STRAIGHT-6) << endl;
	cout << "12. " << "Chance:            " << getLowerSection(CHANCE-6) << endl;
	cout << "13. " << "Yahtzee:           " << getLowerSection(YAHTZEE-6) << endl;
	cout << "    " << "Total:             " << getTotalScore() << endl;
};

int Game::getUpperScore() {
	int score = 0;
	for (int i = ONES; i <= SIXES; ++i) {
		score += getUpperSection(i);
	}
	return score;
};

int Game::getLowerScore() {
	int score = 0;
	for (int i = THREE_OF_KIND - THREE_OF_KIND; i <= YAHTZEE - THREE_OF_KIND; ++i) {
		score += getLowerSection(i);
	}
	return score;
};

int Game::getBonusScore() {
	int upperSum = getUpperScore();
	if (upperSum >= 63) {
		return 35;
	} else {
		return 0;
	}
};

int Game::getTotalScore() {
	return getUpperScore() + getLowerScore() + getBonusScore();
};

void Game::play(Hand* hand, int row) {
	if (!isPlayed(row)) {
		if (row <= SIXES) {
			setUpperSection(row, calcScore(hand, row));
		} else if (row >= THREE_OF_KIND) {
			setLowerSection(row - THREE_OF_KIND, calcScore(hand, row));
		}

		board[row] = true;
		hand->play();
	} else {
		cout << "Row " << row << " has already been played." << endl;
	}
};

bool Game::isPlayed(int row) {
	if (board[row] == true) {
		return true;
	} else {
		return false;
	}
};

bool Game::isFinished() {
	for (bool b : board) {
		if (!b) {
			return false;
		}
	}
	return true;
}

//#######################################################################################

//The run function is the main loop of your program
void run() {
	srand(time(0));

	int roll_attempts = 3;

	Game* game = new Game();

	while (!game->isFinished()) {
		Hand* hand = new Hand();

		game->show();

		for (int i = 1; i < roll_attempts; ++i) {

			hand->show();
			cout << "Keep Dice (s to stop rolling): ";

			string selection;
			cin >> selection;

			if (selection == "s") {
				break;
			}

			hand->setSelection(selection);
			hand->play();

		}

		hand->show();

		cout << "Select a combination to play: ";
		int row;
		cin >> row;

		game->play(hand, row - 1);

		delete hand;
	}
}


//For these types of programs there exists many combinations that you might have missed. 
//The best way to check them all is to write test cases for your program. 
//Here you are given with an example of checking large straight. You can design your own test cases for different parts.

void test_case() {
	Game game;
	Hand* hand = new Hand();
	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check1 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
		check1 = false;
	}
	if (check1) {
		cout << "check 1 passed\n"; 
	}

	hand->getDice(0)->setValue(2);
	hand->getDice(1)->setValue(6);
	hand->getDice(2)->setValue(4);
	hand->getDice(3)->setValue(3);
	hand->getDice(4)->setValue(5);
	
	bool check2 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
		check2 = false;
	}

	if (check2) {
		cout << "check 2 passed\n"; 
	}

	hand->getDice(0)->setValue(3);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(5);
	hand->getDice(3)->setValue(6);
	hand->getDice(4)->setValue(3);

	bool check3 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
		check3 = false;
	}

	if (check3) {
		cout << "check 3 passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(6);

	bool check4 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
		check4 = false;
	}
	cout << "Check 4 value: " << game.calcScore(hand, LARGE_STRAIGHT) << endl;

	if (check4) {
		cout << "check 4 passed\n"; 
	}


}

// THE AUTOGRADER WILL REPLACE THE MAIN FUNCTION. 
// DO NOT ADD ANY LOGIC OF YOUR PROGRAM HERE.
int main() {
	
	run();
	//test_case();
	return 0;
}
