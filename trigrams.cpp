#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "Trigrams.h"
#include "HelperMethods.h"
#include "Dictionary_Part01.h"

using namespace std;

string Trigrams::getWords() {
	return words;
}


void Trigrams::setWords(string word) {
	words = word;
}

int Trigrams::returnIndex(char a) {

	// Initialise variable
	int index = -1;

	// Convert char to int
	int currentCharCode = (int)a;

	// Returns the index of the input char between 0 and 26. If char is a space or dash (-), index = 0.
	if (currentCharCode == (int)' ' || currentCharCode == (int)'-') {
		index = 0;
	}
	else if ((int)'a' <= currentCharCode <= (int)'z') {
		index = currentCharCode - (int)'a' + 1;
	}
	return index;

}

void Trigrams::loadWords(string filename) {

	// initialise variables
	string line;
	int lineCount = 0;
	int incrementCounter = 0;

	ifstream myfile(filename);

	if (myfile.is_open()) {
		// while not at the end of the text file, run this code
		while (!myfile.eof()) {
			getline(myfile, line);

			lineCount++;
			incrementCounter++;

			// if line is empty, take 1 from the line count and go to next iteration
			if (line.size() == 0) {
				lineCount--;
				incrementCounter--;
				continue;
			}

			// Add word to vector of words to later check if 'random english word' is an actual word.
			if (lineCount % 2 != 0) {
				// If the first letter is uppercase, convert to lower
				if (isupper(line.substr(0, line.find(" "))[0])) {
					realWord.setRealWord(lowerCase(line.substr(0, line.find(" "))));
				}
				else {
					realWord.setRealWord(line.substr(0, line.find(" ")));
				}
				realWordsVector.push_back(realWord);
			}

			// if line count is odd, add word to the string. Only use every 6th word to speed up trigram counter.
			if (lineCount % 2 != 0 && incrementCounter == 11) {
				// If the first letter is uppercase, convert to lower
				if (isupper(line.substr(0, line.find(" "))[0])) {
					setWords(getWords() + lowerCase(line.substr(0, line.find(" "))) + " ");
				}
				else {
					setWords(getWords() + line.substr(0, line.find(" ")) + " ");
				}
				// Reset Counter
				incrementCounter = -1;
			}
		}
		myfile.close();
	}

}

void Trigrams::threeDArray() {

	int index1, index2, index3;

	// Increment 3D Array counter
	for (int i = 0; i < getWords().length() - 2; i++) {
		char a = getWords()[i];
		char b = getWords()[i + 1];
		char c = getWords()[i + 2];

		index1 = returnIndex(a);
		index2 = returnIndex(b);
		index3 = returnIndex(c);

		if ((index1 != -1) && (index2 != -1) && (index3 != -1)) {
			charCount[index1][index2][index3]++;
		}
	}
}

array<char, 3> Trigrams::mostLikelyLetters(string inputChars) {

	// Create an array to store the counts of the most occuring chars
	std::array<int, 27> mostOccuringCharCount;

	for (int i = 0; i < mostOccuringCharCount.size(); i++) {
		mostOccuringCharCount[i] = charCount[returnIndex(inputChars[0])][returnIndex(inputChars[1])][i];
	};

	// Initialise variables and find 1st, 2nd, and 3rd max char counts from the array.
	int max1 = -1; int max1Key = 0;
	int max2 = -1; int max2Key = 0;
	int max3 = -1; int max3Key = 0;

	for (int number : mostOccuringCharCount) {
		if (number > max1) {
			max3 = max2;
			max2 = max1;
			max1 = number;
		}
		else if (number > max2) {
			max3 = max2;
			max2 = number;
		}
		else if (number > max3) {
			max3 = number;
		}
	}

	// Find max char array positions
	for (int i = 0; i < mostOccuringCharCount.size(); i++) {
		if (mostOccuringCharCount[i] == max1) {
			max1Key = i;
		}
		else if (mostOccuringCharCount[i] == max2) {
			max2Key = i;
		}
		else if (mostOccuringCharCount[i] == max3) {
			max3Key = i;
		}
	}

	// Create an array to index alphabet chars
	std::array<char, 27> alphabet = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	// Create an array to store the most occuring chars
	std::array<char, 3> mostOccuringChars;

	mostOccuringChars[0] = alphabet[max1Key];
	mostOccuringChars[1] = alphabet[max2Key];
	mostOccuringChars[2] = alphabet[max3Key];

	return mostOccuringChars;
}

void Trigrams::main() {
	cout << "-------- Trigrams --------\n" << endl;
	cout << "Loading... please wait...";

	// Remove space from end of words string
	getWords().pop_back();

	// Count trigrams
	threeDArray();

	// Initialise vector to store random words
	vector<string> randomWords;
	vector<string> filteredWords;

	bool finished = false;
	cout << "\nThis program will generate random english sounding words from an input of two characters of the english alphabet.\n\nPlease enter two characters:";

	// Ask for input of two chars
	while (finished == false) {

		// If input contains more than 2 chars on int, request for input again.
		bool validInput = true;
		string userInput = "";

		while (validInput) {
			getline(cin, userInput);
			if (isNumber(userInput) == false && userInput.length() == 2) {
				validInput = false;
			}
			else {
				cout << "\nPlease enter two characters: ";
			}
		}
		

		// Return next three most likely letters
		array<char, 3> firstThree = mostLikelyLetters(userInput);

		// Create strings of new first two letters
		string first = userInput[1] + string(1, firstThree[0]);
		string second = userInput[1] + string(1, firstThree[1]);
		string third = userInput[1] + string(1, firstThree[2]);

		// Use these new letters to obtain next three most likely chars
		array<char, 3> firstCombo = mostLikelyLetters(first);
		array<char, 3> secondCombo = mostLikelyLetters(second);
		array<char, 3> thirdCombo = mostLikelyLetters(third);
		
		// Create random english sounding words using input and most occuring chars

		// Generates words using the user Input of two chars + first three most occuring letters after those two
		for (int i = 0; i < 3; i++) {
			randomWords.push_back(userInput + string(1, firstThree[i]));
		}

		// Generates words using the user input, the 1st, 2nd, and 3rd most occuring letter,
		// and the 1st, 2nd, and 3rd most occuring letters of the user inputs 2nd letter + 1st, 2nd and 3rd most occuring letters
		for (int i = 0; i < 3; i++) {
			randomWords.push_back(userInput + string(1, firstThree[0]) + string(1, firstCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[1]) + string(1, firstCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[2]) + string(1, firstCombo[i]));
		}

		for (int i = 0; i < 3; i++) {
			randomWords.push_back(userInput + string(1, firstThree[0]) + string(1, secondCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[1]) + string(1, secondCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[2]) + string(1, secondCombo[i]));
		}

		for (int i = 0; i < 3; i++) {
			randomWords.push_back(userInput + string(1, firstThree[0]) + string(1, thirdCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[1]) + string(1, thirdCombo[i]));
			randomWords.push_back(userInput + string(1, firstThree[2]) + string(1, thirdCombo[i]));
		}

		// Iterate through the randomWords vector and check if the generated word does not contain a space and is not already in the filtered words vector, 
		// push the word to the vector
		for (string word : randomWords) {
			if (word.find(" ") == std::string::npos && find(filteredWords.begin(), filteredWords.end(), word) == filteredWords.end()){
				filteredWords.push_back(word);
			}
		}

		// Check to see if generated word is a real word. If it is, remove it from the filtered word vector
		for (RealWords elem : realWordsVector) {
			if (find(filteredWords.begin(), filteredWords.end(), elem.getRealWord()) != filteredWords.end()) {
				filteredWords.erase(remove(filteredWords.begin(), filteredWords.end(), elem.getRealWord()), filteredWords.end());
			}
		}

		// Count number of words in vector. If 10 words have been generated, break the loop. Otherwise loop again, and request two new chars
		bool choice = true;
		string inputYN = "";

		if (filteredWords.size() >= 10) {
			cout << "\n10 Generated English sounding words: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << filteredWords[i] << endl;
			}

			while (choice) {
				cout << "\nWould you like to try again? (y/n)" << endl;
				getline(cin, inputYN);

				if (inputYN == "y" || inputYN == "Y") {
					//Clear vectors
					filteredWords.clear();
					randomWords.clear();
					cout << "Please enter two chars: ";
					choice = false;
				}
				else if (inputYN == "n" || inputYN == "N") {
					finished = true;
					choice = false;
				}
			}


		} else {
			cout << "Please enter another two chars:" << endl;
		}

	}	

}