/*#include "TList.h"
#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	int sw; int a;
	setlocale(LC_CTYPE, "Russian");
	TList<int> list;
	while (1)
	{
		cout << "�������� ������ - 1\n" << "�������� ����� ������� - 2\n" << "�������� ��������� - 3\n" << "������� ������ - 4\n" << "������� ������� - 5\n" << "������� ��������� - 6\n" << "���������� ������� - 7\n";
		cin >> sw;
		switch (sw)
		{
		case(1):
			cout << "������� �������\n";
			cin >> a;
			list.InsFirst(a);
			list.PrintList();
			break;
		case(2):
			cout << "������� �������\n";
			cin >> a;
			list.InsCurr(a);
			list.PrintList();
			break;
		case(3):
			cout << "������� �������\n";
			cin >> a;
			list.InsLast(a);
			list.PrintList();
			break;
		case(4):
			list.DelFirst();
			list.PrintList();
			break;
		case(5):
			list.DelCurr();
			list.PrintList();
			break;
		case(6):
			list.DelLast();
			list.PrintList();
			break;
		case(7):
			cout << "������� �������\n";
			cin >> a;
			list.SetPos(a);
			list.PrintList();
			break;
		}
	}
	

}*/