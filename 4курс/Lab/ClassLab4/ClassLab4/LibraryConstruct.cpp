#include "Header.h"
#include "Library.cpp"

Library::Library() { year = price = 0; }

void Library::newBook() 
{

	cout << "������� ������� ������ ����� : ";
	cin.ignore(255, '\n');
	getline(cin, Author);

	cout << "������� �������� ����� : ";
	cin.ignore(255, '\n');
	getline(cin, Title);

	cout << "������� ��� ������� ����� : ";
	cin >> year;

	cout << "������� �������� ������������ : ";
	cin.ignore(255, '\n');
	getline(cin, publisher);

	cout << "������� ���� ����� : ";
	cin >> price;

	system("pause");
}

void Library::getBook() 
{
	cout << "����� : " << Author << endl;
	cout << "����� : " << Title << endl;
	cout << "��� �������  : " << year << endl;
	cout << "������������ : " << publisher << endl;
	cout << "���� �����  : " << price << endl;

	system("pause");
}