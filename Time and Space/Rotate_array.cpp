// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

#include <iostream>
using namespace std;

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int size)
{
    int i = 0;
    int j = size-1;
    while(i < j)
    {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
}

void Rotate(int arr[], int d, int size) {
    reverse(arr, size);
    reverse(arr, size - d);
    reverse(arr + size-d, d);
}	

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		Rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}