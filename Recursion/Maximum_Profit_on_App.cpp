// You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.
// You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.
// Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :
//  m * x
// where m is total number of buyers whose budget is greater than or equal to x.

#include <iostream>
#include <algorithm>
using namespace std;

int maximumProfit(int budget[], int n) {
    int storage[1000000], size = 0;
    sort(budget, budget+n);
    for(int i = 0; i < n; i++)
    {
        int val = budget[i];
        int sum = n-i;
        
        storage[size] = sum*val;
        size++;
    }
    
    int max = storage[0];
    
    for(int i = 0; i <size; i++)
    {
        if(storage[i] > max) max = storage[i];
    }
    
    return max;

}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
