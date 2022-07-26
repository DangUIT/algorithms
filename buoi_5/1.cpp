/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

//###INSERT CODE HERE -
TNODE *CreateNode(int x)
{
    TNODE *p = new TNODE;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void Insert(TREE &T, int x)
{
    if (T == NULL)
        T = CreateNode(x);
    else
    {
        if (T->key == x)
            return;
        if (T->key > x)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
}
void CreateTree(TREE &T)
{
    int x;
    do
    {
        cin >> x;
        if (x != -1)
        {
            Insert(T, x);
        }
    } while (x != -1);
}
void Ignore(TREE T)
{
    if (T != NULL)
    {

        Ignore(T->pLeft);
        cout << T->key << " ";
        Ignore(T->pRight);
    }
}
void PrintTree(TREE T)
{
    if (T == NULL)
        cout << "Empty Tree.";
    else
        Ignore(T);
}

//-----------------------------
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
