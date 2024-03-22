#pragma once
#include"THeadList.h"
class TPolinom :public THeadList<TMonom>
{
public:
	
	TPolinom(int monoms[][2]=0, int km=0);
	TPolinom(TPolinom& pol);
	TPolinom& operator+= ( TPolinom &pol);
	TPolinom operator+ (TPolinom& pol);
	TPolinom operator- (TPolinom& pol);
	TPolinom& operator= (TPolinom& pol);
	TPolinom operator* (double c);
	void addMonom(TMonom m);
	friend ostream& operator<< (ostream& os, TPolinom& pol)
	{
		pol.Reset();
		int x, y, z;
		x = pol.GetCurr().GetIndex() / 100;
		y = pol.GetCurr().GetIndex() % 100 / 10;
		z = pol.GetCurr().GetIndex() % 10;
		os << pol.GetCurr().GetCoeff() << "(x^" << x << "y^" << y << "z^" << z<<")";
		pol.GoNext();
		while (!pol.IsEnd())
		{
			x = pol.GetCurr().GetIndex() / 100;
			y = pol.GetCurr().GetIndex() % 100 / 10;
			z = pol.GetCurr().GetIndex() % 10;
			if (pol.GetCurr().GetCoeff() > 0)
				os << "+";

			os << pol.GetCurr().GetCoeff() << "(x^" << x << "y^" << y << "z^" << z<<")";
			pol.GoNext();
		}
		return os;
	}
	void EnterPolinom();
};
