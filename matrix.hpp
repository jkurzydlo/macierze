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
    matrix& pod_przekatna();
    matrix& nad_przekatna();
    matrix& szachownica();

    matrix& operator+(matrix& m);
    matrix& operator*(matrix& m);
    matrix& operator-(matrix& m);
    matrix& operator=(matrix& m);
    matrix& operator+(int a);
    matrix& operator*(int a);
    matrix& operator-(int a);
    friend matrix operator+(int a, matrix& m);
    friend matrix operator*(int a, matrix& m);
    friend matrix operator-(int a, matrix& m);
    matrix& operator++();
    matrix& operator--();
    matrix& operator*(double a);

    friend std::ostream& operator<<(std::ostream& o, matrix& m);

    bool operator==(const matrix& m);
    bool operator>(const matrix& m);
    bool operator<(const matrix& m);
};

#endif // MATRIX_HPP
