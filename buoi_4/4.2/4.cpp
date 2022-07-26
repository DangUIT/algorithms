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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//###INSERT CODE HERE -
void Heapify(int a[], int heapSize, int i)
{
    int childLeft = i * 2 + 1;
    int childRight = i * 2 + 2;
    int max = i;
    if (childLeft < heapSize && a[max] < a[childLeft])
        max = childLeft;
    if (childRight < heapSize && a[max] < a[childRight])
        max = childRight;
    if (max != i)
    {
        swap(a[max], a[i]);
        Heapify(a, heapSize, max);
    }
}
void BuildHeap(int a[], int n)
{
    int heapSize = n;
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, heapSize, i);
}

void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
//-------------------------------------
int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    BuildHeap(a, n);

    XuatMang(a, n);

    return 0;
}
