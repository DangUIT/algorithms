/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;
//###INSERT CODE HERE -
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
node *createNode(int x)
{
    node *p = new node;
    if (p == NULL)
        exit(1);
    else
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}
void CreateEmptyList(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}
void addTail(LIST &L, node *p)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
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
            addTail(L, createNode(n));
        }
    } while (n != -1);
}
void RemoveHead(LIST &L)
{
    node *p;
    if (L.head != NULL)
    {
        p = L.head;
        L.head = L.head->next;
        delete p;
    }
}
void RemoveTail(LIST &L)
{
    node *k = L.head;
    if (L.head != NULL)
    {
        if (k->next == NULL)
        {
            L.tail = L.head = NULL;
        }
        for (k; k != NULL; k = k->next)
        {
            if (k->next == L.tail)
            {
                delete L.tail;
                k->next = NULL;
                L.tail = k;
            }
        }
    }
}
void PrintList(LIST &L)
{
    node *p = L.head;
    if (p == NULL)
        cout << "Empty List";
    else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    // RemoveHead(L);
    RemoveTail(L);
    PrintList(L);

    return 0;
}
