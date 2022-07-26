/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define M 100

struct NODE
{
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE *&head, int x)
{
    NODE *p = CreateNode(x);
    if (head == NULL)
        head = p;
    else
    {
        NODE *i = head;
        while (i->pNext != NULL)
        {
            i = i->pNext;
        }
        i->pNext = p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

void InitHashTable(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i)
{
    NODEPTR p = H[i];
    while (p != NULL)
    {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        TraverseBucket(H, i);
        cout << endl;
    }
}
//###INSERT CODE HERE -
void CreateHashTable(HASHTABLE &H, int &numbecket)
{
    cin >> numbecket;
    int x;
    InitHashTable(H, numbecket);
    do
    {
        cin >> x;
        if (x != -1)
        {
            int i = HF(numbecket, x);
            AddTail(H[i], x);
        }
    } while (x != -1);
}
void DeleteHead(NODEPTR &p)
{
    if (p != NULL)
    {
        NODEPTR x=p;
        p = p->pNext;
        delete x;
    }
}
void DeleteAfter(NODEPTR &q)
{
    NODEPTR p = q->pNext;
    if (p != NULL)
    {
        q->pNext = p->pNext;
        delete p;
    }
}
bool Remove(HASHTABLE &H, int numbecket, int x)
{
    int i = HF(numbecket, x);
    NODE *p = H[i];
    NODE *q = NULL;
    while (p != NULL && p->key != x)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    else if (p == H[i])
        DeleteHead(H[i]);
    else
        DeleteAfter(q);
    return true;
}
//---------------------------
int main()
{
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x))
    {
        cout << endl
             << x << ": Delete Successful." << endl
             << endl;
        Traverse(H, numbucket);
    }
    else
        cout << endl
             << x << ": Delete Failed." << endl
             << endl;

    return 0;
}
