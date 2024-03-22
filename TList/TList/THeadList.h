#pragma once
#include "TList.h"
#include"TMonom.h"
template <class T>
class THeadList:public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		
		pStop =pLast= pFirst = pPr = pCurr = nullptr;
		pos = 0;
		len = 0;
	}
	THeadList(const THeadList& list);
	~THeadList()
	{
		TList::DelList();
		delete pHead;
	}
	 void InsFirst(T val) override
	{
		TList<T>::InsFirst(val);
		pLast->pNext = pHead;
		pStop = pHead;
		pHead->pNext = pFirst;
	}
	 void InsCurr(T val) override
	{
		TList<T>::InsCurr(val);
		pHead->pNext = pFirst;
	}
	 void InsLast(T val) override
	{
		TList<T>::InsLast(val);
		pLast->pNext = pHead;
		pStop = pHead;
		pHead->pNext = pFirst;
	}
	 void DelFirst() override
	{
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}
	 void DelCurr() override
	{
		TList<T>::DelCurr();
		if (pCurr == pFirst)
		{
			pHead->pNext = pFirst;
		}
	}
	 void DelLast() override
	{
		TList<T>::DelLast();
		pLast->pNext = pHead;
		pStop = pHead;
		pHead->pNext = pFirst;
	}
	 void PrintList() override;
	
};
template <class T>
void THeadList<T>::PrintList()
{
	if (pFirst == pStop)
	{
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "������ ����\n";
		cout << "----------------------------------------------------------------------------------------\n";
	}
	else
	{
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "C�����:\n";
		int pos1 = pos;
		if (pFirst != pLast)
		{
			Reset();
			cout << pFirst->val;
			GoNext();
			while (!IsEnd())
			{
				cout << " --> " << pCurr->val;
				GoNext();
			}
			SetPos(pos1);
			
		}
		else
		{
			cout << pFirst->val;
		}

		cout << "\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "\n";
		if (pCurr != nullptr)
		{
			cout << "������� �������: " << pCurr->val << " ��� �������: " << pos << "\n";
		}
		if (pLast != nullptr)
		{
			cout << "��������� �������: " << pLast->val << "\n";
		}
		if (pFirst != nullptr)
		{
			cout << "������ �������: " << pFirst->val << "\n";
		}
		if (pPr != nullptr)
		{
			cout << "���������� �������: " << pPr->val << "\n";
		}
		if (pHead != nullptr)
		{
			cout << "�������� ����� ��������� �� ��������� ������� �� ���������: " << pHead->pNext->val<<endl;
			if (pLast->pNext == pHead)
				cout << "������� �� ���������: " << pLast->val << " ��������� �� �������� �����" << endl;
		}

		cout << "����� ������:" << len << "\n";
		cout << "----------------------------------------------------------------------------------------\n";
		cout << "\n\n";
	}
}


