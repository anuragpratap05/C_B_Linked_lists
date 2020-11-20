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
void delete_at_head(node* &head)
{
	if (head == NULL)
	{
		return;
	}
	node* temp = head->next;
	delete head;
	head = temp;

}
bool search(node* head, int key)
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return true;

		}
		temp = temp->next;
	}
	return false;
}

node* takeinput(node*&head)
{
	int d;
	cin >> d;
	//node*head = NULL;
	while (d != -1)
	{
		insert(head, d);
		cin >> d;
	}
	return head;
}

void reverse(node* &head)
{
	node* c = head;
	node* p = NULL;
	node* temp;
	while (c != NULL)
	{
		temp = c->next;
		c->next = p;
		p = c;
		c = temp;
	}
	head = p;
}

node* recursive_reverse(node* head)
{
	if (head->next == NULL or head == NULL)
	{
		return head;
	}
	node* shead = recursive_reverse(head->next);
	node*temp = head->next;
	/*node* temp = shead;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}*/
	head->next = NULL;
	temp->next = head;
	return shead;

}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* head = NULL;
	takeinput(head);
	print(head);
	node* ans = recursive_reverse(head);
	cout << endl;
	print(ans);
	//node* head = NULL;
	/*insert(head, 5);
	insert(head, 2);
	insert(head, 1);
	insert(head, 0);
	print(head);
	cout << endl;
	insert_at_middle(head, 4, 3);
	insert_at_tail(head, 7);
	print(head);
	cout << endl;
	delete_at_head(head);
	print(head);
	if (search(head, 56))
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}*/
}
