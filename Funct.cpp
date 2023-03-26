#include "List.h"

pNode Input_List(istream& stream)
{
	int x;
	cin >> x;
	pNode newNode = Init_List(x);

	while (cin >> x)	Insert_Last(newNode, x);

	cin.clear(); cin.ignore();
	system("cls");
	return newNode;
}

pNode Init_List(int x)
{
	pNode newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void insertToHead(pNode& head, int x)
{
	pNode newNode = Init_List(x);
	newNode->next = head;
	head = newNode;
}

void Insert_Last(pNode head, int x)
{
	pNode newNode = Init_List(x);
	while (head->next)
		head = head->next;
	head->next = newNode;
}

void Print_List(pNode head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

bool Is_Empty(pNode& head)
{
	return !head;
}

void Delete_First_El(pNode& head)
{
	if (!Is_Empty(head))
	{
		pNode cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
	}
}

void Delete_After(pNode& a) 
{
	pNode cur = a->next;
	a->next = a->next->next;
	cur->next = NULL;
	delete cur;
}

pNode Search_Last_Negative(pNode head)
{
	pNode last = head;
	while (head)
	{
		if (head->data < 0)
		{
			last = head;
		}
		head = head->next;
	} return last;
}

void Delete_Negative(pNode& head, pNode a)
{
	if (head == a) Delete_First_El(head);
	else
	{
		pNode cur = head;
		while (cur->next != a) cur = cur->next;
		pNode tmp = cur->next;
		cur->next = cur->next->next;
		tmp->next = NULL;
		delete tmp;
	}
}

pNode Search_MinEl(pNode head)
{
	pNode m = head;
	int min = head->data;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			m = head;
		}
		head = head->next;
	} return m;
}

pNode Search_Min_Positive(pNode head)
{
	pNode minElem = head;
	while (head)
	{
		if (abs(head->data) < abs(minElem->data))
			minElem = head;
		head = head->next;
	} return minElem;
}

void addAfter(pNode& el, int x)
{
	pNode newNode = Init_List(x);
	pNode temp = el->next;
	el->next = newNode;
	newNode->next = temp;
}

void addBefore(pNode head, pNode& el, int x)
{
	pNode newNode = Init_List(x);
	while (head->next != el)
		head = head->next;
	head->next = newNode;
	newNode->next = el;
}

void Clear(pNode& head)
{
	while (head)
		Delete_First_El(head);
}