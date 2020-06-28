// Given an N*M 2D array, print it in spiral form. That is, first you need to print the 1st row, then last column, then last row and then first column and so on.
// Print every element only once.

#include <iostream>
using namespace std;


void spiralPrint(int input[][1000], int row, int col){
    int srow = 0;
    int scol = 0;
    while( srow < row && scol < col)
    {
        for(int i = scol; i < col; i++)
    {
        cout << input[srow][i] << " ";
    }
    srow++;
    for(int i = srow; i < row; i++)
    {
        cout << input[i][col-1] << " ";
    }
    col--;
    
    if(srow < row)
    {
        for(int i = col-1; i >= scol; i--)
        {
            cout << input[row-1][i] << " ";
        }
        row--;
    }
    
    if(scol < col)
    {
        for(int i = row - 1; i >= srow; i--)
        {
            cout << input[i][scol] << " ";
        }
        scol++;
    }
    }
}



int main() {
    int input[1500][1000];
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    spiralPrint(input, row, col);
}