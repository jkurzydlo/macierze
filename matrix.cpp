#include "matrix.hpp"
#include <cstdlib>
#include <ctime>

matrix::matrix() {
    data = nullptr;
    size = 0;
}

matrix::matrix(int n) {
    alokuj(n);
}

matrix::matrix(int n, int* t) {
    alokuj(n);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = t[i * size + j];
        }
    }
}

matrix::matrix(const matrix& m) {
    alokuj(m.size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

matrix::~matrix() {
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

matrix& matrix::alokuj(int n) {
    if (data != nullptr) {
        // Sprawdzamy czy rozmiar alokacji jest równy zdeklarowanemu rozmiarowi
        if (size != n) {
            // Jeśli nie, zwalniamy pamięć i alokujemy ponownie
            for (int i = 0; i < size; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }
    // Jeśli data == nullptr lub rozmiar alokacji jest różny od zdeklarowanego
    if (data == nullptr) {
        size = n;
        data = new int*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }
    }
    return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc) {
    // Wstawiamy wartość do odpowiedniego miejsca w macierzy
    // (zakładam, że x i y są poprawne)
    data[x][y] = wartosc;
    return *this;
}

int matrix::pokaz(int x, int y) {
    // Zwracamy wartość elementu x, y
    // (zakładam, że x i y są poprawne)
    return data[x][y];
}

// Kolejne metody...

