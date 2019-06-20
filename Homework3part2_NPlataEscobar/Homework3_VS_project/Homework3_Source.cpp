/*	Homework 3 Coding - Queues, Stacks, and Link Lists.
	@author: Nicolas Plata-Escobar.
	@version: v0.1, 06/19/2019.
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include "Game Database/GameData.cpp"
using namespace std;

class Stack {
private:
	int MAX = 1024;
	int top;
public:
	string a[MAX];

	Stack() { top = -1; }

	bool push(string s) {
		if (top >= (MAX - 1)) {
			cout << "Stack Overflow" << endl;
			return false;
		}
		else {
			a[++top] = s;
			cout << "pushing: " << s << endl;
			return true;
		}
	}

	string pop() {
		string sTemp = "";
		if (top < 0) {
			cout << "Stack Underflow" << endl;
			return "";
		}
		else {
			sTemp = a[top--];
			return sTemp;
		}
	}

	string FindDeveloper(string developer) {
	
	}

	void AddToEnd(string gameTitle) {
	
	}

	void WriteCSV(string fileName) {
	
	}
};

int main() {
	//Stack - compute total number of arrayIndexes (data[i] operations) for all operations.
	stack <GameData> stackGD;

	//Queue - compute total number of arrayIndexes (data[i] operations) for all operations.
	queue <GameData> queueGD;

	//Doubly Linked List (prevNode and nextNode) - compute total number of pointer traversals.


	cout << "Double ENTER to end program." << endl;
	string exit;
	getline(cin, exit);
	getline(cin, exit);
	cout << "Goodbye!";
	return 0;
}