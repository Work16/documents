// problem 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int value;
	list *next;
};

void add(list *&beg, int number)
{
	if (beg)
	{
		list *temp = new list;
		temp->value = number;
		temp->next = beg;
		beg = temp;
	}
	else
	{
		beg = new list;
		beg->value = number;
		beg->next = NULL;
	}
}
void add2(list *&beg, int number)
{
	if (beg)
	{
		list *temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = new list;
		temp->next->value = number;
		temp->next->next = NULL;
	}
	else
	{ 
		beg = new list;
		beg->value = number;
		beg->next = NULL;
	}
}
void show(list *beg)
{
	while (beg)
	{
		cout << beg->value<<" ";
		beg = beg->next;
	}
	cout << endl;
}
void destroy(list *&beg)
{
	while (beg)
	{
		list *temp = beg->next;
		delete(beg);
		beg = temp;
	}
}
void deleting_element(list *&beg, int key)
{
	list *temp = beg;
	while (temp->next->value != key)
		temp = temp->next;
	if (temp->next)
	{
		list *del = temp->next;
		temp->next = temp->next->next;
		delete (del);
	}
}
void twolists(list *beg, list*&beg1, list *&beg2,int key_diference)
{
	while (beg)
	{
		if (beg->value > key_diference)
			add2(beg1, beg->value);
		else
			add2(beg2, beg->value);
		beg = beg->next;
	}
}
int main()
{
	setlocale(LC_ALL,"Russian");
	list *beg(NULL) ,*beg1(NULL),*beg2(NULL);
	int amount_elements,element,key_del,key_diference;
	cout << "¬ведите количество элементов:\n";
	cin >> amount_elements;
	system("cls");
	for (int i = 0;i < amount_elements;i++)
	{
		cout << "¬ведите " << i + 1 << " элемент списка:\n";
		cin >> element;
		add2(beg, element);
	}
	char agreed;
	cout << "∆елаете ли вы удалить какое-то значение?\n";
	cin >>agreed;
	if (agreed == 'y')
	{
		cout << "¬ведите удал€емое значение:\n";
		cin >> key_del;
		deleting_element(beg, key_del);
		system("cls");
		cout << "∆елаете ли что-то еще ввести:\n";
		cin >> agreed;
		if (agreed == 'y')
		{
			cout << "¬ведите количество элементов которые хотите добавить:\n";
			cin >> amount_elements;
			system("cls");
			for (int i = 0;i < amount_elements;i++)
			{
				cout << "¬ведите "  << " элемент списка:\n";
				cin >> element;
				add2(beg, element);
			}
		}
	}
	system("cls");
	show(beg);
	cout << "¬ведите значение дл€ делени€ списка:\n";
	cin >> key_diference;
	twolists(beg, beg1, beg2, key_diference);
	show(beg1);
	show(beg2);
	destroy(beg);
	destroy(beg1);
	destroy(beg2);
	system("pause");
    return 0;
}

 