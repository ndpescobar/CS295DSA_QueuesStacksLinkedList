#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <ctype.h>


using namespace std;

// constants
#define ENCODE_BASE		36
#define NUM_DIGITS		10
#define MAX_PLAINTEXT	5

class GameData
{
private:
	// a unique identifier for the node
	unsigned long int id;
	// line number in the file that the data came from
	unsigned int line;
	// all the data for this line in the file
	string lineInFile;

	int CharEncode(char c) { // maps a-z,0-9 into 0,1,2, ..., 35
		return (isalpha(c) ? ((unsigned int)c - 'a') : (ENCODE_BASE - 10) + (c - '0'));
	}

public:
	string LineInFile() { return lineInFile; }
	unsigned long int Encode(string s);
	string Decode(unsigned long int value);
	GameData();
	~GameData();

	friend class GameConsole;
	friend ostream& operator<<(ostream& os, const GameData& g);
};

