#include <iostream>
using namespace std;

void checkInsert(int arr[], int temp, int index, int elementNumber)
{
    cout << "\nVi tri chen cua a[" << index << "] la " << temp << endl;
    for (int i = 0; i < elementNumber; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionSort(int arr[], int elementNumber)
{
    int index = 1, temp = 0;
    while (index < elementNumber)
    {
        int current = arr[index];
        for (int position = index - 1; position >= 0 && arr[position] < current; position--)
        {

            arr[position + 1] = arr[position];
            arr[position] = current;
            temp = position ;
        }
        checkInsert(arr, temp, index, elementNumber);
        index++;
    }
}
int main()
{
    int elementNumber;
    cin >> elementNumber;
    if (elementNumber == 0)
    {
        cout << "Mang rong.";
        return 0;
    }
    int *arr = new int[elementNumber];
    for (int i = 0; i < elementNumber; i++)
    {
        cin >> arr[i];
    }

    cout << "Mang truoc khi sap xep la:";
    for (int i = 0; i < elementNumber; i++)
    {
        cout << " " << arr[i];
    }
    insertionSort(arr, elementNumber);

    cout << "\nMang sau khi sap xep la:";
    for (int i = 0; i < elementNumber; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}