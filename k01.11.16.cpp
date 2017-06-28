// k01.11.16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

node* copy_list(node* last);
void add_list(node*&, int);

int main()
{
	node* lis1 = nullptr;
	for (int i = 1; i < 5; i++)
		add_list(lis1, i);
	node* copy_lis = copy_list(lis1);
	node* first = lis1->next;
	lis1 = lis1->next;
	while (lis1 != first) {
		cout << lis1->data << " ";
		lis1 = lis1->next;
	}

	cout << endl;
	first = copy_lis->next;
	copy_lis = copy_lis->next;
	while (copy_lis != first) {
		cout << copy_lis->data << " ";
		copy_lis = copy_lis->next;
	}

	system("pause");
    return 0;
}

void add_list(node*& last, int value) {
	node* add_node = new node;
	add_node->data = value;
	if (last != nullptr) {
		add_node->next = last->next;
		last->next = add_node;
	}
	else {
		add_node->next = add_node;
		last = add_node;
	}
}

node* copy_list(node* last) {
	if (last == nullptr) return nullptr;
	node* first = last->next;
	node* new_list = nullptr;
	last = last->next;
	while (last->next != first) {
		add_list(new_list, last->data);
	}
	return new_list;
}