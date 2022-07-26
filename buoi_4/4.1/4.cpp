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
	int x, n;
	cin >> n; // Số lượng phần tử của danh sách
	while (n-- > 0)
	{
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}

//###INSERT CODE HERE -
void addHead(LIST &L, NODE *p)
{
	if (L.pHead == NULL)
		L.pHead = L.pTail = p;
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}

NODE *separateHead(LIST &L)
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
void partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2)
{
	if (L.pHead == NULL)
		exit;
	NODE *p;
	pivot = separateHead(L);
	while (L.pHead != NULL)
	{
		p = separateHead(L);
		if (p->info <= pivot->info)
			AddTail(L1, p);
		else
			AddTail(L2, p);
	}
}
void Join(LIST &L, LIST &L1, NODE *pivot, LIST &L2)
{
	NODE *p;
	while (L1.pHead != NULL)
	{
		p = separateHead(L1);
		AddTail(L, p);
	}
	AddTail(L, pivot);
	while (L2.pHead != NULL)
	{
		p = separateHead(L2);
		AddTail(L, p);
	}
}
void quicksort_ascending(LIST &L)
{
	LIST L1, L2, A;
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateEmptyList(A);
	NODE *pivot;
	partition(L, L1, pivot, L2);
	if (L1.pHead != L1.pTail)
		quicksort_ascending(L1);
	if (L2.pHead != L2.pTail)
		quicksort_ascending(L2);
	Join(L, L1, pivot, L2);
}

//
int length(NODE *p)
{
	int i = 0;
	while (p)
	{
		i++;
		p = p->pNext;
	}
	return i;
}

void PrintList(NODE *p)
{
	if (p == NULL)
		cout << "Empty List.";
	else
	{
		// cout << boolalpha << is_ascending(p) << endl;
		cout << length(p) << endl;
		while (p)
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
	quicksort_ascending(L);
	PrintList(L.pHead);

	return 0;
}
