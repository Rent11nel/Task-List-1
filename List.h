#pragma once

#include <iostream>
#include <Windows.h>

struct Node
{
	int data;
	Node* next;
};

using std::cin;
using std::cout;
using pNode = Node*;
using std::istream;

pNode Input_List(istream& stream);
void Insert_Last(pNode head, int x);
pNode Init_List(int x);
void Print_List(pNode head);
bool Is_Empty(pNode& head);
void Delete_First_El(pNode& head);
void Delete_After(pNode& a);
pNode Search_Last_Negative(pNode head);
void Delete_Negative(pNode& head, pNode a);
pNode Search_MinEl(pNode head);
void addAfter(pNode& elem, int x);
void addBefore(pNode head, pNode& elem, int x);
void insertToHead(pNode& head, int x);
pNode Search_Min_Positive(pNode head);
void Clear(pNode& head);