#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include "HelperMethods.h"
#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"
#include <ctime>

using namespace std;

// Documentation for the below methods is located in the .h file

// Part 2 - Task 1
void Dictionary_Part02::nounAndVerb() {
	int count = -1;
	cout << "-------- Words both nouns and verbs --------\n" << endl;

	cout << "The following words are both a noun and verb: \n";
	
	// Iterate through word vector
	for (Word elem : wordVector) {

		// If type is a nound and verb, print the word
		if (elem.getType() == "[n_and_v]") {
			cout << elem.getWord() << "\n";
		}
	}
}


// Part 2 - Task 2
void Dictionary_Part02::palindromes() {
	cout << "-------- Palindromes --------\n" << endl;

	cout << "The following words are palindromes: \n";

	// Iterate through word vector
	for (Word elem : wordVector) {
		// Exclude single char words from the search
		if (elem.getWord().length() > 1) {
			// Create a temporary reversed string
			string temp = elem.getWord();
			reverse(temp.begin(), temp.end());
			// Compare a reversed string to the original string and if a match is found, output the word
				if (elem.getWord() == temp) {
					cout << elem.getWord() << "\n";
			}
		}
	}
}

// Part 2 - Task 3
void Dictionary_Part02::anagram() {
	cout << "-------- Anagrams --------\n" << endl;

	// Ask for input
	string inputWord = "";
	cout << "Please enter a word: ";
	getline(cin, inputWord);

	// Initialise bool variable
	bool found = false;

	// Convert input to lower case
	inputWord = lowerCase(inputWord);

	// Create sorted version of the input word
	string sortedWord = inputWord;
	sort(sortedWord.begin(), sortedWord.end());

	// Check if input is a valid word.// - 
	for (Word elem : wordVector) {
		if (elem.getType() == "[pn]") {
			if (lowerCase(elem.getWord()) == inputWord) {
				found = true;
				break;
			}
		}
		else {
			if (elem.getWord() == inputWord) {
				found = true;
				break;
			}
		}
	}

	// If input is a valid word, check if there are any anagrams, if not print word not found
	if (found == true) {

		cout << "The following words are anagrams of " << inputWord << endl;

		// Iterate through word vector
		for (Word elem : wordVector) {

			// Created sorted version of the current word in the iteration of the word vector
			string temp = elem.getWord();
			sort(temp.begin(), temp.end());

			// If type is a proper noun, convert input to upper case version
			if (elem.getType() == "[pn]") {
				string pnTemp = upperCase(inputWord);

				// If the current word matches the input and the upper case version does not match the input upper case version, print the word.
				// This prevents the input word being printed alongside the anagrams
				if (temp == sortedWord && upperCase(elem.getWord()) != pnTemp) {
					cout << elem.getWord() << "\n";
				}
			}
			else {
				// else if not a proper noun, complete the above with no case conversion
				if (temp == sortedWord && elem.getWord() != inputWord) {
					cout << elem.getWord() << "\n";
				}
			}
		}
	}
	// If the input is not a valid word, print an error message.
	else {
		cout << "Invalid word" << "\n";
	}
}


// Part 2 - Task 4
void Dictionary_Part02::guessingGame() {

	// Give random function a starting point passing time since unix epoch - Avoids the same 'random' number being generated on each call of the method.
	srand((unsigned)time(0));
	cout << "-------- Guessing Game --------\n" << endl;

	cout << "Guess the noun by using its definition as a clue. You have three attempts. \n";

	// Initialise variables
	vector<int> nounPos;
	int count = -1;

	// Iterate through word vector to find noun positions in the word vector and store positions in a vector
	for (Word elem : wordVector) {
		count += 1;
		if (elem.getType() == "[n]" || elem.getType() == "[n_and_v]") {
			nounPos.push_back(count);
		}
	}
	// Generate a random noun (Generates a random position in the nounPosition vector and store in variable).
	int randomNounIndex = rand() % nounPos.size();

	// Print how many letters the noun has
	cout << "This noun has " << wordVector[nounPos[randomNounIndex]].getWord().length() << " letters.\n" << endl;

	// Print the defintion
	cout << "Definition:\n";
	cout << wordVector[nounPos[randomNounIndex]].getDefinition() << endl;

	// Initialise variables
	int guessCount = 0;
	string guess = "";
	
	while (guessCount != 3) {
		// Ask for input
		cout << "\nYour guess is: ";
		string userInput = "";
		getline(cin, userInput);

		// If the input matches the noun, print correct and end loop.
		if (lowerCase(userInput) == wordVector[nounPos[randomNounIndex]].getWord()) {
			cout << "You guessed " << wordVector[nounPos[randomNounIndex]].getWord() << " correctly. Good Work!";
			guessCount = 3;
			break;
		}
		else {
			// Add 1 to the guess count and generate an extra hint. If three attempts were made unsuccesfully, print a fail message.
			guessCount += 1;
			if (guessCount == 3) {
				cout << "You failed! The word was " << wordVector[nounPos[randomNounIndex]].getWord() << endl;
				break;
			}
			cout << "Incorrect. Have this extra hint!" << endl;
			guess += wordVector[nounPos[randomNounIndex]].getWord()[guessCount - 1];
			cout << guess << "\n";
			continue;
		}
	}
}


// Part 2 - Task 5...
//void Dictionary_Part02::runThis() {

	//// Create string full of words in dictionary
	//string words = "";
	//for (Word elem : wordVector) {
	//	words = words + elem.getWord() + " ";
	//}

	//// Get rid of whitespace at the end of the string
	//words.pop_back();

	// Initialise 3D Array
	//int charCount[27][27][27] = { 0 };
	//int index1, index2, index3;

	//// Increment 3D Array counter
	//for (int i = 0; i < words.length() - 2; i++) {
	//	char a = words[i];
	//	char b = words[i + 1];
	//	char c = words[i + 2];

	//	index1 = returnIndex(a);
	//	index2 = returnIndex(b);
	//	index3 = returnIndex(c);

	//	 
	//	if ((index1 != -1) && (index2 != -1) && (index3 != -1)) {
	//		charCount[index1][index2][index3]++;
	//	}
	//}

	//// Ask for input of two chars
	//cout << "\nPlease enter two chars:";
	//string userInput = "";
	//getline(cin, userInput);

	//// Find max count and key position (char)
	//int maxCount = 0;
	//int maxKey = 0;

	//// Store counts in an array to later obtain first, second, and third most used chars after the first two char inputs
	//std::array<int, 27> mostUsedChars;
	////int mostUsedChars[27];

	//for (int i = 0; i < 27; i++) {
	//	//int depth = charCount[returnIndex('t')][returnIndex('h')][i];
	//	int thirdCharCount = charCount[returnIndex(userInput[0])][returnIndex(userInput[1])][i];

	//	mostUsedChars[i] = thirdCharCount;

	//	
	//};

	//// Find 1st, 2nd, and 3rd max char counts from the array
	//int max1 = -1; int max1Key = -1;
	//int max2 = -1; int max2Key = -1;
	//int max3 = -1; int max3Key = -1;

	//for (int number : mostUsedChars) {
	//	cout << number << endl;
	//	if (number > max1) {
	//		max3 = max2;
	//		max2 = max1;
	//		max1 = number;
	//	}
	//	else if (number > max2) {
	//		max3 = max2;
	//		max2 = number;
	//	}
	//	else if (number > max3) {
	//		max3 = number;
	//	}
	//}

	//// Find max char array positions
	//for (int i = 0; i < mostUsedChars.size() - 1; i++) {
	//	if (mostUsedChars[i] == max1) {
	//		max1Key = i;
	//	}
	//	else if (mostUsedChars[i] == max2) {
	//		max2Key = i;
	//	}
	//	else if (mostUsedChars[i] == max3) {
	//		max3Key = i;
	//	}
	//}
	//cout << "Max1: " << max1 << " Index: " << max1Key << endl;
	//cout << "Max2: " << max2 << " Index: " << max2Key << endl;
	//cout << "Max3: " << max3 << " Index: " << max3Key << endl;

	//std::array<char, 27> alphabet = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	//// Print 10 random english sounding words
	//cout << "Most probabable english sounding words based on your input" << endl;
	//cout << userInput << alphabet[max1Key] << endl;
	//cout << userInput << alphabet[max2Key] << endl;
	//cout << userInput << alphabet[max3Key] << endl;


