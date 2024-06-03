#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <Windows.h>
using namespace std;

class Account {
	public:
		Account();
		void InitAccount();
		void Change();
		void View();
		void Withdraw();
		void Put();
		void Percent();
		void ToDollars();
		void ToEuro();
		void SumCursive(float Summ);
		void Clean();
	private:
		string Name;
		int Number;
		float AcPercent;
		float Summ;
		char s[100] = "\0";
};

int p;
float q, o, pr, doll, eur, numb;
bool ret = true, ret1 = true;

Account::Account() { Number = AcPercent = Summ = 0; }


void Account::InitAccount() {

	cout << "������������� ��������. ������� ������ : " << endl;
	while (ret1 == true) {

		cout << "������� ������� : ";
		cin.ignore(255, '\n');
		getline(cin, Name);

		cout << "������� ����� ����� : ";
		cin >> Number;

		if (!cin.good()) {
			cout << "� ������ ����� �� ����� ���� ����." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		cout << "������� ������� ���������� : ";
		cin >> AcPercent;
		if (!cin.good()) {
			cout << "������� ���������� �� ����� ���� ������." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		cout << "�����(� ������) : ";
		cin >> Summ;
		if (!cin.good()) {
			cout << "� ���� ����� �� ����� ���� ����." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		numb = Summ;
	}

	cout << "������������� ���������.";
}

void Account::Change() {

	cout << "������� ������� ������ ��������� ����� : ";
	cin.ignore(255, '\n');
	getline(cin, Name);
}

void Account::View() {

	cout << "��� ���� : " << endl;

	cout << "�������� : " << Name << endl;
	cout << "����� ����� : " << Number << endl;
	cout << "������� ���������� : " << AcPercent << endl;
	cout << "������ : " << Summ << endl;

	system("pause");
}

void Account::Withdraw() {

	ret1 = true;

	while (ret1 == true) {

		cout << "������� �����, ������� ������ ����� : ";
		cin >> o;
		if (!cin.good()) {
			cout << "� ���� ����� �� ����� ���� ����." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		if (o > Summ) {
			cout << "������������ ������� ��� ������! " << endl;
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

		Summ -= o;

		cout << "��� ������ : " << Summ << endl;

		numb = Summ;

	system("pause");

}

void Account::Put() {

	ret1 = true;

	while (ret1 == true) {

		cout << "������� �����, ������� ������ �������� �� ���� : ";
		cin >> q;
		if (!cin.good()) {
			cout << "� ���� ����� �� ����� ���� ����." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	Summ += q;

	cout << "��� ������ : " << Summ << endl;

	numb = Summ;

	system("pause");
}

void Account::Percent() {

	pr = Summ / 100 * AcPercent;

	Summ += pr;

	cout << "��� ������ ����� ���������� ��������� : " << Summ;

	numb = Summ;

	system("pause");
}

void Account::ToDollars() {

	doll = Summ / 58, 18;

	cout << "������� � ������� ��������. \n "
		<< "��� ������ � �������� : " << doll << endl;

	system("pause");
}

void Account::ToEuro() {

	eur = Summ / 55, 53;

	cout << "������� � ���� ��������. \n "
		<< "��� ������ � ���� : " << eur << endl;

	system("pause");
}

void Account::SumCursive(float Summ) {

	int position = 0;
	int x[6];
	int div = 100000;
	float var = numb;
	int rest;
	for (int i = 0; i < 6; i++)
	{
		rest = var / div;
		x[i] = rest;
		var = var - rest * div;
		div = div / 10;
	}


	switch (x[0])
	{
		case 1: strcpy(s, "��� ����� "); break;
		case 2: strcpy(s, "������ ����� "); break;
		case 3: strcpy(s, "������ ����� "); break;
		case 4: strcpy(s, "��������� ����� "); break;
		case 5: strcpy(s, "������� ����� "); break;
		case 6: strcpy(s, "�������� ����� "); break;
		case 7: strcpy(s, "������� ����� "); break;
		case 8: strcpy(s, "��������� ����� "); break;
		case 9: strcpy(s, "��������� ����� "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[1])
	{
		case 1:
			switch (x[2])
			{
				case 0: strcpy(s + position, " ������ ����� "); break;
				case 1: strcpy(s + position, " ����������� ����� "); break;
				case 2: strcpy(s + position, " ���������� ����� "); break;
				case 3: strcpy(s + position, " ���������� ����� "); break;
				case 4: strcpy(s + position, " ������������ �����"); break;
				case 5: strcpy(s + position, " ���������� ����� "); break;
				case 6: strcpy(s + position, " ����������� �����"); break;
				case 7: strcpy(s + position, " ���������� ����� "); break;
				case 8: strcpy(s + position, " ������������ ����� "); break;
				case 9: strcpy(s + position, " ������������ ����� "); break;
			}
			x[2] = 0;
			position = strlen(s);
			break;
		case 2: strcpy(s + position, " �������� ����� "); break;
		case 3: strcpy(s + position, " �������� ����� "); break;
		case 4: strcpy(s + position, " ����� ����� "); break;
		case 5: strcpy(s + position, " ��������� ����� "); break;
		case 6: strcpy(s + position, " ���������� ����� "); break;
		case 7: strcpy(s + position, " ��������� ����� "); break;
		case 8: strcpy(s + position, " ����������� ����� "); break;
		case 9: strcpy(s + position, " ��������� ����� "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[2])
	{
		case 1: strcpy(s + position, " ���� ������ "); break;
		case 2: strcpy(s + position, " ��� ������ "); break;
		case 3: strcpy(s + position, " ��� ������ "); break;
		case 4: strcpy(s + position, " ������ ������ "); break;
		case 5: strcpy(s + position, " ���� ����� "); break;
		case 6: strcpy(s + position, " ����� ����� "); break;
		case 7: strcpy(s + position, " ���� ����� "); break;
		case 8: strcpy(s + position, " ������ ����� "); break;
		case 9: strcpy(s + position, " ������ ����� "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[3])
	{
		case 1: strcpy(s + position, " ��� "); break;
		case 2: strcpy(s + position, " ������ "); break;
		case 3: strcpy(s + position, " ������ "); break;
		case 4: strcpy(s + position, " ��������� "); break;
		case 5: strcpy(s + position, " ������� "); break;
		case 6: strcpy(s + position, " �������� "); break;
		case 7: strcpy(s + position, " ������� "); break;
		case 8: strcpy(s + position, " ��������� "); break;
		case 9: strcpy(s + position, " ��������� "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[4])
	{
		case 1:
			switch (x[5])
			{
				case 0: strcpy(s + position, " ������ "); break;
				case 1: strcpy(s + position, " ����������� "); break;
				case 2: strcpy(s + position, " ���������� "); break;
				case 3: strcpy(s + position, " ���������� "); break;
				case 4: strcpy(s + position, " ������������ "); break;
				case 5: strcpy(s + position, " ���������� "); break;
				case 6: strcpy(s + position, " ����������� "); break;
				case 7: strcpy(s + position, " ���������� "); break;
				case 8: strcpy(s + position, " ������������ "); break;
				case 9: strcpy(s + position, " ������������ "); break;
			}
			x[5] = 0;
			position = strlen(s);
			break;
		case 2: strcpy(s + position, " �������� "); break;
		case 3: strcpy(s + position, " �������� "); break;
		case 4: strcpy(s + position, " ����� "); break;
		case 5: strcpy(s + position, " ��������� "); break;
		case 6: strcpy(s + position, " ���������� "); break;
		case 7: strcpy(s + position, " ��������� "); break;
		case 8: strcpy(s + position, " ����������� "); break;
		case 9: strcpy(s + position, " ��������� "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[5]) {
		case 1: strcpy(s + position, " ���� "); break;
		case 2: strcpy(s + position, " ��� "); break;
		case 3: strcpy(s + position, " ��� "); break;
		case 4: strcpy(s + position, " ������ "); break;
		case 5: strcpy(s + position, " ���� "); break;
		case 6: strcpy(s + position, " ����� "); break;
		case 7: strcpy(s + position, " ���� "); break;
		case 8: strcpy(s + position, " ������ "); break;
		case 9: strcpy(s + position, " ������ "); break;
		default: break;
	}
	position = strlen(s);

	cout << Summ << " " << s << endl;

	cin.get();

	system("pause");
}

void Account::Clean() {

	for (int j = 0; j != 100; j++) {
		s[j] = '\0';
	}
}

int main() {
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "�������� ������� ���� �-31" << endl;

	Account t;

	while (ret == true) {

		cout << "��� �� ������ ������� \n"
			<< "1 - ������� ���� \n"
			<< "2 - �������� ��������� ����� \n"
			<< "3 - ������� ����������� � ����� \n"
			<< "4 - ����� ������ \n"
			<< "5 - �������� ������ \n"
			<< "6 - ��������� �������� \n"
			<< "7 - ��������� � ������� \n"
			<< "8 - ��������� � ���� \n"
			<< "9 - ������� ����� �������� \n"
			<< "10 - ��������� ��������� \n"
			<< "11 - ��������� ��������� \n";
		cin >> p;
		switch (p)
		{
		case 1:
			t.InitAccount();
			break;
		case 2:
			t.Change();
			break;
		case 3:
			t.View();
			break;
		case 4:
			t.Withdraw();
			break;
		case 5:
			t.Put();
			break;
		case 6:
			t.Percent();
			break;
		case 7:
			t.ToDollars();
			break;
		case 8:
			t.ToEuro();
			break;
		case 9:
			t.SumCursive(numb);
			t.Clean();
			break;
		case 10:
			ret = true;
			cin.clear();
			break;
		case 11:
			ret = false;
			return 0;
			break;
		}
	}
}
