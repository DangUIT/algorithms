/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

//###INSERT CODE HERE -
void quickSort(int a[], int low, int high)
{
    int i = low, j = high;
    int pivot = a[(low+high)/2];
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        quickSort(a, low, j);
    if (i < high)
        quickSort(a, i, high);
}
void quick_sort_ascending(int a[], int n)
{
    quickSort(a, 0, n - 1);
}
int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
