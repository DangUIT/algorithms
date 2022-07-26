/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 100

struct NODE
{
    char info;
    NODE *pNext;
};
struct stack
{
    NODE *head;
};
void createEmptyStack(stack &s)
{
    s.head = NULL;
}
NODE *createNode(char x)
{
    NODE *p = new NODE;
    if (p == NULL)
        exit(1);
    else
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}
bool empty(stack &s)
{
    return s.head == NULL;
}
void push(stack &s, char x)
{
    NODE *p = createNode(x);
    if (s.head == NULL)
        s.head = p;
    else
    {
        p->pNext = s.head;
        s.head = p;
    }
}
void pop(stack &s)
{
    NODE *p = new NODE;
    if (s.head == NULL)
        exit(1);
    else
    {
        p = s.head;
        s.head = s.head->pNext;
        delete p;
    }
}
char top(stack &s)
{
    return s.head->info;
}
void Input_infix(char a[], int &n)
{
    n = 0;
    while (true)
    {
        char i;
        cin >> i;
        if (i != '#')
            a[n++] = i;
        else
            break;
    }
}
int pre(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
bool toantu(char c)
{
    if (c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-')
        return true;
}
void infix_to_postfix(char a[], int &n, char b[], int &m)
{
    stack s;
    createEmptyStack(s);
    m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            b[m++] = a[i];
        }
        else if (a[i] == '(')
        {
            push(s, a[i]);
        }
        else if (a[i] == ')')
        {
            while (top(s) != '(')
            {
                b[m++] = top(s);
                pop(s);
            }
            pop(s);
        }
        else
        {
            while (!empty(s) && toantu(a[i]) && pre(a[i]) <= pre(top(s)))
            {
                b[m++] = top(s);
                pop(s);
            }
            push(s, a[i]);
        }
    }
    while (!empty(s))
    {
        b[m++] = top(s);
        pop(s);
    }
}
void Output(char b[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
}
int main()
{
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
