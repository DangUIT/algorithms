/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int re_binary_search(int a[], int first, int last, int x)
{
    int mid = (first + last) / 2;
    if (first > last)
        return -1;
    else if (a[mid] == x)
        return mid;
    else if (a[mid] < x)
        return (re_binary_search(a, mid + 1, last, x));
    else
        return (re_binary_search(a, first, mid - 1, x));
}
bool binary_search(int a[], int first, int last, int x)
{
    if (re_binary_search(a, 0, last, x) == -1)
        return false;
    return true;
}
int main()
{
    int x, n, a[MAXN];
    cin >> x;
    cin >> n;
    NhapMang(a, n);
    cout << boolalpha << binary_search(a, 0, n - 1, x);
    return 0;
}
