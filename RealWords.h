#pragma once
#ifndef REALWORDS_H
#define REALWORDS_H

using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class Name: RealWords - Written by: Hugo Santana (SID# 10511804)

// Summary: This class is used to create word objects and is used in the Trigrams class to store these objects in a vector. It has a getter and setter for the word
// to make these accessible.

// Inputs: None
// Outputs: None

// Date of Creation: 22/05/21

class RealWords {

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private:
	string word;
public:
	string getRealWord();
	void setRealWord(string realword);
};



#endif