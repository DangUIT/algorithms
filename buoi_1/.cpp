

#include <iostream>
#include <string.h>

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
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE *CreateNode(int x)
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
    do
    {
        cin >> n;
        if (n != -1)
        {
            addTail(L, CreateNode(n));
        }
    } while (n != -1);
}
int countElement(NODE *p)
{
    int x = 0;
    for (p; p != NULL; p = p->pNext)
    {
        x++;
    }
    return x;
}
int get_nth_node_from_head(NODE *p, int k)
{
    int x;
    if (countElement(p) < k || k <= 0)
        x = -1;
    else
    {
        while (k)
        {
            x = p->info;
            p = p->pNext;
            k--;
        }
    }
    return x;
}
int main()
{
    LIST L;
    int k;
    CreateEmptyList(L);
    CreateList(L);

    std::cin >> k;
    cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
