#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void printarr(int* arr, int n)
{
    for(int i =  0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partitioner(int* arr, int start, int end)
{
    int i = 0;
    int pivot = end;
    int j = 0;
    while(j < end)
    {
        if(arr[j] < arr[pivot])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j++;
        }

        else j++;
    }

    int temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;

    return i;
}

int randomised_partitioner(int* arr, int start, int end)
{
    srand(time(NULL));
    int random = start + rand()%(end-start);

    int temp = arr[end];
    arr[end] = arr[random];
    arr[random] = temp;

    return partitioner(arr, start, end);
}

void quicksort(int* arr, int start, int end)
{
    if(start < end)
    {
        int partitionIndex = randomised_partitioner(arr, start, end);
        quicksort(arr, start, partitionIndex-1);
        quicksort(arr, partitionIndex+1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // int n;
    // cin >> n;
    // int* arr = new int[n];
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    ifstream file;
    file.open("qsort.txt");

    if(file.fail())
    {
        cout << "Didn't read" << endl;
        exit(1);
    }

    int* arr = new int[201];
    for(int i = 0; i < 200; i++)
    {
        file >> arr[i];
    }

    cout << endl << "Before sorting: ";
    printarr(arr, 200);

    quicksort(arr, 0, 199);

    // quicksort(arr, 0, n-1);

    cout << endl << "After sorting: ";
    printarr(arr, 200);

    return 0;
}