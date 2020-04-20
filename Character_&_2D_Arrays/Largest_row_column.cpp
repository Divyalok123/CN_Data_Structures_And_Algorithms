// Given an NxM 2D array, you need to find out which row or column has largest sum (sum of its elements) overall amongst all rows and columns.
// Input Format :
//  Line 1 : 2 integers N and M respectively, separated by space 
//  Line 2: Single line having N*M elements entered in row wise manner, each separated by space.
// Output Format :
//  If row sum is maximum then - "row" row_num max_sum
//  If column sum is maximum then - "column" col_num max_sum
// Note : If there are more than one rows/columns with maximum sum consider the row/column that comes first. And if ith row and jth column has same sum (which is largest), consider the ith row as answer.

#include<iostream>
using namespace std;

void findLargest(int arr[][1000], int row, int col){
    int sumrow = 0;
    int sumcol = 0;
    int rowidx = 0, colidx = 0;
    for(int i = 0; i < row; i++)
    {
        int sum = 0;
        for(int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if(sum > sumrow) {
            sumrow = sum;
            rowidx = i;
        }
    }
    
    for(int j = 0; j < col; j++)
    {
        int sum = 0;
        for(int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        if(sum > sumcol)
        {
            sumcol = sum;
            colidx = j;
        }
    }
    
    if(sumrow >= sumcol)
    {
        cout << "row " << rowidx << " " << sumrow;
        
    }
    else
    {
        cout << "column " << colidx << " " << sumcol;
    }
}


int main() {
    int row, col;
    cin >> row >> col;

    int input[1000][1000]; 
    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    findLargest(input, row, col);
}