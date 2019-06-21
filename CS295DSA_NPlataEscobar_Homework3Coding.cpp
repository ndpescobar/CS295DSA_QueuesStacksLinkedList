/*	Homework 3 Coding - Queues, Stacks, and Link Lists.
	@author: Nicolas Plata-Escobar.
	@version: v0.1, 06/19/2019.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include "Game Database/GameData.cpp"
using namespace std;

class Stack {
	int MAX = 1024;
	string *arrS;
	int top;
	
public:
	string arrS[MAX];
	Stack(int size) {
		top = -1;
	}

	bool push(string s) {
		if (top >= (MAX - 1)) {
			cout << "Stack Overflow" << endl;
			return false;
		}
		else {
			arrS[++top] = s;
			cout << "pushing: " << s << endl;
			return true;
		}
	}

	string pop() {
		if (top < 0) {
			cout << "Stack Underflow" << endl;
			return "";
		}
		else {
			return arrS[top--];
		}
	}

	string FindDeveloper(string developer) {
		
	}

	void AddToEnd(string gameTitle) {
		// arrays are not dynamic.
		if (top >= (MAX - 1)) {
			cout << "Stack is full. Cannot add to end." << endl;
		}
		else {
			arrS[0] = gameTitle;
			cout << "adding \"" << gameTitle << "\" to end of stack" << endl;
		}
	}

	void WriteCSV(string fileName) {
		ofstream fileCSV;
		cout << "Opening" << fileName << endl;
		fileCSV.open(fileName, ios_base::out);
		if (fileCSV.is_open) {
			cout << "Writing..." << endl;
			for (int i = top; i >= 0; i--) {
				fileCSV << arrS[i];
			}
		}
		cout << "Closing" << fileName << endl;
		fileCSV.close();
	}
};

class Queue {
public:
	string a[MAX];
	Stack() { top = -1; }

	bool Enqueue(string s) {
		
	}

	string Dequeue() {
		
	}

	string FindDeveloper(string developer) {

	}

	void AddToEnd(string gameTitle) {
		
	}
};

struct Node {
	string value;
	struct Node* next;
	struct Node* next;
	struct Node* head
	
	struct Node* GetNewNode(string gameTitle){
		struct Node* newNode = malloc(sizeof(struct Node));
		newNode->value
	}
	
	void InsertEnd(string gameTitle){
		//create new node at end of the list with gameTitle
	}
	
	//create new node at beginning/head of the list with gameTitle
	void InsertBegin(string gameTitle){
		struct Node* 
	}
	
	void InsertAfter(string gameTitle, string insertionTitle){
		//traverse to node with insertionTitle, and create a new node with gameTitle after insertionTitle
	}
	
	bool Delete(string gameTitle){
		//traverse list for gameTitle, and return true if found
	}
	
	string FindGame(string developer){
		//traverse list for developer, and return the line/node
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