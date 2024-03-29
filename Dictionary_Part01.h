#pragma once
#ifndef DICTIONARYPART_01
#define DICTIONARYPART_01

#include "Word.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class Name: Dictionary_Part01 - Written by: Hugo Santana (SID# 10511804)

// Summary: This class will hold and create a vector of Word objects. This class will also include several functions/methods to implement each task as outlined
// in Part 1 of the assignment brief (described in more detail below).

// Inputs: Inherits from the Word Class 
// Outputs: Vector of Word objects

// Date of Creation: 20/03/21

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Dictionary_Part01 {
protected:
	Word words;
	vector<Word> wordVector;
	 
public:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Method Name: searchVector - Written by: Hugo Santana (SID# 10511804)

// Summary: This method will search for a given word inside the vector of word objects. If a search is succesful, the method will output the word, type, and definition.

// Inputs: String (User input)
// Outputs: Word (String), Type (String), Definition (String)

// Date of Creation: 20/03/2021

	void searchVector();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Method Name: threeZ - Written by: Hugo Santana (SID# 10511804)

// Summary: This method will search for words with more than three z's. The method will iterate through all words in the word Vector, and all chars of each word.
// For each 'z' found, 1 will be added to the count. After iterating through each char of the word, the program will check to see if the count is more than 3,
// and if so, the word will be printed.

// Inputs: None
// Outputs: Words containing more than three 'Z's'
// Date of Creation: 27/03/2021.

	void threeZ();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Method Name: loadDictionary - Written by: Hugo Santana (SID# 10511804)

// Summary: This method will read through each line of a text file and create a vector of word objects with the information found on each line. Each word object 
// will contain a word name, word type, and word defintion.

// Inputs: Text file (String (filename))
// Outputs: Vector of Word objects

// Date of Creation: 20/03/2021

	void loadDictionary(string filename);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Method Name: quFunction - Written by: Hugo Santana (SID# 10511804)

// Summary: This method will iterate through all words in the word vector and all chars in each word. A counter will be used to
// find the index of any q found, and then check the next char in the word. if the current index char is q and the index char + 1 is not u. output the word.

// Inputs: None
// Outputs: Words containing q without a following u (String)

// Date of Creation: 02/04/2021

	void quFunction();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};

#endif