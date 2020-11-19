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

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	insert(head, 3);
	insert(head, 2);
	insert(head, 1);
	insert(head, 0);
	print(head);
}
