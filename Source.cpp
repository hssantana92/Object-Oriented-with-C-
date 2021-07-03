//CSP2104 C++ programming Assignment Part 1 & 2
//Hugo Santana 
//Student No. 10511804

#include <iostream>
#include <string>
#include <vector>
#include "Dictionary_Part01.h"
#include "Dictionary_Part02.h"
#include "Trigrams.h"
#include "Word.h"
#include <sstream>


using namespace std;


int main() {
	// Program title
	cout << "Dictionary 2021 - CSP2104 Object-oriented Programming with C++ \n\n";

	//Reads txt file and loads words, types, and definitions into a Word class vector
	Dictionary_Part02 dictionaryPart02;
	dictionaryPart02.loadDictionary("dictionary2021.txt");

	//Create Trigrams object and load words and real words
	Trigrams trigram;
	trigram.loadWords("dictionary2021.txt");

	// Main Menu
	while (true) {
		// Display menu options
		cout << "Please select one of the following options: \n 1. Word search \n 2. Find word(s) with more than three z's \n 3. Find words that have a 'q' without a following 'u'" << endl;
		//Part 2 options
		cout << " 4. Noun and Verb \n 5. Palindromes \n 6. Anagrams \n 7. Guessing Game \n 8. Trigrams" << endl;

		// check if user input is valid
		string line;
		int userResponse = -1;
		while (getline(cin, line)) {
			stringstream ss(line);
			if (ss >> userResponse) {
				if (ss.eof()) {
					break;
				}
			}
			cout << "Invalid response. Please try again." << endl;
		}

		switch (userResponse) {
		case 1:
			// Call searchWord (Task 1) method
			dictionaryPart02.searchVector();
			cout << "\n";
			break;
		case 2:
			// Call Three Zs (Task 2) method
			dictionaryPart02.threeZ();
			cout << "\n";
			break;
		case 3:
			// Call Q/U (Task 3) method
			dictionaryPart02.quFunction();
			cout << "\n";
			break;
		case 4:
			// Call nounVerb method
			dictionaryPart02.nounAndVerb();
			cout << "\n";
			break;
		case 5:
			// Call Palindromes method
			dictionaryPart02.palindromes();
			cout << "\n";
			break;
		case 6:
			// Call Anagram method
			dictionaryPart02.anagram();
			cout << "\n";
			break;
		case 7:
			// Call Anagram method
			dictionaryPart02.guessingGame();
			cout << "\n";
			break;
		case 8:
			// Call Trigrams
			trigram.main();
			cout << "\n";
			break;
		default:
			// give me a valid number please
			cout << "Invalid response. Please try again." << endl;
		}
	}
	system("pause");
	return 0;
};