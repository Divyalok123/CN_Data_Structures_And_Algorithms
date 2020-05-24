// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int size)
{
    int count = 0;
    int p = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[p])
            count++;
    }
    swap(&arr[p], &arr[count]);
    p = count;

    int i = 0, j = size - 1;

    while (i < p && j > p)
    {
        if (arr[i] >= arr[p])
        {
            if (arr[j] < arr[p])
            {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }

    return p;
}

void quickSort(int input[], int size)
{
    if (size < 2)
        return;

    int p;
    p = partition(input, size);
    quickSort(input, p);
    quickSort(input + (p + 1), size - (p + 1));
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
