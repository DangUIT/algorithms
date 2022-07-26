/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <math.h>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int &N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int interpolation_search(int *a, int n, int x)
{
    //###INSERT CODE HERE -
    int l = 0, r = n - 1;
    while (l <= r && a[l] <= x && x <= a[r])
    {
        int rangeDelta = a[r] - a[l];
        int indexDelta = r - l;
        int valueDelta = x - a[l];

        if (valueDelta < 0)
            return -1;
        if (rangeDelta <= 0)
            return a[l] == x ? l : -1;
        float frac = float(indexDelta) / rangeDelta;
        int m = l + floor(valueDelta * frac);

        if (a[m] < x)
            l = m + 1;
        else if (a[m] > x)
            r = m - 1;
        else
            return m;
    }
    return -1;
}

int main()
{
    int x;
    cin >> x;
    int n;
    cin >> n;

    int a[MAXN];
    NhapMang(a, n);

    int i = interpolation_search(a, n, x);

    if (i == -1)
        std::cout << "false";
    else
        std::cout << "true";

    return 0;
}
