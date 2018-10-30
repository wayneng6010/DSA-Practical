#include <iostream>
#include "Stack.h"
using namespace std;

struct Node {
	int Data;
	struct Node *Next; // self-referential
};

// Create a class STACK that contains push, and pop function.
class stack {
	public:
		void Push(Node *&Top, int Num);//inserting the number 20 into stack
		void Pop(Node *&Top, int &Item);
		void Display(Node *Top);
};

// Create a class QUEUE that contain append and serve function
class queue {
public:
	void Append(Node *&Top, Node *&Tail, int Num);//inserting the number 20 into stack
	void Serve(Node *&Top, Node *&Tail, int &Item);
	void Display(Node *Top);
};

// Stack - Push function/operation
void stack::Push(struct Node *&Top, int Num)
{
	struct Node *newNode; // can declare typedef

	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Data = Num;
	newNode->Next = Top;
	Top = newNode;
	cout << Num << " is inserted\n";
}

//Stack - POP operation
void stack::Pop(Node *&Top, int &Item)
{
	struct Node *Temp;
	if (Top == NULL)
		cout << "Stack is empty\n";
	else
	{
		Item = Top->Data;
		Temp = Top;
		Top = Top->Next;
		free(Temp);
		cout << Item << " is deleted from stack\n";
	}
}

//Stack - DISPLAY operation
void stack::Display(Node *Top) {
	cout << "\nDisplay: \n";
	if (Top == NULL) {
		cout << "Your stack is empty\n";
	}
	while (Top != NULL) {
		cout << Top->Data << "\n";
		Top = Top->Next;
	}
}

// create a function for Queue - APPEND
void queue::Append(struct Node *&Head, struct Node *&Tail, int Num)
{
	struct Node *NewNode;
	NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->Data = Num;
	NewNode->Next = NULL;
	if (Tail == NULL)
		Head = NewNode;
	else
		Tail->Next = NewNode;
	Tail = NewNode;


	cout << Num << " is inserted\n";
}

//create a function for Queue - SERVE
void queue::Serve(Node *&Head, struct Node *&Tail, int &Item)
{
	struct Node *Temp;
	if (Head == NULL)
		cout << "Stack is empty\n";
	else
	{
		Item = Head->Data;
		Temp = Head;
		Head = Head->Next;
		if (Head == NULL)
			Tail = NULL;
		free(Temp);
		cout << Item << " is deleted from stack\n";
	}
}

//Queue - DISPLAY operation
void queue::Display(Node *Top) {
	cout << "\nDisplay: \n";
	if (Top == NULL) {
		cout << "Your queue is empty\n";
	}
	while (Top != NULL) {
		cout << Top->Data << "\n";
		Top = Top->Next;
	}
}

int main()
{
	int Item;

	cout << "STACK\n";
	Node *TopStack = NULL;
	stack stackObj;
	stackObj.Push(TopStack, 20);
	stackObj.Push(TopStack, 30);
	stackObj.Pop(TopStack, Item);
	stackObj.Push(TopStack, 40);
	stackObj.Display(TopStack);

	cout << endl << "------------------------" << endl;

	cout << "QUEUE\n";
	Node *HeadQueue = NULL;
	Node *TailQueue = NULL;
	queue queueObj;
	queueObj.Append(HeadQueue, TailQueue, 10);
	queueObj.Append(HeadQueue, TailQueue, 20);
	queueObj.Serve(HeadQueue, TailQueue, Item);
	queueObj.Append(HeadQueue, TailQueue, 30);
	queueObj.Serve(HeadQueue, TailQueue, Item);
	queueObj.Display(HeadQueue);

	return 0;
}




