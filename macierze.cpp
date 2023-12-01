#include <iostream>
#include "matrix.h"
int main()
{
    matrix m1;
    m1.alokuj(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) m1.wstaw(i, j, i);

    matrix m2;
    m2.alokuj(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) m2.wstaw(i, j, i);

   //std::cout<< m1.pokaz(3, 0);
    std::cout << (m1 + m2).pokaz(3, 0) << "\n";
    std::cout << (m1 * m2).pokaz(2, 2);
    //std::cout << (m1 += 2);
    //std::cout<< (m1 -= 2);
    //std::cout<< (m1 *= 2);
    //std::cout<< (m1 + 2);
    //std::cout<< (m1 -= 2);
    //matrix m3 = m1 * m2;
    //std::cout << m3;
    //std::cout << std::boolalpha << (m1 == m2);
}