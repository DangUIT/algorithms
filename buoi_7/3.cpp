/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct TNODE
{
    int data;
    TNODE *pLeft;
    TNODE *pRight;
    int appear;
};
typedef TNODE *TREE;
TNODE *CreateTNODE(int key)
{
    TNODE *p = new TNODE;
    if (p == NULL)
        exit;
    p->data = key;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->appear = 1;
    return p;
}
void AddTNODE(TREE &T, int x)
{
    int number;
    if (T == NULL)
        T = CreateTNODE(x);
    else
    {
        if (T->data == x)
        {
            T->appear++;
            return;
        }
        if (T->data > x)
            return AddTNODE(T->pLeft, x);
        else
            return AddTNODE(T->pRight, x);
    }
}
void CreateTree(TREE &T)
{
    int n;
    cin >> n;
    int x;
    while (n)
    {
        cin >> x;
        AddTNODE(T, x);
        n--;
    }
}
void PrintTree(TREE T)
{
    if (T != NULL)
    {
        PrintTree(T->pLeft);
        cout << T->data << " xuat hien " << T->appear << " lan" << endl;
        PrintTree(T->pRight);
    }
}
int main()
{
    TNODE *T;
    T = NULL;
    CreateTree(T);
    PrintTree(T);
    return 0;
}
