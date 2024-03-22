#include "TPolinom.h"
#include<vector>
#include<locale.h>
void PrintVector(vector<TPolinom> v, int currentpos)
{
cout << "������ ���������:\n\n";

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
int a, currentpos=0;//��������� �� ��������� ������ ������� �������
int first, second;//��������� � 1
while (1)
{	
	cout << "1-��������� �������\n2-��������\n3-���������\n4-��������� �� ���������\n5- +=\n6-������� ������\n";
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
		cout << "������� ������ ��������� � ������� �� ������ �������\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] + vect[second - 1];
		currentpos++;
		cout << "\n��������� ��������: " << vect[currentpos-1] << endl;
		break;
	case 3:
		cout << "������� ����������� � ����������\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] - vect[second - 1];
		currentpos++;
		cout << "\n��������� ���������: " << vect[currentpos-1] << endl;
		
		break;
	case 4:
		cout << "������� ������ �������� � ���������\n";
		cin >> first >> second;
		
		vect[currentpos] = vect[first - 1] *second;
		currentpos++;
		cout << "\n��������� ���������: " << vect[currentpos-1]<< endl;
		break;
	case 6:
		PrintVector(vect, currentpos);
		break;
	}
}
}