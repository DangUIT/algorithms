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
int numberNode(LIST L)
{
    int k = 0;
    for (node *p = L.head; p != NULL; p = p->next)
    {
        k++;
    }
    return k;
}
void add_after_middle(LIST &L, int k)
{
    if (L.head != NULL)
    {
        node *p = L.head;
        int x = numberNode(L);
        int vitri = x / 2;
        node *q = createNode(k);
        if (x % 2 == 0)
        {
            for (int i = 1; i < vitri; i++)
            {
                p = p->next;
            }
            node *r = p->next;
            p->next = q;
            q->next = r;
        }
        else
        {
            for (int i = 1; i < vitri + 1; i++)
            {
                p = p->next;
            }
            node *r = p->next;
            p->next = q;
            q->next = r;
        }
    }
}
void PrintList(LIST L)
{
    if (L.head == NULL)
        cout << "Empty List";
    else
    {
        while (L.head != NULL)
        {
            cout << L.head->data << " ";
            L.head = L.head->next;
        }
    }
}
int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_middle(L, Y);

    PrintList(L);

    return 0;
}
