/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <climits>
// #include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
//###INSERT CODE HERE -
//-----------------------------------
void merge_2_Sorted_subArray(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;
    int A[MAXN], B[MAXN];
    for (i = 0; i < n1; i++)
        A[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        B[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (A[i] < B[j])
        {
            a[k] = A[i];
            i++;
        }
        else
        {
            a[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = A[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = B[j];
        j++;
        k++;
    }
}

//----------------------------------
void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    int l = 0, r = n - 1, middle = (l + r) / 2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
