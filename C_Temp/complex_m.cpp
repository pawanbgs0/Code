#include "complex.h"

int main()
{
    complex c1;
    complex c2;
    c1.set_imaginary(11);
    c2.set_imaginary(11);
    c1.set_real(2);
    c2.set_real(2);
    // int a = c1.get_imaginary();
    // int b = c2.get_imaginary();
    // complex c3 = c1 + c2;
    // complex c4 = c2 - c1;
    // complex c5 = c2 * c1;
    cout << (c2 == c1);
    cout << c1;
    // c5.get_imaginary();
    // cout << endl;
    // c5.get_real();
    // cout << a << b;
}