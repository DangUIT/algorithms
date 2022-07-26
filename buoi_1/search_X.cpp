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
    p->next = NULL;
    p->data = x;
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
    {
        L.head = L.tail = p;
    }
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
bool searchX(node *p, int x)
{
    cout << boolalpha;
    for (node *k = p; k != NULL; k = k->next)
    {
        if (k->data == x)
            return true;
    }
    return false;
}

int main()
{
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> X;
    cout << searchX(L.head, X);

    return 0;
}
