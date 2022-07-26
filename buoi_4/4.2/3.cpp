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

//###INSERT CODE HERE -
bool isMinHeap(int a[], int n)
{
    int left, right, min;
    for (int i = 0; i < n; i++)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        min = i;
        if (left < n && right < n && (a[min] >= a[left] || a[min] >= a[right]))
            return false;
    }
    return true;
}

//--------------------
int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    std::cout << "MinHeap: " << std::boolalpha << isMinHeap(a, n) << std::endl;

    return 0;
}
