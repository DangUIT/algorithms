/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct LIST
{
    node *head;
    node *tail;
};
node *createNote(int x)
{
    node *p = new node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}
void CreateEmptyList(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}
void addHead(LIST &L, node *p)
{
    if (L.head == NULL)
    {
        L.tail = L.head=p;
    }
    else
    {
        p->next = L.head;
        L.head = p;
    }
}
void addTail(LIST &L, node *p)
{
    if (L.head == NULL)
    {
        L.head = p;
        L.tail = L.head;
    }
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}
void CreateList(LIST &L)
{
    int n, m;
    do
    {
        cin >> n;
        if (n != -1)
        {
            cin >> m;
            if (n == 0)
                addHead(L, createNote(m));
            else if (n == 1)
                addTail(L, createNote(m));
        }
    } while (n != -1);
}
void PrintList(LIST L)
{
    node *p = L.head;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    else
        cout << "Empty List.";
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L);

    return 0;
}
