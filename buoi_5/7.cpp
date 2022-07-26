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

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x;           // gán trường dữ liệu của node = x
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

bool IsFullBinaryTree(TREE Root)
{

    //###INSERT CODE HERE -
    if (Root == NULL)
        return true;
    if (Root->pLeft == NULL && Root->pRight == NULL)
        return true;
    if (Root->pLeft != NULL && Root->pRight != NULL)
        return (IsFullBinaryTree(Root->pLeft) && IsFullBinaryTree(Root->pRight));
    return false;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << boolalpha << IsFullBinaryTree(T);
    return 0;
}
