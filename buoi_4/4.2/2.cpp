/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
// #include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

void NhapMang(int *a, int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int &N)
{
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

//###INSERT CODE HERE -
//-----------------------------------------
void Copy(int b[], int a[], int l, int r)
{
    int nb = r - l + 1;
    for (int i = 0; i < nb; i++)
        b[i] = a[i + l];
}
void TopDownMerge(int *a, int l, int r)
{
    int *b, nb = r - l + 1;
    b = new int[nb];
    Copy(b, a, l, r);
    int mid = (nb - 1) / 2;
    int i0 = 0, i1 = mid + 1;
    for (int j = l; j <= r; j++)
    {
        if (i0 <= mid && (i1 >= nb || b[i0] < b[i1]))
            a[j] = b[i0++];
        else
            a[j] = b[i1++];
    }
}
void TopDownMergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        TopDownMergeSort(a, l, mid);
        TopDownMergeSort(a, mid + 1, r);
        TopDownMerge(a, l, r);
    }
}
void MergeSort(int a[], int n)
{
    TopDownMergeSort(a, 0, n - 1);
}

//-----------------------------------------

int main()
{
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
