/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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
void AddTnode(TREE &T, int x)
{
    if (T == NULL)
        T = CreateTnode(x);
    else
    {
        if (T->key == x)
            return;
        if (T->key > x)
            return AddTnode(T->pRight, x);
        else
            return AddTnode(T->pLeft, x);
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
            AddTnode(T, x);
        }
    } while (x != -1);
}
bool areIdentical(TREE root1, TREE root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->key == root2->key 
    && areIdentical(root1->pLeft, root2->pLeft) 
    && areIdentical(root1->pRight, root2->pRight));
}
bool isSubtree(TREE S, TREE T)
{
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
    if (areIdentical(S, T))
        return true;
    return isSubtree(S, T->pLeft) || isSubtree(S, T->pRight);
}
int main()
{
    TNODE *S, *T;
    S = NULL;
    T = NULL;

    CreateTree(S);
    CreateTree(T);

    cout << boolalpha << isSubtree(S, T);

    return 0;
}
