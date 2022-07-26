#include<iostream>
#include <string>
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
void CreateEmptyList(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}
node *CreateNode(int x)
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
void addHead(LIST &L, node *p)
{
    if (L.head == NULL)
        L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
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
            addHead(L, CreateNode(n));
        }
    } while (n != -1);
}
int Armstrong(int x)
{
    int s = 0;
    int m = x;
    int n = to_string(x).length();
    while (m)
    {
        int y = m % 10;
        m /= 10;
        s += pow(y, n);
    }
    if (x == s && x != 0)
        return 1;
    return 0;
}
int findArmstrong(LIST &L)
{
    for (node *p = L.head; p != NULL; p = p->next)
    {
        if (Armstrong(p->data) == 1)
            break;
        return 1;
    }
    return 0;
}
void PrintList_Armstrong(LIST &L)
{
    node *p = L.head;
    if (p == NULL)
        cout << "Empty List";
    else
    {
        while (p != NULL)
        {
            if (Armstrong(p->data) == 1)
                cout << p->data << " ";
            p = p->next;
        }
    }
    if (findArmstrong(L) == 1)
        cout << "Khong co so armstrong nao trong mang";
}
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Armstrong(L);
    return 0;
}
