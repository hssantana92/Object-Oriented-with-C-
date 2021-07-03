#include <string>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

// Lowercase Conversion
string lowerCase(string x) {
	string blank = "";
	for (char c : x) {
		c = tolower(c);
		blank = blank + c;
	}
	return blank;
}

// Uppercase Coversion
string upperCase(string x) {
	string blank = "";
	for (char c : x) {
		c = toupper(c);
		blank = blank + c;
	}
	return blank;
}

// Split String
vector<string> splitDefinition(string x) {

	stringstream definition(x);
	string splitDefinition;
	vector<string> splitDefVector;

	while (getline(definition, splitDefinition, ';')) {
		splitDefVector.push_back(splitDefinition);
	}

	return splitDefVector;
}

// Print Type
string printType(string x) {
	if (x == "[n]") {
		x = "Noun (n.)";
	}
	else if (x == "[v]") {
		x = "Verb (v.)";
	}
	else if (x == "[adv]") {
		x = "Adverb (adv.)";
	}
	else if (x == "[adj]") {
		x = "Adjective (adj.)";
	}
	else if (x == "[prep]") {
		x = "Preposition (prep)";
	}
	else if (x == "[misc]") {
		x = "MiscWords (misc.)";
	}
	else if (x == "[pn]") {
		x = "ProperNouns (pn.)";
	}
	else if (x == "[n_and_v]") {
		x = "NounAndVerb (n. v.)";
	}

	return x;
}

bool isNumber(const string& c) {
	return (c.find_first_of("0123456789") != std::string::npos);
}