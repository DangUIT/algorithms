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

int HF(int numbucket, int key)
{
    return key % numbucket;
}

//###INSERT CODE HERE -
void InitHashtable(HASHTABLE &H)
{
    for (int i = 0; i < M; i++)
    {
        H[i] = NULL;
    }
}
void CreateHashTable(HASHTABLE &H, int &numbecket)
{
    cin >> numbecket;
    int x;
    InitHashtable(H);
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
void Traverse(NODEPTR p)
{
    while (p != NULL)
    {
        cout << p->key;
        if (p->pNext != NULL)
            cout << " --> ";
        p = p->pNext;
    }
}
void Traverse(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        if (H[i] != NULL)
        {
            cout << " --> ";
            Traverse(H[i]);
        }
        cout << endl;
    }
}
//---------------------------------------------
int main()
{
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}