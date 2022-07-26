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
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if (T)
    {
        if (T->key == p->key)
            return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
void CreateTree(TREE &T)
{
    int x;
    do
    {
        cin >> x;
        if (x == -1)
            break;
        Insert(T, CreateTNode(x));
    } while (true);
}
int CountLeaf(TREE &T, int &x)
{
    if (T == NULL)
        return 0;
    if (T->pLeft == NULL && T->pRight == NULL)
        x++;
    else
        return CountLeaf(T->pLeft, x) + CountLeaf(T->pRight, x);
    return x;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int count = 0;
    CountLeaf(T, count);
    cout << count;
    return 0;
}
