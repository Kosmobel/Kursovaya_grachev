#include "menu.h"



string menu::getTitle() {
	return title_;
}
bool menu::checkPassword() {
	system("cls");
	string pass;
	cout << "��� ��������� ������� ������� ������: " << endl;
	cin >> pass;
	if (pass != password) {
		cout << "������ ��������, ������� ����� ������� ��� �����������" << endl;
		getchar();
		isAccessGranted = (pass == password);
		return isAccessGranted;
	}
}