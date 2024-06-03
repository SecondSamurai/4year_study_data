#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Date {
public:
	Date();
	void setDate(int, int, int);
	int getDay();
	int getMonth();
	int getYear();
private:
	int EDay;
	int EMonth;
	int EYear;
	int enrDate;
	int yesDate;
	int checkEDay(int);
};

class Payment {
public:
	Payment();
	void newEmpl();
	void View();
	void experince();
	void charges();
	void retention();
	void clearPay();
private:
	string Name;
	string SecondName;
	string Patronymic;
	float Salary;
	Date enrDate;
	Date yesDate;
	float AcPercent;
	int Tax;
	int WorkDays;
	int SWorkDays;
	float Charg;
	float Ret;
	float SumClear;
};

bool ret = true, ret1 = true;
int p, o, dy, mn, yr, q, D, Dy, k, l, M, Y;

Payment::Payment() { Salary = AcPercent = Tax = WorkDays = SWorkDays = Charg = Ret = 0; }
Date::Date() { EDay = EMonth = EYear = 0; }

void Payment::newEmpl() {

	while (ret1 == true) {
		cout << "�� � ���� ������ ����������, ��� �� ������ ������� : \n"
			<< "1 - ������ ��� ����������. \t" << " 2 - ������ ����� ����������. \n"
			<< "3 - ������ ����. \t\t" << " 4 - ������ ��������. \n"
			<< "5 - ������ ��������� ������� ����. " << " 6 - ������ ���������� ������������ ����. \n"
			<< "7 - ��������� ��������. \n";
		cin >> q;
		switch (q) {
		case 1:
			cout << "������� ������� ���������� : ";
			cin.ignore(255, '\n');
			getline(cin, SecondName);

			cout << "������� ��� ���������� : ";
			cin.ignore(255, '\n');
			getline(cin, Name);

			cout << "������� �������� ���������� : ";
			cin.ignore(255, '\n');
			getline(cin, Patronymic);
			break;
		case 2:
			cout << "������� ����� ���������� : ";
			cin >> Salary;
			break;
		case 3:
			cout << "������� ���� : " << endl;
			cout << "���� : ";
			cin >> dy;
			cout << "����� : ";
			cin >> mn;
			cout << "��� : ";
			cin >> yr;
			cout << "��� \n"
				<< "1 - ���� ���������� ���������� � ����. \n"
				<< "2 - ����������� ����. \n";
			cin >> p;
			switch (p) {
				case 1:
					cout << "���� ���������� ���������� � ���� : ";
					enrDate.setDate(dy, mn, yr);
					cout << endl;
					continue;
				case 2:
					cout << "����������� ���� : ";
					yesDate.setDate(dy, mn, yr);
					cout << endl;
					continue;
			}
			break;
		case 4:
			cout << "������� �������� : ";
			cin >> AcPercent;
			break;
		case 5:
			cout << "���������� ������� ���� : ";
			cin >> WorkDays;
			break;
		case 6:
			cout << "���������� ������������ ���� : ";
			cin >> SWorkDays;
			break;
		case 7:
			ret1 = false;
			break;
		}
	}

}

void Payment::View() {

	cout << Name << SecondName << Patronymic << endl;
	cout << Salary << endl;
	cout << enrDate.getDay() << "." << enrDate.getMonth() << "." << enrDate.getYear() << endl;
	cout << yesDate.getDay() << "." << yesDate.getMonth() << "." << yesDate.getYear() << endl;
	cout << AcPercent << endl;
	cout << WorkDays << endl;
	cout << SWorkDays << endl;

	system("pause");
}

void Payment::experince() {

	cout << "���������� ����� : " << endl;

	if (yesDate.getYear() > enrDate.getYear())
		Y = yesDate.getYear() - enrDate.getYear();

		M = yesDate.getMonth() - enrDate.getMonth();

		if (Y == 0 && M > 0 && yesDate.getDay() <= enrDate.getDay()) {
			D = yesDate.getDay() - enrDate.getDay();
			D = enrDate.getDay() + D;
			cout << "���� ���������� : " << D << " ����.";
		}
		if (Y > 0 && yesDate.getDay() <= enrDate.getDay()) {
			D = yesDate.getDay() - enrDate.getDay();
			D = enrDate.getDay() + D;
			Dy = Y * 365;
			if (M >= 1 && D < 31) {
				M -= 1;
			}
			if (D > 30) {
				M += 1;
				D -= 30;
			}
			cout << "���� ���������� : " << Dy << " ����. ��� \n" << Y << " ���  " << M << " ������� � " << D << " ����.";
		}
		else {
			D = yesDate.getDay() - enrDate.getDay();
			Dy = Y * 365;
			if (M = 1 && D < 31) 
				M -= 1;
			if (D > 30) {
				M += 1;
				D -= 30;
			}
			cout << "���� ���������� : " << Dy << " ����. ��� \n" << Y << " ���  " << M << " ������� � " << D << " ����.";
		}
	system("pause");
}

void Payment::charges() {
	
	cout << "���������� ����������� �����  " << endl;
	system("pause");

	Charg = Salary / WorkDays;
	Charg *= SWorkDays;
	l = (Charg / 100) * AcPercent;
	Charg += l;

	cout << "����������� ����� : " << Charg << endl;
	system("pause");
}

void Payment::retention() {

	cout << "���������� ���������� �����  " << endl;
	system("pause");

	k = Charg / 100;
	Tax = Charg / 100 * 13;
	Ret = k + Tax;

	cout << "���������� ����� : " << Ret << endl;
	system("pause");
}

void Payment::clearPay() {
	cout << "���������� ������� " << endl;
	system("pause");

	SumClear = Charg - Ret;

	cout << "������� : " << SumClear << endl;
	system("pause");
}

void Date::setDate(int dy, int mn, int yr) {

	if (mn > 0 && mn <= 12) {
		EMonth = mn;
	}
	else {
		EMonth = 1;
		cout << "�������� ������ " << mn
			<< " �������, ����������� �������� ������ - " << EMonth
			<< endl;
	}
	if (yr >= 1965) {
		EYear = yr;
	}
	else {
		EYear = 1965;
		cout << "�������� ���� " << yr
			<< " �������, ����������� �������� ���� - " << EYear
			<< endl;
	}
	EDay = checkEDay(dy);

	cout << EDay << "." << EMonth << "." << EYear;

	cout << endl;
}

int Date::checkEDay(int dy) {

	static int daysPerMonth[13] =
	{ 0, 31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30 , 31 };

	if (dy > 0 && dy <= daysPerMonth[EMonth])
		return dy;

	if (EMonth == 2 && dy == 29
		&& (EYear % 400 == 0 || (EYear % 4 == 0 && EYear % 100 != 0)))
		return dy;

	cout << "�������� ��� " << dy
		<< " �������, ����������� �������� 1. " << endl;
	return 1;
}

int Date::getDay() {

	return EDay;
}

int Date::getMonth() {

	return EMonth;
}

int Date::getYear() {

	return EYear;
}

int main() {

	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Payment t;

	cout << "�������� ������� ���� �-31" << endl;

	while (ret == true) {
		cout << "��� �� ������ ������� : \n"
			<< "1 - ��������� ���������� � ����. \t" << " 2 - �������� ������ ����������. \n"
			<< "3 - ��������� ����. \t" << " 4 - ��������� ����������� �����. \n"
			<< "5 -  ��������� ���������� �����. " << " 6 - ��������� �����, ���������� �� ����. \n"
			<< "7 - ��������� ���������. \n";
		cin >> o;
		switch (o) {
		case 1:
 			t.newEmpl();
			break;
		case 2:
			t.View();
			break;
		case 3:
			t.experince();
			break;
		case 4:
			t.charges();
			break;
		case 5:
			t.retention();
			break;
		case 6:
			t.clearPay();
			break;
		case 7:
			ret = false;
			return 0;
			break;
		}
	}
}