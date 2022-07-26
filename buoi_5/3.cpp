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
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE;
    if (p == NULL)
        exit;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void Insert(TREE &T, int x)
{
    if (T == NULL)
        T = CreateTNode(x);
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
            Insert(T, x);
    } while (x != -1);
}
TNODE *FindMin(TREE &T)
{
    if (T == NULL)
        return NULL;
    if (T->pLeft == NULL)
        return T;
    return FindMin(T->pLeft);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMin(T)->key;
    return 0;
}
