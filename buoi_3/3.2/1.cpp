/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <iomanip>
using namespace std;
#define MAXN 100
struct SinhVien
{
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
void Input(SinhVien &a)
{
    cin.getline(a.MASV, 10);
    cin.getline(a.HoTen, 100);
    cin.getline(a.NgaySinh, 12);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}

//###INSERT CODE HERE -
struct node
{
    SinhVien data;
    node *next;
};
struct LIST
{
    node *pHead;
    node *pTail;
};
node *createNode(SinhVien &x)
{
    node *p = new node;
    if (p == NULL)
        exit(1);
    else
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}
void addTail(LIST &L, node *p)
{
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}
void Input(LIST &L)
{
    int n;
    cin >> n;
    do
    {
        if (n > 0)
        {
            SinhVien p;
            cin.ignore();
            Input(p);
            addTail(L, createNode(p));
            n--;
        }
    } while (n > 0);
}
void Output(LIST &L)
{
    node *p = L.pHead;
    if (L.pHead == NULL)
        return;
    else
    {
        while (p)
        {
            cout << p->data.MASV << "\t";
            cout << p->data.HoTen << "\t";
            cout << p->data.NgaySinh << "\t";
            cout << p->data.GioiTinh << "\t";
            cout << p->data.DiemToan << "\t";
            cout << p->data.DiemLy << "\t";
            cout << p->data.DiemHoa << "\t";
            cout << setprecision(3);
            cout << p->data.DTB << "\t";
            p = p->next;
            cout << endl;
        }
    }
}
int main()
{
    LIST L;
    L.pHead = L.pTail = NULL;
    Input(L);
    Output(L);
    return 0;
}
