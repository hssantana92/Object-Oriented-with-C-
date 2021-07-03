#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Word.h"
#include "HelperMethods.h"
#include "Dictionary_Part01.h"


using namespace std;


void Dictionary_Part01::searchVector() {
	cout << "-------- Word Search --------\n" << endl;

	// Initialise variables
	bool found = false;
	int count = -1;
	string inputWord = "";

	// Ask for input
	cout << "Please enter a word: ";
	getline(cin, inputWord);

	// Iterate over all elements in Word Vector
	for (Word elem : wordVector) {
		count++;
		// First check if the word type is a proper noun.
		// if so, then convert both the input string and the word in the word vector to an upper case version. 
		// If not, convert the input string to a lower case version for comparison
		if (elem.getType() == "[pn]") {
			if (upperCase(elem.getWord()) == upperCase(inputWord)) {
				found = true;
				break;
			}
		}
		else {
			if (elem.getWord() == lowerCase(inputWord)) {
				found = true;
				break;
			}
		}

	}
	if (found) {
		// as found is true, print the word, type, and its definition
		cout << "\n" << " Word: " << wordVector[count].getWord();
		cout << " - Type: " << printType(wordVector[count].getType()) << "\n" << "\n";

		wordVector[count].printDefinition();
	}
	else {
		cout << "Word not found." << endl;
	}
}


void Dictionary_Part01::threeZ() {
	cout << "-------- Three Z's -------- \n" << endl;

	cout << "The following words contain more than three Z's: \n" << endl;

	// Iterate through the word vector
	for (Word word : wordVector) {

		// Initialise count variables
		int count = 0;
		//int wordCount = 0;

		// Iterate over each char of every word
		for (char c : word.getWord()) {

			// If char is equal to a lower or upper case z/Z, increment count variable
			if (c == 'z' || c =='Z')
				count++;
		}

		// If count greater than three, print the word
		if (count > 3) {
			cout << word.getWord() << "\n";
		}
	}
}



void Dictionary_Part01::quFunction() {
	cout << "-------- Q without a following U --------\n" << endl;

	cout << "The following words have a 'q' without a following 'u' eg 'Iraqi': \n";

	// Iterate through word vector
	for (Word word : wordVector) {

		// Initialise count variable
		int count = -1;

		// Iterate through each char of each word
		for (char c : word.getWord()) {

			count++;

			//If the char is a lowercase q or uppercase Q and the next char is a u, print the word
			if ((c == 'q' || c == 'Q') && word.getWord()[count + 1] != 'u') {
				cout << word.getWord() << "\n";
			}
		}
		
	}
}


void Dictionary_Part01::loadDictionary(string filename) {

	// initialise variables
	string line;
	int lineCount = 0;

	ifstream myfile(filename);

	if (myfile.is_open()) {
		// while not at the end of the text file, run this code
		while (!myfile.eof()) {
			getline(myfile, line);

			lineCount++;

			// if line is empty, take 1 from the line count and go to next iteration
			if (line.size() == 0) {
				lineCount--;
				continue;
			}

			// if line count is odd  find the word and type substrings and add them to the words object
			if (lineCount % 2 != 0) {
				words.setWord(line.substr(0, line.find(" ")));
				words.setType(line.substr(line.find("["), line.find("]")));

				// if line count is even, this is the defitiion. add the line to the word class and push the words object to the vector of words objects
			}
			else if (lineCount % 2 == 0) {
				words.setDefinition(line);
				wordVector.push_back(words);
			}

		}

		// close the file.
		myfile.close();
	}
};


