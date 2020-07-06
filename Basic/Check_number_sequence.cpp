// You are given S a sequence of n integers i.e. S = s1, s2, ..., sn. Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.
// That is, in the sequence if numbers are decreasing, they can start increase at one point. And once number starts increasing, they cannot decrease at any point further.
// Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence. So in both the cases, print true.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	bool valid = true;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			valid = false;
		}
	}

	if (arr[1] > arr[0])
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				valid = false;
				break;
			}
		}
	}
	else
	{
		int i = 0;
		while (arr[i] > arr[i + 1])
		{
			i++;
		}
		for (int j = i; j < n - 1; j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				valid = false;
				break;
			}
		}
	}
	if (valid)
	{
		cout << "true"
			 << "\n";
	}
	else
	{
		cout << "false"
			 << "\n";
	}
	return 0;
}
