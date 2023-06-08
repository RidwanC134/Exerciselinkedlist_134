#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** Hidayatullah, Node** Ridwan);
	bool listEmpty();
	bool delNode();
	void traverse();

};

void CircularLinkedList::addNode() { // My answer
	Node* newNode = new Node();
	cout << "Enter roll number: ";
	cin >> newNode->rollNumber;
	cout << "Enter name: ";
	cin >> newNode->name;

	if (listEmpty() || newNode->rollNumber < LAST->next->rollNumber) { // Awal dari list
		newNode->next = LAST->next;
		LAST->next = newNode;
	}
	else {
		Node* Ridwan = LAST->next;
		Node* Hidayatullah = NULL;
		while (Ridwan != LAST && Ridwan->rollNumber < newNode->rollNumber) {
			Hidayatullah = Ridwan;
			Ridwan = Ridwan->next;
		}
		newNode->next = Ridwan;
		Hidayatullah->next = newNode;
		if (Ridwan == LAST) {
			LAST = newNode;
		}
	}

	cout << "Node added successfully." << endl;
}

bool CircularLinkedList::search(int rollno, Node** Hidayatullah, Node** Ridwan) {
	*Hidayatullah = LAST->next;
	*Ridwan = LAST->next;

	while (*Ridwan != LAST) {
		if (rollno == (*Ridwan)->rollNumber) {
			return true;
		}
		*Hidayatullah = *Ridwan;
		*Ridwan = (*Ridwan)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST = NULL;
}

bool CircularLinkedList::delNode() { // My answer
	if (listEmpty()) {
		cout << "List is empty. Cannot delete node." << endl;
		return false;
	}

	int rollno;
	cout << "Enter the roll number to delete: ";
	cin >> rollno;

	Node* Hidayatullah;
	Node* Ridwan;

	if (search(rollno, &Hidayatullah, &Ridwan)) {
		if (Ridwan == LAST) { // Akhir dari list
			if (LAST == LAST->next) {
				delete Ridwan;
				LAST = NULL;
			}
			else {
				Hidayatullah->next = Ridwan->next;
				delete Ridwan;
				LAST = Hidayatullah;
			}
		}
		else { // Diantara 2 Nodes dalam list
			Hidayatullah = LAST;
			while (Hidayatullah->next != Ridwan) {
				Hidayatullah = Hidayatullah->next;
			}
			Hidayatullah->next = Ridwan->next;
			delete Ridwan;
		}
		cout << "Node deleted successfully." << endl;
		return true;
	}
	else {
		cout << "Node not found. Deletion failed." << endl;
		return false;
	}
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* RidwanNode = LAST->next;
		while (RidwanNode != LAST) {
			cout << RidwanNode->rollNumber << "   " << RidwanNode->name << endl;
			RidwanNode = RidwanNode->next;
		}
		cout << LAST->rollNumber << "   " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter yout choice (1-4): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1': {

			}
			case '2': {

			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
} 