#include "submenu.h"
#include "windows.h"
#include <iostream>
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define BLACK "\033[1;30m"




void starbar(int width)
{

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 48);
	for (int i = 1; i < width; i++) { cout <<  "*"; }
	cout << RESET;
}



void subMenu::run() {
	if (getProtected() && !getAccessGranted()) {
		if (!this->checkPassword()) {
			return;
		}
	}
	while (true) {
		system("MODE CON COLS=70 LINES=22");
		system("cls");
		system("Color F0");
		starbar(70);
		cout << "\n";
		cout << GREEN << "�������� ��������: " << BLACK << endl;

		for (int i = 0; i < (int)items_.size(); i++) {
			cout << i + 1 << ". " << items_[i]->getTitle() << (items_[i]->getProtected() ? "(*)" : "") << endl;
		}
		cout << "������� ����� (q ��� ������): " << BLACK;
		string input;
		cin >> input;
		cin.ignore(100, '\n');
		if (input == "q") break;
		int choice = 0;
		try {
			choice = stoi(input);
		}
		catch (const invalid_argument&) {
			cout << "�������� ����\n";
			getchar();
			continue;
		}
		if (choice > 0 && choice <= (int)items_.size()) ((menu*)items_[choice - 1])->run();
		else {
			cout << "�������� ����\n";
			getchar();
		}
	}
}