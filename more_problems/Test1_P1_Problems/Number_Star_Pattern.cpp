// Print the following pattern for given number of rows.
// Input format :

// Line 1 : N (Total number of rows)

// Sample Input :
//    5
// Sample Output :
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << " ";
		}
		for (int j = i; j >= 1; j--)
		{
			cout << j;
		}
		for (int j = 2; j <= i; j++)
		{
			cout << j;
		}
		cout << "\n";
	}
	return 0;
}
