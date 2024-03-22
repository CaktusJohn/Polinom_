#pragma once
#include <iostream>
using namespace std;
class TMonom
{
private:
	double coeff;
	int index;
public:
	void SetCoeff(double _coeff)
	{
		coeff = _coeff;
	}
	void SetIndex(int _index)
	{
		index = _index;
	}
	int GetIndex()
	{
		return index;
	}
	double GetCoeff()
	{
		return coeff;
	}
	TMonom()
	{
		coeff = 0;
		index = 0;
	}
	TMonom(double c, int i)
	{
		coeff = c;
		index = i;
	}
	void operator= (TMonom& monom)
	{
		coeff = monom.coeff;
		index = monom.index;
	}
	friend ostream& operator<< (ostream& os, TMonom mon)
	{
		os << mon.coeff << "\n" << "___\n" << mon.index;
		return os;
	}
	bool operator== (TMonom monom)
	{
		if ((index == monom.index) && (coeff == monom.coeff))
		{
			return true;
		}
		else return false;
	}
};

