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
NODE *createNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
		exit(1);
	else
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}
void CreateList(LIST &L)
{
	int n;
	do
	{
		cin >> n;
		if (n != -1)
			addTail(L, createNode(n));
	} while (n != -1);
}
NODE *separateHead(LIST &L)
{
	if (L.pHead == NULL)
		return NULL;
	NODE *p = L.pHead;
	L.pHead = L.pHead->pNext;
	if (L.pHead == NULL)
		L.pTail = NULL;
	p->pNext = NULL;
	return p;
}
void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
	pivot = separateHead(L);
	NODE *p;
	while (L.pHead != NULL)
	{
		p = separateHead(L);
		if (p->info <= pivot->info)
		{
			addTail(L1, p);
		}
		else
		{
			addTail(L2, p);
		}
	}
}
void PrintList(LIST &L)
{
	if (L.pHead == NULL)
		cout << "Empty List.";
	NODE *p = L.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}
int main()
{
	LIST L, L1, L2;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if (L.pHead == NULL)
	{
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);
	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);
	return 0;
}
