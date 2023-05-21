#include <iomanip>
#include <iostream>

using namespace std;
typedef int Info;

struct Node
{
	Node* next;
	Info info;
};

Node* newNode(Info info)
{
	Node* node = new Node;
	node->info = info;
	node->next = NULL;
	return node;
}

void push(Node** head,Info info)
{
	Node* node = newNode(info);
	node->next = *head;
	*head = node;
}


void InputBefore(Node** head, Info v1, Info v2)
{
	Node* curr = *head;
	if (curr != NULL && curr->info == v1)
	{
		Node* tmp = newNode(v2);
		tmp->next = curr;
		*head = tmp;
	}
	
	while (curr != NULL && curr->next != NULL)
	{
		if (curr->next->info == v1)
		{
			Node* tmp = newNode(v2);
			tmp->next = curr->next;
			curr->next = tmp;
			curr = curr->next;
		}
		curr = curr->next;
	}
	
}

void PrintList(Node* node)
{
	while (node != NULL) {
		cout << node->info << " ";
		node = node->next;
	}
	cout << endl;
}

int main()
{
	Node* head = NULL;

	int v1, v2;
	v1 = 2;
	v2 = 6;

	push(&head, 4);
	push(&head, 7);
	push(&head, 2);
	push(&head, 8);
	push(&head, 1);
	push(&head, 2);

	cout << "List before deletion: ";
	PrintList(head);

	InputBefore(&head,v1,v2);

	cout << "List after deletion: ";
	PrintList(head);


	return 0;
}