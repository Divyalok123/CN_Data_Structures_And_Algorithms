/*

Implement a polynomial class, with following properties and functions.
Properties :
1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)

*/
// Note that here we use std::stack  for Stack operations

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;

    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }

        this->capacity = p.capacity;
    }

    void setCoefficient(int d, int val)
    {
        if (d < capacity)
            degCoeff[d] = val;
        else
        {
            int *Coeff = new int[d + 1];
            for (int i = 0; i < d + 1; i++)
            {
                Coeff[i] = 0;
            }

            for (int i = 0; i < capacity; i++)
            {
                Coeff[i] = this->degCoeff[i];
            }

            delete[] degCoeff;
            degCoeff = Coeff;
            capacity = d + 1;

            this->degCoeff[d] = val;
        }
    }

    Polynomial operator+(Polynomial const &p) const
    {
        int newCap = (capacity > p.capacity) ? capacity : p.capacity;
        int *newDeg = new int[newCap];

        for (int i = 0; i < newCap; i++)
        {
            newDeg[i] = 0;
        }

        if (capacity > p.capacity)
        {
            for (int i = 0; i < p.capacity; i++)
            {
                newDeg[i] = degCoeff[i] + p.degCoeff[i];
            }

            for (int i = p.capacity; i < capacity; i++)
            {
                newDeg[i] = degCoeff[i];
            }
        }

        else
        {
            for (int i = 0; i < capacity; i++)
            {
                newDeg[i] = degCoeff[i] + p.degCoeff[i];
            }

            for (int i = capacity; i < p.capacity; i++)
            {
                newDeg[i] = p.degCoeff[i];
            }
        }

        Polynomial p3;
        p3.degCoeff = newDeg;
        p3.capacity = newCap;

        return p3;
    }

    Polynomial operator-(Polynomial const &p) const
    {
        int newCap = (this->capacity > p.capacity) ? this->capacity : p.capacity;
        int *newDeg = new int[newCap];

        for (int i = 0; i < newCap; i++)
        {
            newDeg[i] = 0;
        }

        if (p.capacity >= this->capacity)
        {
            for (int i = 0; i < this->capacity; i++)
            {
                newDeg[i] = this->degCoeff[i] - p.degCoeff[i];
            }

            for (int i = this->capacity; i < p.capacity; i++)
            {
                newDeg[i] = -(p.degCoeff[i]);
            }
        }

        else
        {
            for (int i = 0; i < p.capacity; i++)
            {
                newDeg[i] = this->degCoeff[i] - p.degCoeff[i];
            }

            for (int i = p.capacity; i < this->capacity; i++)
            {
                newDeg[i] = this->degCoeff[i];
            }
        }

        Polynomial p3;
        p3.degCoeff = newDeg;
        p3.capacity = newCap;

        return p3;
    }

    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->degCoeff[i] != 0)
            {
                cout << this->degCoeff[i] << "x" << i << " ";
            }
        }
    }

    Polynomial operator*(Polynomial const &p) const
    {
        int *newDeg = new int[this->capacity + p.capacity - 1];
        int capac = this->capacity + p.capacity - 1;
        for (int i = 0; i < this->capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                newDeg[i + j] += (this->degCoeff[i]) * (p.degCoeff[j]);
            }
        }

        Polynomial p3;
        p3.degCoeff = newDeg;
        p3.capacity = capac;

        return p3;
    }

    void operator=(Polynomial const &p)
    {
        this->capacity = p.capacity;
        for (int i = 0; i < capacity; i++)
        {
            this->setCoefficient(i, p.degCoeff[i]);
        }
    }
};

//Driver program to test above functions
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
