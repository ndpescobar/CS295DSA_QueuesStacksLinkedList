/*	Homework 3 Coding - Queues, Stacks, and Link Lists.
	@author: Nicolas Plata-Escobar.
	@version: v0.6, 06/20/2019.
*/
#include <iostream>
#include <fstream>
#include <array>
#include <string>
//#include <stack>
//#include <queue>
//#include <list>
//#include "Game Database/GameData.cpp"
using namespace std;

class Stack {
	const int MAX = 1024;
	string *arrS;
	int top;
public:
	Stack(int size) {
		arrS = new int[size];
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

	//traverse through the stack's data for developer to return a bool
	bool FindDeveloper(string developer) {
		while (top >= 0) {
			if (pop() == developer) { //may need to parse string for GameData values/categories
				return true;
			}
		}
		return false;
	}

	//adds a string to the top of the stack
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

	//write out contents of the stack to a CSV file, fileName
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
	string *arrQ;
	int maxSize;
	string front;
	string back;
	int currentSize;
public:
	
	Queue(int size) {
		arrQ = new int[size];
		maxSize = size;
		front = 0;
		back = -1;
		currentSize = 0;
	}
	
	//returns current size of the queue
	int size(){
		return currentSize;
	}
	
	//check if queue is full
	bool isFull(){
		return (size()==maxSize);
	}
	
	//check if queue is empty
	bool isEmpty(){
		return (size()==0);
	}
	
	//adds an element to the back of the queue
	bool Enqueue(string s) {
		if(isFull()){
			cout << "Queue Overflow" << endl;
			return false;
		}
		else {
			back = size() - 1;
			arrQ[back] = s;
			currentSize++;
			return true;
		}
	}

	//removes an element from the front of the queue
	string Dequeue() {
		if (isEmpty()) {
			cout << "Queue Underflow" << endl;
			return "";
		}
		else {
			string oldString = arrQ[front];
			front = size() - (size() - 1);
			currentSize++;
			return oldString;
		}
	}

	//traverse through the queue's data for developer to return a bool
	bool FindDeveloper(string developer) {
		for (int i = back; i > 0; i--) {
			if (arrQ[i] == developer) { //may need to parse string for GameData values/categories
				return true;
			}
		}
		return false;
	}

	void AddToEnd(string gameTitle) { //same as enqueue?
		if(isFull()){
			cout << "Queue Overflow; queue is full" << endl;
			return false;
		}
		else {
			back = size() - 1;
			arrQ[back] = s;
			currentSize++;
			return true;
		}
	}
};

struct Node {
	string value;
	struct Node* next;
	struct Node* prev;
	struct Node* head
	
	struct Node* CreateNewNode(string gameTitle){
		struct Node* newNode = malloc(sizeof(struct Node));
		newNode->value = gameTitle;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	
	//create new node at end of the list with gameTitle
	void InsertEnd(string gameTitle){
		struct Node* newNode = CreateNewNode(gameTitle);
		struct Node* traverse = head;
		while (traverse != NULL) {
			traverse = traverse->next;
		}
		if (traverse == NULL) {
			traverse->next = newNode;
		}
		else {
			cout << "error: failed to insert new node at end" << endl;
		}
	}
	
	//create new node at beginning/head of the list with gameTitle
	void InsertBegin(string gameTitle){
		struct Node* newNode = CreateNewNode(gameTitle);
		if (head == NULL) {
			head = newNode;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	
	//traverse to node with insertionTitle, and create a new node with gameTitle after insertionTitle
	void InsertAfter(string gameTitle, string insertionTitle){
		struct Node* newNode = CreateNewNode(gameTitle);
		struct Node* traverse = head;
		while (traverse->data != insertionTitle) {
			traverse = traverse->next;
		}
		if (traverse->data == insertionTitle) {
			//possibly incorrect linking 
			traverse->prev = newNode;
			newNode->next = traverse;
			traverse = newNode;
		}
		else {
			cout << "error: failed to insert new node after " << insertionTitle << endl;
		}
	}
	
	
	//traverse list for gameTitle, and return true if found
	bool Delete(string gameTitle){
		
	}
	
	//traverse list for developer, and return the line/node
	string FindGame(string developer){
		
	}
};

int main() {
	//Stack - compute total number of arrayIndexes (data[i] operations) for all operations.

	//Queue - compute total number of arrayIndexes (data[i] operations) for all operations.

	//Doubly Linked List (prevNode and nextNode) - compute total number of pointer traversals.


	cout << "Double ENTER to end program." << endl;
	string exit;
	getline(cin, exit);
	getline(cin, exit);
	cout << "Goodbye!";
	return 0;
}