#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HelperMethods.h"
#include "Word.h"

using namespace std;


string Word::getWord() {
	return word;
}

string Word::getType() {
	return type;
}

string Word::getDefinition() {
	return definition;
}

void Word::setWord(string x) {
	word = x;
}

void Word::setType(string x) {
	type = x;
}

void Word::setDefinition(string x) {
	definition = x;
}

void Word::printDefinition() {
	if (definition.find(';') != string::npos) {
		cout << " Definitions: " << "\n";
		for (string i : splitDefinition(definition))
			cout << i << "\n" << "\n";
	}
	else
		cout << " Definition: " << "\n" << definition << endl;
	cout << "\n---------------------------------------------" << "\n";
}


