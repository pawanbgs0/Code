#include "complex.h"

complex :: complex()
{
    real = imag = 0;
}

complex :: complex(int r,int i)
{
    real = r;
    imag = i;
}

void complex :: set_imaginary(int i)
{
    imag = i;
}

void complex :: set_real(int r)
{
    real = r;
}

void complex :: get_imaginary()
{
    cout << "The imaginary number is:" << imag;
}

void complex :: get_real()
{
    cout << "The real number is:" << real;
}

complex complex :: operator-(complex c1)
{
    complex c3;
    c3.real = this -> real - c1.real;
    c3.imag = this -> imag - c1.imag;
    return c3;
}

complex complex :: operator+(complex c1)
{
    complex c3;
    c3.real = this -> real + c1.real;
    c3.imag = this -> imag + c1.imag;
    return c3;
}

complex complex :: operator*(complex c1)
{
    complex c3;
    c3.real = this -> real * c1.real;
    c3.imag = this -> imag * c1.imag;
    return c3;
}


bool complex :: operator==(complex c)
{
    if(this -> real == c.real && this -> imag == c.imag)
    {
        cout << "Yes,The complex numbers are equal";
        return true;
    }
    else
    {
        cout << "No, The complex numbers are not equal";
        return false;
    }
}

istream &operator>>(istream &in, complex &c)
{
   in >> c.real >> c.imag;
   return in;
}

ostream &operator<<(ostream &out,const complex &c)
{
    out << c.real << " + I" <<c.imag;
    
    return out;
}

// complex operator+(complex c1,complex c2)
// {
//     complex c3;
//     c3.real = c1.real + c2.real;
//     c3.imag = c1.imag + c2.imag;
//     return c3;
// }

// complex operator-(complex c1,complex c2)
// {
//     complex c3;
//     c3.real = c1.real - c2.real;
//     c3.imag = c1.imag - c2.imag;
//     return c3;
// }

