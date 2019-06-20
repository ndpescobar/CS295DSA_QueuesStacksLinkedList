#include "GameConsole.h"


//
// Func: GameConsole
// Desc: Constructor to create the game data
//
GameConsole::GameConsole()
{
	numGames = 0;
}

//
// Func: ~GameConsole
// Desc: Destructor to delete the game data
//
GameConsole::~GameConsole()
{
}



//
// Func: ReadGameConsole
// Desc: Function to show students how to read the game data
//
bool GameConsole::ReadGameConsole(string aFile) {

	ifstream theFile(aFile.c_str());

	bool status = false;

	// open the file
	if (!theFile.is_open()) {
		cout << "ERROR: Unable to open the file <" << aFile << ">" << endl;
		status = false;
		return status;
	}

	// read the file
	string lineInFile;
	int line = 1;
	int index;
	while (getline(theFile, lineInFile)) {

		/*
		cout << "line = " << line;
		cout << "\t";
		cout << "lineInFile = [" << lineInFile << "]" << endl;
		*/

		// add the data in to the structure here
		index = line - 1;
		data[index].id = (512 * line * line) - (line * 512) + 2; // create a unique even id for the node
		data[index].line = line;
		data[index].lineInFile = lineInFile;

		line++;

		numGames++;

	}

	// close the file
	theFile.close();

	return true;
}
