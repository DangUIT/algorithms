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
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
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
int number(NODE *p)
{
    int k = 0;
    for (p; p != NULL; p = p->pNext)
    {
        k++;
    }
    return k;
}
int searchXget_nth_node_from_tail(NODE *p, int k)
{
    int x;
    int n = number(p);
    if (k > n)
        x = -1;
    else
    {
        int f = n - k + 1;
        while (f)
        {
            x = p->info;
            p = p->pNext;
            f--;
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
    cout << searchXget_nth_node_from_tail(L.pHead, k);

    return 0;
}
