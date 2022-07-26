/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void hoanvi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

//###INSERT CODE HERE -

void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void selection_sort_decending(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[min])
                min = j;
        }
        hoanvi(a[min], a[i]);
    }
}
int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    selection_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}
