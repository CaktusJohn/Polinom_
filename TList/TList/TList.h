#pragma once
#include <iostream>
using namespace std;
template <class T>
struct TNode
{
	T val;
	TNode* pNext;
	
	
};


template <class T>
class TList
{
protected:
	TNode<T>* pStop;
	TNode<T>* pFirst, * pLast, * pCurr, * pPr;
	int pos, len;
public:
	TList();//
	~TList()//
	{
		DelList();
	}
	TList(const TList& _list);//
	virtual void InsFirst(T _val);//
	virtual void InsLast(T _val);//
	virtual void InsCurr(T _val);//
	virtual void DelFirst();//
	virtual void DelLast();//
	virtual void DelCurr();//

	T GetCurr()//
	{
		return (pCurr->val);
	}
	void SetPos(int _pos)//
	{
		if (_pos > len || _pos<0)
		{
			throw ("wrong pos");
		}
			Reset();
			while (pos != _pos)
			{
				GoNext();
			}
	}
	void Reset();//
	void GoNext();//
	bool IsEnd();//
	void DelList();//
	virtual void PrintList();
};
	template <class T>
	void TList<T>::PrintList()
	{
		if (pFirst == pStop)
		{
			cout << "----------------------------------------------------------------------------------------\n";
			cout << "Список пуст\n";
			cout << "----------------------------------------------------------------------------------------\n";
		}
		else
		{
			cout << "----------------------------------------------------------------------------------------\n";
			cout << "Cписок:\n";
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
				cout << "Текущий элемент: " << pCurr->val << " Его позиция: " << pos << "\n";
			}
			if (pLast != nullptr)
			{
				cout << "Последний элемент: " << pLast->val << "\n";
			}
			if (pFirst != nullptr)
			{
				cout << "Первый элемент: " << pFirst->val << "\n";
			}
			if (pPr != nullptr)
			{
				cout << "Предыдущий элемент: " << pPr->val << "\n";
			}

			cout << "Длина списка:" << len << "\n";
			cout << "----------------------------------------------------------------------------------------\n";
			cout << "\n\n";
		}
	}
	template <class T>
	TList<T>::TList()
	{
		pFirst = nullptr;
		pLast = nullptr;
		pStop = nullptr;
		pCurr = nullptr;
		pPr = nullptr;
		pos = 0;
		len = 0;
	}
	template <class T>
	TList<T>::TList(const TList& _list)
	{
		pFirst = _list.pFirst;
		pLast = _list.pLast;
		pStop = _list.pStop;
		pCurr = nullptr;
		pPr = nullptr;
		pos = _list.pos;
		len = _list.len;

	}
	template <class T>
	void TList<T>::Reset()
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 1;
	}
	template <class T>
	void TList<T>::GoNext()
	{
		if (pCurr != pStop)
		{
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		}
	}
	template <class T>
	bool TList<T>::IsEnd()
	{
		return (pStop == pCurr);
	}
	template <class T>
	void TList<T>::InsCurr(T _val)
	{
		if (len == 0) throw ("list is empty");
		if (pCurr == pFirst)
		{
			InsFirst(_val);

		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->val = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++; pos++;
		}
	}
	template <class T>
	void TList<T>::InsFirst(T _val)
	{
		
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;

		
		if (pFirst == nullptr)

			{
				pFirst = tmp;
				pFirst->pNext = pStop;
				pLast = pFirst;
				pCurr = pFirst;
				len++; pos++;
			}
		
		else
		{
			if (pFirst == pLast)
			{
			tmp->pNext = pFirst;
			pCurr = pFirst;
			pLast = pCurr;
			pFirst = tmp;
			pPr = pFirst;
			len++; pos++;
			}
			else
			{
				tmp->pNext = pFirst;
				pFirst = tmp;
				len++; pos++;
			}
		}
	}
	template <class T>
	void TList<T>::InsLast(T _val)
	{
		if (len == 0) InsFirst(_val);
		else
		{
			TNode<T> *tmp = new TNode<T>;
			tmp->val = _val;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			
			
				pLast = tmp;
				len++;
			
		}
	}


	template <class T>
	void TList<T>::DelCurr()
	{
		if (len == 0) throw ("list is empty");
		else
		{
			if (pCurr == pFirst)
			{
				DelFirst();
			}
			else
			{
				if (pCurr == pLast)
				{
					DelLast();
				}
				else
				{
					if (pCurr != pStop)
					{

						TNode<T>* tmp = pCurr;
						pCurr = pCurr->pNext;
						pPr->pNext = pCurr;
						delete tmp;
						len--;
					}
				}
			}
		}
	}
	template <class T>
	void TList<T>::DelFirst()

	{
		if (len == 0) throw ("list is empty");
		else
		{	
			TNode<T>* tmp = pFirst;
			if (pCurr == pFirst)
			{
				pCurr = pCurr->pNext;
				pFirst = pFirst->pNext;
				delete tmp;
				len--; 
			}
			else
			{
				if (pFirst == pPr)
				{
					pFirst = pFirst->pNext;
					delete tmp;
					pPr = nullptr;
					len--; pos--;
					
				}
				else {
					pFirst = pFirst->pNext;
					delete tmp;
					len--; pos--;
				}
			}
			
		}
	}
	template <class T>
	void TList<T>::DelLast() 
	{
		if (len == 0) throw ("list is empty");
		else
		{
			if (pLast == pFirst)
			{
				DelFirst();
			}
			{
				if (pCurr == pLast)
				{
					TNode<T>* tmp = pCurr;
					SetPos(pos - 1);
					delete tmp;
					pCurr->pNext = pStop;
					pLast = pCurr;
					len--;
				}
				else
				{
					int posPcur = pos;
					Reset();
					while (pos != len - 1)
					{
						GoNext();
					}
					pCurr->pNext = pStop;
					delete pLast;
					pLast = pCurr;
					SetPos(posPcur);
					len--;

				}
			}
		}
	}
	template <class T>
	void TList<T>::DelList()
	{
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}

