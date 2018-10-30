#include <iostream>
using namespace std;

struct Node {
	int data;
	// 3. self-referential structure
	struct Node* next; 
};

struct Node* head;

/*4.Assume that the linked list is empty. 
	Write a function to insert the first node into the linked list when the user chooses option 1.*/
void Insert(Node* &head) {
	char beginOrEnd;
	cout << "Add data at beginning or end ? (b/e)\n";
	cin >> beginOrEnd;

	int number;
	cout << "Enter value to be inserted in the linked list: ";
	cin >> number;

/*5.Write a function to insert node at the front of the linked list when the user chooses option 1.*/	
	if (beginOrEnd == 'b') {
		// add at beginning of list
		Node* NewNode = (Node*)malloc(sizeof(struct Node));
		NewNode->data = number;
		NewNode->next = head;
		head = NewNode;
	}

	else if (beginOrEnd == 'e') {
		// add at end of list
		Node* temp;
		Node* NewNode = (Node*)malloc(sizeof(struct Node));
		NewNode->data = number;
		NewNode->next = NULL;
		if (head == NULL)
			head = NewNode;
		else {
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = NewNode;
		}
	}
}

void Display(Node* head) {
	if (head == NULL) {
		cout << "Your list is empty\n";
	}
	while (head != NULL) {
		cout << head->data << "\n";
		head = head->next;
	}
}

void Delete(Node* &head) {
	char beginOrEnd;
	cout << "Delete data at beginning or end or custom or delete second node ? (b/e/c/s)\n";
	cin >> beginOrEnd;

	if (beginOrEnd == 'b') {
		// delete at beginning
		Node* temp;
		if (head == NULL)
			cout << "The list is empty, nothing to delete.\n";
		else
		{
			temp = head;
			head = head->next;
			free(temp);
			cout << "Data deleted successfully\n";
		}
	}
	else if (beginOrEnd == 'e') {
		Node* Before; 
		Node* After;
		if (head == NULL)
			cout << "The list is empty, nothing to delete.\n";
		else
		{
			Before = NULL;
			After = head;
			while (After->next != NULL)
			{
				Before = After;
				After = After->next;
			}
			if (After == head) {
				free(After);
				cout << "Data deleted successfully\n";
				head = NULL;
			}
			else {
				Before->next = NULL;
				free(After);
				cout << "Data deleted successfully\n";
			}
			
		}
	}
	else if (beginOrEnd == 'c') {
		if (head == NULL)
			cout << "The list is empty, nothing to delete.\n";
		else {
			cout << "\n";
			Display(head);

			int target;
			cout << "Which data you wish to delete? ";
			cin >> target;

			Node* Temp;
			Node* before;

			Temp = head;
			bool notDeleted = true;

			while (Temp != NULL && notDeleted)
			{
				if (Temp->data == target) {
					if (Temp != head) {
						before->next = Temp->next;
					}
					else {
						head = Temp->next;
					}
					free(Temp);
					cout << "Data deleted successfully\n";
					notDeleted = false;
				}
				else {
					before = Temp;
					Temp = Temp->next;
				}
			}
			if (Temp == NULL) {
				cout << "Data not found. Delete action unsuccessful.\n";
			}
		}
	}
	//6.Write a function to delete the second node of the linked list.
	else if (beginOrEnd == 's') {
		Node* second;
		if (head == NULL)
			cout << "The list is empty, nothing to delete.\n";
		else if (head->next == NULL)
			cout << "The list has only one node, cannot delete second node.\n";
		else
		{
			second = head->next;
			if (second->next == NULL) {
				free(second);
				head->next = NULL;
				cout << "Data deleted successfully\n";
			}
			else {
				head->next = second->next;
				free(second);
				cout << "Data deleted successfully\n";
			}
		}
	}
}

int main() {
	//2.Write a program to allow user to choose the option
	char choice;
	do {
		cout << "\n------------------------------------------------------------------\n\n";
		cout << "Please choose one of the following (1/2/3/4) : \n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nResponse: ";
		cin >> choice;
		cout << "\n";
		switch (choice) {
		case '1':
			Insert(head);
			break;
		case '2':
			Delete(head);
			break;
		case '3':
			Display(head);
			break;
		case '4':
			return 0;
			break;
		}
	} while (choice != 4);


	return 0;
}
