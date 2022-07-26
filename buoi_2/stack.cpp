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
struct stack
{
    node *Head;
};
void createStack(stack &s)
{
    s.Head = NULL;
}
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
bool isEmpty(stack &s)
{
    if (s.Head == NULL)
        return true;
    return false;
}
// addHead
void push(stack &s, int x)
{
    node *p = createNode(x);
    p->data = x;
    if (s.Head == NULL)
        s.Head = p;
    else
    {
        p->next = s.Head;
        s.Head = p;
    }
}
// delete Head
void pop(stack &s)
{
    node *p;
    if (s.Head == NULL)
        exit(1);
    else
    {
        p = s.Head;
        s.Head = s.Head->next;
        delete p;
    }
}
int top(stack &s)
{
    return s.Head->data;
}
void Testing_Push_Pop_Top_Stack(stack &s)
{
    createStack(s);
    int a;
    cin >> a;
    cout << "output: ";
    do
    {
        if (a != -1)
        {
            if (a)
            {
                push(s, a);
            }
            else if (a == 0 && !isEmpty(s))
            {
                cout << top(s) << " ";
                pop(s);
            }
            cin >> a;
        }
    } while (a != -1);
    if (!isEmpty(s))
        cout << "\ntop: " << top(s);
    else
        cout << "\ntop: ";
}
int main()
{
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
