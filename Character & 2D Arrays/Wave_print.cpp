// Given a two dimensional n*m array, print the array in a sine wave order. i.e. print the first column top to bottom, next column bottom to top and so on.
// Note : Print the elements separated by space.

#include <iostream>
using namespace std;

void wavePrint(int input[][1000], int row, int col){
    for(int i = 0; i < col; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j < row; j++)
            {
                cout << input[j][i] << " ";
            }
        }
        else
        {
            for(int j = row-1; j >= 0; j--)
            {
                cout << input[j][i] << " ";
            }
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
    wavePrint(input, row, col);
}