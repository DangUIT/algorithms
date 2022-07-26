/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
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
int binary_search_last_occurrence(int a[], int n, int x)
{
    int first, last;
    first = 0;
    last = n - 1;
    int res = -1;
    int middle;
    while (first <= last)
    {
        middle = (last + first) / 2;
        if (a[middle] > x)
            last = middle - 1;
        else if (a[middle] < x)
            first = middle + 1;
        else
        {
            res = middle;
            first = middle + 1;
        }
    }
    return res;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}
