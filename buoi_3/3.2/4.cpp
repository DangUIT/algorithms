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
	int n;
	cin >> n;
	int x;
	while (n)
	{
		cin >> x;
		addTail(L, createNODE(x));
		n--;
	}
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
	if (p != NULL)
	{
		while (p)
		{
			NODE *min = p;
			NODE *r = p->pNext;
			while (r)
			{
				if (r->info < min->info)
					min = r;
				r = r->pNext;
			}
			hoanvi(p->info, min->info);
			p = p->pNext;
		}
		NODE *x = L.pHead->pNext;
		while (x)
		{
			NODE *y = x->pNext;
			if (y == NULL)
				break;
			hoanvi(x->info, y->info);
			x = y->pNext;
		}
	}
}
void PrintList(NODE *p)
{
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

	PrintList(L.pHead);

	return 0;
}
