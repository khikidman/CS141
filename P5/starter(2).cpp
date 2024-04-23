
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
		void roll() {this->value = rand() % 6 + 1;}

		int reveal() {return value;}

		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value) {this->value = value;}

};


//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
	public:

		//Display the value of the five dice
		void show() {
			cout << "Hand: ";
			for (int i = 0; i < HAND_SIZE; ++i) {
				cout << this->getDice(i);
			}
			cout << endl;
		}

		void play() {
			for (int i = 0; i < HAND_SIZE; ++i) {
				dice[i]->roll();
			}
		}

		Dice* getDice(int diceNum) {
			return dice[diceNum];
		}
		
		//selection is the string of dice numbers that the player wants to keep.
		//For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
		void setSelection(string selection) {
			for (int i = 0; i < HAND_SIZE; ++i) {
				if (selection.find(to_string(i + 1)) == string::npos) {
					dice[i]->roll();
				}
			}
		}

		Hand() {
			for (int i = 0; i < HAND_SIZE; ++i) {
				dice[i] = new Dice();
			}
		}
	
	private:
		Dice* dice[5];
};



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
		int upperSection[6] = {0};
		int lowerSection[7] = {0};
		int board[BOARD_SIZE] = {false};
		//calcScore returns a score of a hand (5 dice) for given row in the board. 
		//Note the rows are indexed from zero. 
		//For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
		int calcScore(Hand* hand, int row) {
			int score = 0;
			switch (row) {
				case ONES:
				case TWOS:
				case THREES:
				case FOURS:
				case FIVES:
				case SIXES:
					for (int i = 0; i < HAND_SIZE; ++i) {
						if (hand->getDice(i)->reveal() == row + 1) {
							score += row + 1;
						}
					}
					upperSection[row] = score;
					break;
				case THREE_OF_KIND:
				case FOUR_OF_KIND:
				case CHANCE:
					for (int i = 0; i < HAND_SIZE; ++i) {
						score += hand->getDice(i)->reveal();
					}
					lowerSection[row] = score;
					break;
				case FULL_HOUSE:
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
						// lowerSection[FULL_HOUSE - 6] = score;
					}
					break;
				case SMALL_STRAIGHT:
					bool sequence = false;
					for (int i = 1; i <= 3; ++i) {
						if (hand->getDice(0)->reveal() == i && hand->getDice(1)->reveal() == i + 1 && hand->getDice(2)->reveal() == i + 2 && hand->getDice(3)->reveal() == i + 3) {
							sequence = true;
							break;
						}
					}
					if (sequence) {
						score = 30;
						// lowerSection[SMALL_STRAIGHT - 6] = score;
					}
					break;
				case LARGE_STRAIGHT:
					bool sequence = false;
					for (int i = 1; i <= 2; ++i) {
						if (hand->getDice(0)->reveal() == i && hand->getDice(1)->reveal() == i + 1 && hand->getDice(2)->reveal() == i + 2 && hand->getDice(3)->reveal() == i + 3 && hand->getDice(4)->reveal() == i + 4) {
							sequence = true;
							break;
						}
					}
					if (sequence) {
						score = 40;
						// lowerSection[LARGE_STRAIGHT - 6] = score;
					}
					break;
				case YAHTZEE:
					int value = hand->getDice(0)->reveal();
					bool yahtzee = true;
					for (int i = 1; i < HAND_SIZE; ++i) {
						if (hand->getDice(i)->reveal() != value) {
							yahtzee = false;
							break;
						}
					}
					if (yahtzee) {
						// if (lowerSection[YAHTZEE - 6] >= 50) {
						// 	score = 100;
						// 	lowerSection[YAHTZEE - 6] += score;
						// 	break;
						// }
						score = 50;
						lowerSection[YAHTZEE - 6] = score;
					}
					break;
			}
			board[row] = true;
			return score;
		}
		
		
		//Display the board
		void show() {
			cout << setw(20) << "1." << "Ones:" << calcScore(hand, ONES) << endl;
			cout << setw(20) << "2." << "Twos:" << calcScore(hand, TWOS) << endl;
			cout << setw(20) << "3." << "Threes:" << calcScore(hand, THREES) << endl;
			cout << setw(20) << "4." << "Fours:" << calcScore(hand, FOURS) << endl;
			cout << setw(20) << "5." << "Fives:" << calcScore(hand, FIVES) << endl;
			cout << setw(20) << "6." << "Sixes:" << calcScore(hand, SIXES) << endl;
			cout << setw(20) << "" << "Sum:" << getUpperScore() << endl;
			cout << setw(20) << "" << "Bonus:" << getBonusScore() << endl;
			cout << setw(20) << "7." << "Three of a kind:" << calcScore(hand, THREE_OF_KIND) << endl;
			cout << setw(20) << "8." << "Four of a kind:" << calcScore(hand, FOUR_OF_KIND) << endl;
			cout << setw(20) << "9." << "Full house:" << calcScore(hand, FULL_HOUSE) << endl;
			cout << setw(20) << "10." << "Small straight:" << calcScore(hand, SMALL_STRAIGHT) << endl;
			cout << setw(20) << "11." << "Large straight:" << calcScore(hand, LARGE_STRAIGHT) << endl;
			cout << setw(20) << "12." << "Chance:" << calcScore(hand, CHANCE) << endl;
			cout << setw(20) << "13." << "Yahtzee:" << calcScore(hand, YAHTZEE) << endl;
			cout << setw(20) << "" << "Total:" << getLowerScore() << endl;
		}
		

		//Returns the score of the upper part of the board
		int getUpperScore() {
			int sum = 0;
			for (int i : upperSection) {
				sum += i;
			}
			return sum;
		}
		
		//Returns the score of the upper part of the board
		int getLowerScore() {
			int sum = 0;
			for (int i : lowerSection) {
				sum += i;
			}
			return sum;
		}
	

		//Returns the bonus points
		int getBonusScore() {
			if (getUpperScore() >= 63) {
				return 35;
			}
		}

		//Returns the total score
		int getTotalScore() {
			return getUpperScore() + getLowerScore() + getBonusScore();
		}

		//Play a hand based on the selected row
		void play(Hand* hand, int row);

		
		//Check to see if a row has been played or not (returns true if a row has been played)
		bool isPlayed(int row) {
			return board[row];
		}
		
		//Check to see if all rows haven been played or not (returns true if all rows have been played)
		bool isFinished() {
			bool played = true;
			for (bool row : board) {
				if (row == false) {
					played = false;
				}
			}
			return played;
		};


	private:
		Hand* hand = new Hand();
};




//#######################################################################################

//The run function is the main loop of your program
void run() {
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
