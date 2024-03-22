#include "TPolinom.h"
#include<vector>
#include<locale.h>
void PrintVector(vector<TPolinom> v, int currentpos)
{
cout << "Вектор полиномов:\n\n";

for (int i = 0; i < currentpos; i++)
{
	
	cout << "|"<<i+1<<"| "<<v[i] << endl;
}
cout << endl;
}

int main()
{
setlocale(LC_CTYPE, "Russian");
vector<TPolinom> vect(20);
TPolinom pol;
int a, currentpos=0;//указывает на последний пустой элемент вектора
int first, second;//нумерация с 1
while (1)
{	
	cout << "1-добавиьть полином\n2-сложение\n3-вычитание\n4-умножение на константу\n5- +=\n6-вывести вектор\n";
	cin >> a;
	switch (a)
	{
	case 1:
		pol.EnterPolinom();
		vect[currentpos] = pol;
		currentpos++;
		PrintVector(vect, currentpos);
		pol.DelList();
		break;
	case 2:
		cout << "Введите номера полиномов с которые вы хотите сложить\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] + vect[second - 1];
		currentpos++;
		cout << "\nРезультат сложения: " << vect[currentpos-1] << endl;
		break;
	case 3:
		cout << "Введите уменьшаемое и вычитаемое\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] - vect[second - 1];
		currentpos++;
		cout << "\nРезультат вычитания: " << vect[currentpos-1] << endl;
		
		break;
	case 4:
		cout << "Введите номера полинома и константу\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] *second;
		currentpos++;
		cout << "\nРезультат умножения: " << vect[currentpos-1]<< endl;
		break;
	case 6:
		PrintVector(vect, currentpos);
		break;
	}
}
}