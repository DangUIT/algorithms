#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct list
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
void createEmptyList(list &l)
{
    l.head = NULL;
    l.tail = NULL;
}
void addHead(list &l, node *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}
void addTail(list &l, node *p)
{
    if (l.head == NULL)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void createList(list &l)
{
}
void printList(list l)
{
    node *p = l.head;
    if (p == NULL)
        cout << "Empty list";
    else
    {
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
}
void addNodeAfter(list &l, node *q)
{
    int x;
    cout << "Nhap gia tri node: ";
    cin >> x;
    node *p = createNode(x);
    if (l.head->next == NULL && l.head->data == p->data)
    {
        addTail(l, q);
    }
    else
    {
        for (node *k = l.head; k != NULL; k = k->next)
        {
            if (k->data == p->data)
            {
                node *h = createNode(q->data);
                node *m = k->next;
                h->next = m;
                k->next = h;
            }
        }
    }
}
void addNodeBefore(list &l, node *q)
{
    int x;
    cout << "Nhap node: ";
    cin >> x;
    node *p = createNode(x);
    if (l.head->data == p->data && l.head->next == NULL)
    {
        addHead(l, q);
    }
    else
    {
        node *g = new node;
        for (node *k = l.head; k != NULL; k = k->next)
        {
            if (k->data == p->data)
            {
                if (l.head->data == p->data)
                    addHead(l, q);
                node *h = createNode(q->data);
                h->next = k;
                g->next = h;
            }
            g = k;
        }
    }
}
int main()
{
    list l;
    createEmptyList(l);
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        node *p = createNode(x);
        addHead(l, p);
    }
    printList(l);
    cout << endl;
    int x;
    cout << "Nhap gia tri node can them: ";
    cin >> x;
    node *p = createNode(x);
    addNodeBefore(l, p);
    printList(l);
    return 0;
}