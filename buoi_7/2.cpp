/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;
typedef string VERTEX;
struct NODE
{
    int info;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
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
void AddHead(LIST &L, NODE *p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

// Q khác NULL
void add_Y_afterQ(LIST &L, int Y, NODE *Q)
{
    NODE *p = CreateNode(Y);
    p->pNext = Q->pNext;
    Q->pNext = p;
    if (L.pTail == Q)
        L.pTail = p;
}

// tìm đỉnh s tương ứng với index from 1 to n đỉnh
int search_index(VERTEX *V, int n, string s)
{
    for (int i = 0; i < n; i++)
        if (V[i] == s)
            return i + 1;
    return -1;
}

//###INSERT CODE HERE -
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
void quicksort_ascending(LIST &L)
{
    LIST L1, L2, A;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    CreateEmptyList(A);
    if (L.pHead == L.pTail)
        return;
    NODE *pivot;
    partition(L, L1, pivot, L2);
    if (L1.pHead != L1.pTail)
        quicksort_ascending(L1);
    if (L2.pHead != L2.pTail)
        quicksort_ascending(L2);
    Join(L, L1, pivot, L2);
}

void CreateGraph_AdjacencyList(LIST *&L, VERTEX *&V, int &n)
{
    cin >> n;
    L = new LIST[n + 1];
    for (int i = 0; i < n; i++)
        CreateEmptyList(L[i]);
    V = new VERTEX[n + 1];
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        VERTEX a, b;
        cin >> a >> b;
        int u = search_index(V, n, a);
        int v = search_index(V, n, b);
        AddTail(L[u - 1], CreateNode(v));
        AddTail(L[v - 1], CreateNode(u));
    }
    for (int i = 0; i < n; i++)
    {
        quicksort_ascending(L[i]);
    }
}

//-------------------------
void PrintList(LIST L, VERTEX *V)
{
    NODE *p;
    if (L.pHead == NULL)
        cout << "EMPTY";
    else
    {
        p = L.pHead;
        while (p)
        {
            cout << V[p->info - 1] << " ";
            p = p->pNext;
        }
    }
}
void PrintGraph_AdjacencyList(LIST *L, VERTEX *V, const int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << V[i] << " ==> ";
        PrintList(L[i], V);
        cout << endl;
    }
}
int main()
{
    LIST *L;   // DANH SÁCH KỀ LƯU ĐỒ THỊ
    int n;     // SỐ LƯỢNG ĐỈNH CỦA ĐỒ THỊ
    VERTEX *V; // TẬP TÊN ĐỈNH CỦA ĐỒ THỊ KIỂU STRING

    CreateGraph_AdjacencyList(L, V, n);

    PrintGraph_AdjacencyList(L, V, n);

    return 0;
}
