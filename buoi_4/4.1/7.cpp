/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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
        AddTail(L1, p);
        if (L.pHead)
        {
            p = seperateHead(L);
            AddTail(L2, p);
        }
    }
}
void Merge(LIST &L, LIST &L1, LIST &L2)
{
    NODE *p;
    CreateEmptyList(L);
    while (L1.pHead && L2.pHead)
    {
        if (L1.pHead->info < L2.pHead->info)
        {
            p = seperateHead(L1);
            AddTail(L, p);
        }
        else
        {
            p = seperateHead(L2);
            AddTail(L, p);
        }
    }
    while (L1.pHead)
    {
        p = seperateHead(L1);
        AddTail(L, p);
    }
    while (L2.pHead)
    {
        p = seperateHead(L2);
        AddTail(L, p);
    }
}
void mergesort_ascending(LIST &L)
{
    if (L.pHead == L.pTail)
        return;
    LIST L1, L2;
    Merge_Partition(L, L1, L2);
    mergesort_ascending(L1);
    mergesort_ascending(L2);
    Merge(L, L1, L2);
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
    mergesort_ascending(L);
    PrintList(L.pHead);

    return 0;
}
