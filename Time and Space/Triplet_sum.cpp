// Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
// While printing a triplet, print the smallest element first.
// That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.

#include <iostream>
#include <algorithm>
using namespace std;

void FindTriplet(int arr[], int n, int sum)
{
    sort(arr, arr + n);

    if (n <= 2)
        return;

    if (n == 3)
    {
        if ((arr[0] + arr[1] + arr[2]) == sum)
            cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        else
            return;
    }

    if ((arr[0] == arr[n - 1]) && (3 * arr[0] == sum))
    {
        int count = ((n * (n - 1) * (n - 2)) / 6);

        for (int i = 0; i < count; i++)
        {
            cout << arr[0] << " " << arr[0] << " " << arr[0] << endl;
        }

        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        int val = arr[i];
        while (l < r)
        {
            if ((arr[l] + arr[r] + val) == sum)
            {
                cout << val << " " << arr[l] << " " << arr[r] << "\n";
                r--;

                int count = 1;
                while (((arr[l] + arr[r] + val) == sum) && l < r)
                {
                    cout << val << " " << arr[l] << " " << arr[r] << "\n";
                    r--;
                    count++;
                }

                r += count;

                l++;
            }

            else if ((arr[l] + arr[r] + val) < sum)
            {
                l++;
            }
            else
                r--;
        }
    }
}

int main()
{

    int size;

    int x;
    cin >> size;

    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;

    FindTriplet(input, size, x);

    return 0;
}
