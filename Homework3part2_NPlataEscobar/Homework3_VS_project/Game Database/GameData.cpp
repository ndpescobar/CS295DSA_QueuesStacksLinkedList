#include "GameData.h"
using namespace std;

//
// Func: GameData
// Desc: Constructs a game data
//
GameData::GameData()
{
	id = 0;
	line = 0;
	lineInFile = "";
}

//
// Func: ~GameData
// Desc: Destructs a game data
//
GameData::~GameData()
{
}

//
// Func: Encode
// Desc: Encodes a string into a integer, 0-26 is a-z, 0-9 is 27-35.
// This algorithm implements a collision free encoding (hash function) of the first 6 characters of the game title.
// Strings of length 5 or less are collision free.
//
unsigned long int GameData::Encode(string s) {

	unsigned long int value = 0;

	// create a new string lowered with only digits
	string sAlphaDigit = "";
	for (int i = 0; i < s.length(); i++) {

		if (isalpha(s[i]) || isdigit(s[i])) {
			// lower s
			sAlphaDigit += tolower(s[i]);
		}

	}

	// cout << "sAlphaDigit = " << sAlphaDigit << endl;

	// encode the new string into a number
	for (int i = 0; (i < sAlphaDigit.length()) && (i < MAX_PLAINTEXT); i++) {
		value += CharEncode(sAlphaDigit[i]) * pow(ENCODE_BASE, i);
	}

	return value;

}

//
// Func: Decode
// Desc: Decode integer into a string
//
string GameData::Decode(unsigned long int value) {

	string s = "";

	// log base 36 by switching bases
	double log36 = log(value) / log(ENCODE_BASE);

	// cout << "log36 = " << log36  << endl;

	int exp = floor(log36);

	// cout << "exp = " << exp << endl;

	int letter, basePow;
	char ch;
	int n = value;
	for (int i = exp; i >= 0; i--) {
		basePow = pow(ENCODE_BASE, i);
		letter = n / basePow;

		if (letter < ENCODE_BASE - NUM_DIGITS)
			// if it is a alpha character, 0 - 25, for a-z
			ch = letter + (int) 'a';
		else
			// else is a number (26 - 35 representing the numbers 0 - 9
			ch = (letter - (ENCODE_BASE - NUM_DIGITS)) + (int) '0';

		// prepend the character to s
		s = ch + s;

		// remove the char from the number n
		n = n - (letter * basePow);
	}

	return s;
}

//
// Func: <<
// Desc: Prints an address record table
//
ostream& operator<<(ostream& os, const GameData& g)
{

	os << "id         = " << g.id << endl;
	os << "line       = " << g.line << endl;
	os << "lineInFile = " << g.lineInFile << endl;

	return os;
}