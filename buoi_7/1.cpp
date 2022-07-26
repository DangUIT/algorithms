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
TNODE *CreateTnode(int data)
{
    TNODE *p = new TNODE;
    if (p == NULL)
        exit;
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int AddTnode(TREE &T, int x)
{
    if (T == NULL)
        T = CreateTnode(x);
    else
    {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return AddTnode(T->pRight, x);
        else
            return AddTnode(T->pLeft, x);
    }
    return 1;
}
void CreateTree(TREE &T)
{
    int x;
    do
    {
        cin >> x;
        if (x != -1)
        {
            AddTnode(T, x);
        }
    } while (x != -1);
}
TNODE *FindMax(TREE T)
{
    if (T == NULL)
        return NULL;
    if (T->pLeft == NULL)
        return T;
    return FindMax(T->pLeft);
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMax(T)->key;
    return 0;
}
