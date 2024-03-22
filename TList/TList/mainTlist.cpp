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
		cout << "Вставить первый - 1\n" << "Вставить перед текущим - 2\n" << "Вставить последний - 3\n" << "Удалить первый - 4\n" << "Удалить текущий - 5\n" << "Удалить последний - 6\n" << "Установить позицию - 7\n";
		cin >> sw;
		switch (sw)
		{
		case(1):
			cout << "Введите элемент\n";
			cin >> a;
			list.InsFirst(a);
			list.PrintList();
			break;
		case(2):
			cout << "Введите элемент\n";
			cin >> a;
			list.InsCurr(a);
			list.PrintList();
			break;
		case(3):
			cout << "Введите элемент\n";
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
			cout << "Введите позицию\n";
			cin >> a;
			list.SetPos(a);
			list.PrintList();
			break;
		}
	}
	

}*/