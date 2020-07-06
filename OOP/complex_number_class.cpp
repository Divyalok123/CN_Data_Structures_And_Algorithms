/*

A ComplexNumber class contains two data members : one is the real part (R) and the other is imaginary (I) (both integers).
Implement the Complex numbers class that contains following functions -
1. constructor
You need to create the appropriate constructor.
2. plus -
This function adds two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 3 +i1
C1.plus(C2) results in: 
C1 = 7 + i6 and C2 = 3 + i1
3. multiply -
This function multiplies two given complex numbers and updates the first complex number.
e.g.
if C1 = 4 + i5 and C2 = 1 + i2
C1.multiply(C2) results in: 
C1 = -6 + i13 and C2 = 1 + i2
4. print -
This function prints the given complex number in the following format :
a + ib
Note : There is space before and after '+' (plus sign) and no space between 'i' (iota symbol) and b.

*/

#include <iostream>
using namespace std;

class ComplexNumbers
{
private:
    int real;
    int imag;

public:
    ComplexNumbers(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void plus(ComplexNumbers const &x)
    {
        this->real = this->real + x.real;
        this->imag = this->imag + x.imag;
    }

    void multiply(ComplexNumbers const &x)
    {
        int val1 = this->real;
        int val2 = this->imag;
        this->real = (val1 * x.real) - (val2 * x.imag);
        this->imag = (val1 * x.imag) + (val2 * x.real);
    }

    void print()
    {
        cout << this->real << " + i" << this->imag << endl;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}
