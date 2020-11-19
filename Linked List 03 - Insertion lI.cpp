# C_B_Linked_lists
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void insert(node* &head, int d)
{
	if (head == NULL)
	{
		head = new node(d);
		return;
	}

	node* n = new node(d);
	n->next = head;
	head = n;
}

void print(node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int length(node* head)
{
	int c = 0;
	while (head->next != NULL)
	{
		c++;
		head = head->next;
	}
	return c;
}
void insert_at_tail(node* head, int d)
{
	if (head == NULL)
	{
		head = new node(d);
		return;
	}
	node* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new node(d);
	return;
}

void insert_at_middle(node* &head, int d, int p)
{
	if (head == NULL)
	{
		insert(head, d);
	}
	else if (length(head) < p)
	{
		insert_at_tail(head, d);
	}
	else
	{
		int jump = 1;
		node* temp = head;
		while (jump <= p - 1)
		{
			temp = temp->next;
			jump++;
		}
		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	insert(head, 5);
	insert(head, 2);
	insert(head, 1);
	insert(head, 0);
	print(head);
	cout << endl;
	insert_at_middle(head, 4, 3);
	insert_at_tail(head, 7);
	print(head);
}
