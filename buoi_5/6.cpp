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
TNODE *createTnode(int x)
{
	TNODE *p=new TNODE;
	if (p == NULL)
		exit(1);
	else
	{
		p->key = x;
		p->pLeft = nullptr;
		p->pRight = nullptr;
	}
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
		Insert(T, createTnode(x));
	} while (true);
}
int CountLeaf(TREE &T)
{   
	if (T == NULL)
		return 0;
	if (T->pLeft == NULL && T->pRight == NULL)
		return 1;
	else
		return CountLeaf(T->pLeft) + CountLeaf(T->pRight);
}
int main()
{
	TREE T;	  // hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << CountLeaf(T);
	return 0;
}
