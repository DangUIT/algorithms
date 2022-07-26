#include <iostream>
using namespace std;
#define TableSize 10000
struct NODE_PASS
{
	string info;
	NODE_PASS *pNext;
};
struct USER
{
	string username;
	NODE_PASS *password;
};
struct NODE
{
	USER key;
};
typedef NODE *HASHTABLE[TableSize];
NODE_PASS *creatNodePass(string x)
{
	NODE_PASS *p = new NODE_PASS;
	if (p == nullptr)
		exit(1);
	p->pNext = NULL;
	p->info = x;
	return p;
}
void addTail(NODE_PASS *p, string x)
{
	if (p == NULL)
		p->pNext = creatNodePass(x);
	else
	{
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = creatNodePass(x);
	}
}
int HF(const string &key)
{
	int s = 0;
	for (int i = 0; i < key.length(); i++)
		s = 37 * s + key[i];
	return s % TableSize;
}
int HF_LinearProbing(int hf, int i)
{
	return (hf + i) % TableSize;
}
bool isFull(HASHTABLE H, int CurrentSize)
{
	if (CurrentSize == TableSize)
		return true;
	return false;
}
void InitHashTable(HASHTABLE &H, int &CurrentSize)
{
	CurrentSize = 0;
	for (int i = 0; i < TableSize; i++)
		H[i] = NULL;
}
void CreateHashTable(HASHTABLE &H, int &CurrentSize, int &M)
{
	int N;
	InitHashTable(H, CurrentSize);
	cin >> N >> M;
	int info;
	int dem = 0;
	do
	{
		if (isFull(H, CurrentSize))
			exit;
		if (dem++ == N)
			exit;
		string user, pass;
		cin >> user >> pass;
		int k = HF(user);
		int h = k;
		int i = 0;
		while (H[k] != NULL && user != H[k]->key.username)
			k = HF_LinearProbing(h, ++i);
		// Đưa info vào H tại vị trí
		H[k] = new NODE;
		H[k]->key.username = user;
		// addTail(H[k]->key.password, pass);
		CurrentSize++;
	} while (true);
}
void print(NODE_PASS *p)
{
	if (p == NULL)
		cout << "Unregistered User.";
	else
	{
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}
void Traverse(HASHTABLE H, int CurrentSize, int M)
{
	string user;
	for (int i = 0; i < M; i++)
	{
		cin >> user;
		int k = HF(user);
		int h = k;
		int j = 0;
		while (H[k] != NULL && user != H[k]->key.username)
			k = HF_LinearProbing(h, ++j);
		if (H[k]->key.username == user)
			print(H[k]->key.password);
	}
}
int main()
{
	HASHTABLE H;
	int CurrentSize;
	int M;
	CreateHashTable(H, CurrentSize, M);
	Traverse(H, CurrentSize, M);
	return 0;
}
