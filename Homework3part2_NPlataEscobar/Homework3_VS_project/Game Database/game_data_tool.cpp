// game_data_tool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "GameConsole.h"


int main()
{

	//string GameConsoleFilePath = "E:\\Users\\jerome\\GitHub\\cogswell-cs295-game-data-tool\\game_data_tool\\input\\1024_xbox_360_games.csv";
	string GameConsoleFilePath = "1024_xbox_360_games.csv";

	GameConsole console;
	// read the file
	console.ReadGameConsole(GameConsoleFilePath);

	unsigned long int i = 0;
	string s;


	// element 1011 in the game data
	GameData game;

	// get a game data (these can be node in your ADT)
	game = console[1011];
	cout << game << endl;

	// get the line in the file from the ADT
	s = game.LineInFile();
	cout << "s = " << s << endl;

	// use the encode and decode functions
	i = game.Encode(s);
	cout << "Encode(s) = " << i << endl;
	cout << "Decode(i) = " << game.Decode(i) << endl;


}

