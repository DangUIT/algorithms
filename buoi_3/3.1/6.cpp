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
// ds có 1 phần tử, ds bằng nhau, ds KO có cặp phần tử giảm dần => trả về true
// ds null, ds có 1 cặp phần tử ko tăng => trả về false
bool is_ascending(NODE *head)
{
    if (head == NULL)
        return 0;
    while (head->pNext != NULL)
    {
        if (head->info > head->pNext->info)
            return 0;
        head = head->pNext;
    }
    return 1;
}
void PrintList(NODE *p)
{
    if (p == NULL)
        cout << "0";
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
void hoanvi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort_decending(LIST &L)
{
    //###INSERT CODE HERE -
    NODE *p = L.pHead;
    while (p)
    {
        NODE *min = p;
        NODE *r = p->pNext;
        while (r)
        {
            if (min->info < r->info)
            {
                min = r;
            }
            r = r->pNext;
        }
        hoanvi(p->info, min->info);
        p = p->pNext;
    }
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    selectionSort_decending(L);
    PrintList(L.pHead);

    return 0;
}
