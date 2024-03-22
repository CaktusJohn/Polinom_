#include "TPolinom.h"
TPolinom::TPolinom(int monoms[][2], int n)
{
	TMonom tmp(0, -1);
	pHead->val = tmp;
	for (int i = 0; i < n; i++)
	{
		TMonom monom(monoms[i][0], monoms[i][0]);
		InsLast(monom);
	}
}
TPolinom::TPolinom(TPolinom& pol)
{
	TMonom tmp(0, -1);
	pHead->val = tmp;
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		TMonom monom = pol.GetCurr();
		InsLast(monom);
	}
}
TPolinom& TPolinom::operator= (TPolinom& pol)
{
	DelList();
	for (pol.Reset(); !pol.IsEnd(); pol.GoNext())
	{
		TMonom monom = pol.GetCurr();
		InsLast(monom);
	}
	return *this;
}
void TPolinom::addMonom(TMonom monom)
{
	if (pCurr==nullptr)
	{
		InsFirst(monom);
	}
	pCurr=pFirst;
	while (monom.GetIndex() < pCurr->val.GetIndex())
	{
		GoNext();
	}
	if (pCurr->val == monom)
	{
		if (pCurr->val.GetCoeff() + monom.GetCoeff() == 0)
			DelCurr();
		else
			pCurr->val.SetCoeff(monom.GetCoeff());
	}
	else
	{
		InsCurr(monom);
	}
}

TPolinom TPolinom::operator+ (TPolinom& pol)
{
	TPolinom res(*this);
	res.Reset();
	pol.Reset();
	while (res.pCurr != res.pStop && pol.pCurr != pol.pStop)
	{
		if (res.GetCurr().GetIndex() < pol.GetCurr().GetIndex())
		{
			res.InsCurr(pol.GetCurr());
			pol.GoNext();
		}
		else
			if (res.GetCurr().GetIndex() > pol.GetCurr().GetIndex())
			{
				res.GoNext();
			}
			else
			{
				res.pCurr->val.SetCoeff(pol.pCurr->val.GetCoeff() + res.pCurr->val.GetCoeff());
				if (res.pCurr->val.GetCoeff() != 0)
				{
					pol.GoNext();
					res.GoNext();
				}
				else
				{
					res.DelCurr();
					pol.GoNext();
				}
			}

	}
	return res;
}
TPolinom TPolinom::operator- (TPolinom& pol)
{
	TPolinom res = (*this + pol* (-1));
	return res;
}
TPolinom& TPolinom::operator+= (TPolinom& pol)
{
	Reset();
	pol.Reset();
	while (pCurr != pStop && pol.pCurr != pol.pStop)
	{
		if (GetCurr().GetIndex() < pol.GetCurr().GetIndex())
		{
			InsCurr(pol.GetCurr());
			pol.GoNext();
		}
		else
			if (GetCurr().GetIndex() > pol.GetCurr().GetIndex())
			{
				GoNext();
			}
			else
			{
				pCurr->val.SetCoeff(pol.pCurr->val.GetCoeff() + pCurr->val.GetCoeff());
				if (pCurr->val.GetCoeff() != 0)
				{
					pol.GoNext();
					GoNext();
				}
				else
				{
					DelCurr();
					pol.GoNext();
				}
			}

	}
	return *this;
}

TPolinom TPolinom::operator* (double c)
{	
	TPolinom res(*this);
	if (c == 0)
	{
		res.DelList();
	}
	else
	{
	
		res.Reset();
		while (!res.IsEnd())
		{
			res.pCurr->val.SetCoeff(res.pCurr->val.GetCoeff() * c);
			res.GoNext();
		}
	}
	return res;
}


void TPolinom::EnterPolinom()
{
	int i; double c;
	cout << "Введите коэффициент и индекс добавляемого монома. Чтобы закончить ввод введите 0\n";
	cin >> c >> i;
	if (i < 100) throw ("wrong index");
	while (1)
	{
		TMonom newmonom(c, i);
		addMonom(newmonom);
		cin >> c;
		if (c == 0 ) break;
		cin >> i;
		if ( i == 0) break;
		if (i < 100) throw ("wrong index");
		
	}
}
