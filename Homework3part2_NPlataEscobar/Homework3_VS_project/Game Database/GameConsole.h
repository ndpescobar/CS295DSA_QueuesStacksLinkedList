#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <ctype.h>

#include "GameData.h"


using namespace std;

// constants
#define MAX_GAME_DATA	1024
#define ENCODE_BASE		36
#define NUM_DIGITS		10
#define MAX_PLAINTEXT	4

class GameConsole
{

private:
	// all the data
	int numGames;
	GameData data[MAX_GAME_DATA + 1];

public:
	bool ReadGameConsole(string aFile);
	GameConsole();
	~GameConsole();
	GameData& operator[](int i) { return data[i]; }  // allow array style access to gamedata objects
};

