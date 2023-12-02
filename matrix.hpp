#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class matrix {
private:
    int** data;  // Wskaźnik do dynamicznie alokowanej macierzy
    int size;     // Rozmiar macierzy (ilość wierszy/kolumn)

public:
    matrix();
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m);
    ~matrix();

    matrix& alokuj(int n);
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    matrix& dowroc();
    matrix& losuj();
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int y, int* t);
    matrix& diagonalna();
};

#endif // MATRIX_HPP
