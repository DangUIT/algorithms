/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE
{
	int info;
	NODE *pNext;
};
// Cấu trúc của một DSLK
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};

//###INSERT CODE HERE -
void CreateEmptyList(LIST &L)
{
	L.pHead = L.pTail = NULL;
}
NODE *createNODE(int x)
{
	NODE *p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void addTail(LIST &L, NODE *p)
{
	if (L.pHead == NULL)
		L.pHead = L.pTail = p;
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void CreateList(LIST &L)
{
	int x;
	do
	{
		cin >> x;
		if (x != -1)
			addTail(L, createNODE(x));
	} while (x != -1);
}
void hoanvi(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void ZigZagList(LIST &L)
{
	NODE *p = L.pHead;
	bool flag = true;
	{
		if (p != NULL)
			while (p->pNext != NULL)
			{
				if (flag)
				{
					if (p->info > p->pNext->info)
						hoanvi(p->info, p->pNext->info);
				}
				else
				{
					if (p->info < p->pNext->info)
						hoanvi(p->info, p->pNext->info);
				}
				p = p->pNext;
				flag = !flag;
			}
	}
}
void PrintList(LIST &L)
{
	NODE *p = L.pHead;
	if (p == NULL)
		cout << "Empty List.";
	else
	{
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main()
{
	LIST L;

	CreateEmptyList(L);
	CreateList(L);

	ZigZagList(L);

	PrintList(L);

	return 0;
}
