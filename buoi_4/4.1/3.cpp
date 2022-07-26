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
NODE *CreateNode(int x)
{
	NODE *p;
	p = new NODE;
	// if (p == NULL)
	//		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST &L, NODE *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void CreateEmptyList(LIST &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST &L)
{
	NODE *p;
	int x;
	while (true)
	{
		cin >> x;
		if (x != -1)
		{
			p = CreateNode(x);
			AddTail(L, p);
		}
		else
			break;
	}
}
void Join(LIST &L, LIST &L1, NODE *pivot, LIST &L2)
{
	if (L1.pHead != NULL)
	{
		L.pHead = L1.pHead;
		L1.pTail->pNext = pivot;
	}
	else
		L.pHead = pivot;
	pivot->pNext = L2.pHead;
	if (L2.pHead != NULL)
		L.pTail = L2.pTail;
	else
		L.pTail = pivot;
}
void PrintList(LIST &L)
{
	NODE *p = L.pHead;
	if (L.pHead == NULL)
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
	LIST L, L1, L2;

	int x;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot = CreateNode(x);
	CreateList(L2);

	Join(L, L1, pivot, L2);
	PrintList(L);

	return 0;
}
