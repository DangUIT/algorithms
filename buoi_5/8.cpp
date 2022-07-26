/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
#include <cmath>
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
bool IsCompleteBST(TREE &T)
{
    if (T == nullptr)
        exit(1);
    queue<TNODE *> q;
    q.push(T);
    bool flag = false;
    while (!q.empty())
    {
        TNODE *temp = q.front();
        q.pop();
        if (temp->pLeft)
        {
            if (flag == true)
                return false;
            q.push(temp->pLeft);
        }
        else
        {
            flag = true;
        }
        if (temp->pRight)
        {
            if (flag == true)
                return false;

            q.push(temp->pRight);
        }
        else
            flag = true;
    }
    return true;
}
int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << boolalpha << IsCompleteBST(T);

    system("pause");
    return 0;
}
