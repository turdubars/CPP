#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;

	Node(int aData, Node *aPrev, Node *aNext)
	: data(aData), prev(aPrev), next(aNext)
	{
	}
};

void printInDirectOrder(Node* head)
{
	for (Node *p = head; p != nullptr; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void printInReversedOrder(Node* tail)
{
	for (Node *p = tail; p != nullptr; p = p->prev)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void pushBack(Node* &head, Node* &tail, int e)
{
	if (head == nullptr)
	{
		head = new Node(e, nullptr, nullptr);
		tail = head;
	}
	else
	{
		tail->next = new Node(e, tail, nullptr);
		tail = tail->next;
	}
}

void insertBefore(Node* &head, Node* cur, int elem)
{
	if (cur == head)
	{
		Node *temp = new Node(elem, nullptr, head);
		head->prev = temp;
		head = temp;
	}
	else
	{
		Node* temp = new Node(elem, cur->prev, cur);
		cur->prev->next = temp;
		cur->prev = temp;
	}

}

Node* erase(Node* &head, Node* &tail, Node* curr)
{
	if (curr == head && curr == tail)
	{
		delete curr;
		head = nullptr;
		tail = nullptr;
		return nullptr;
	}

	else if (curr == head)
	{
		curr->next->prev = nullptr;
		head = curr->next;
		delete curr;
		return head;
	}

	else if (curr == tail)
	{
		curr->prev->next = nullptr;
		tail = curr->prev;
		delete curr;
		return tail;
	}
	else
	{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		Node* temp = curr->next;
		delete curr;
		return temp;
	}
}

void clear(Node* &head, Node* &tail)
{
	while (head)
	{
		cout << "Delete node: " << head->data << endl;

		Node* temp = head->next;
		delete head;
		head = temp;
	}

	// head = nullptr;
	tail = nullptr;
}



int main()
{
	Node *head = new Node(1, nullptr, nullptr);
	Node *tail = head;

	// Node *head = nullptr;

	tail->next = new Node(2, tail, nullptr);
	tail = tail->next;

	pushBack(head, tail, 3);
	pushBack(head, tail, 4);
	pushBack(head, tail, 5);
	// erase(head, tail, tail);
	// insertBefore(head, head, 0);

	printInDirectOrder(head);
	printInReversedOrder(tail);

	clear(head, tail);
	printInDirectOrder(head);
	printInReversedOrder(tail);
}
