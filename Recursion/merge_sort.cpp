#include <iostream>
using namespace std;

int merge(int input[], int left[], int size1, int right[], int size2)
{
    int i = 0, k = 0, j = 0;

    for (int k = 0; k < size1 + size2; k++)
    {

        if (i < size1 && j < size2)
        {
            if (left[i] <= right[j])
            {
                input[k] = left[i];
                i++;
            }

            else
            {
                input[k] = right[j];
                j++;
            }
        }

        else if (i == size1)
        {
            input[k] = right[j++];
        }

        else if (j == size2)
        {
            input[k] = left[i++];
        }
    }
}

void mergeSort(int input[], int size)
{
    if (size < 2)
        return;
    int mid = size / 2;
    int left[mid], right[size - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = input[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = input[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(input, left, mid, right, size - mid);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}