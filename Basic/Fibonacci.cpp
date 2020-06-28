// Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
// Fibonacci Series is defined by the recurrence
//     F(n) = F(n-1) + F(n-2)

#include<iostream>
using namespace std;

#include <cmath>

bool isPerfect(int n)
{
    int t = sqrt(n);
    return t*t == n;
}

bool checkMember(int n){
    if(isPerfect(5*n*n - 4) || isPerfect(5*n*n + 4))
    {
        return true;
    }
    return false;
}


int main(){

  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

}


