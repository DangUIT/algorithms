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
NODE *createNode(int x)
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
	int val;
	do
	{
		cin >> val;
		if (val != -1)
			addTail(L, createNode(val));
	} while (val != -1);
}
NODE *seperateHead(LIST &L)
{
	NODE *p;
	if (L.pHead == NULL)
		return NULL;
	p = L.pHead;
	L.pHead = L.pHead->pNext;
	if (L.pHead == NULL)
		L.pTail = NULL;
	p->pNext = NULL;
	return p;
}
void Merge_Partition(LIST &L, LIST &L1, LIST &L2)
{
	NODE *p;
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	while (L.pHead)
	{
		p = seperateHead(L);
		addTail(L1, p);
		if (L.pHead)
		{
			p = seperateHead(L);
			addTail(L2, p);
		}
	}
}

//
void PrintList(LIST L)
{
	NODE *p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else
	{
		p = L.pHead;
		while (p)
		{
			cout << p->info << " ";
			p = p->pNext;
		}
	}
	cout << endl;
}

int main()
{
	LIST L, L1, L2;

	CreateEmptyList(L);
	CreateList(L);

	Merge_Partition(L, L1, L2);

	PrintList(L1);
	PrintList(L2);
	PrintList(L);

	return 0;
}
