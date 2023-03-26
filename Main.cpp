#include "List.h"

int main()
{
	SetConsoleOutputCP(1251);
	cout << "Введите элементы списка (^Z для окончания ввода): ";
	pNode newNode = Input_List(cin);

	cout << "Исходный список: ";  Print_List(newNode);

	pNode a = Search_Last_Negative(newNode);
	Delete_Negative(newNode, a);

	int x;
	cout << "\nВведите заданное число: ";
	cin >> x;

	a = Search_MinEl(newNode);

	if (a == newNode) insertToHead(newNode, x);
	else addBefore(newNode, a, x);

	a = Search_Min_Positive(newNode);
	addAfter(a, x);

	std::cout << "\n\n";
	std::cout << "Список после пробразований: ";  Print_List(newNode);
	std::cout << "\n\n";

	Clear(newNode);

	system("pause");

	return 0;
}