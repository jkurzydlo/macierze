#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

matrix::matrix() {
    data = nullptr;
    size = 0;
}

matrix::matrix(int n) {
    alokuj(n);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            data[i][j] = 0;
        }
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
        data = new int* [size];
        for (int i = 0; i < size; ++i) {
            data[i] = new int[size];
        }
    }
    return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc) {
    // Wstawiamy wartość do odpowiedniego miejsca w macierzy
    data[x][y] = wartosc;
    return *this;
}

int matrix::pokaz(int x, int y) {
    // Zwracamy wartość elementu x, y
    return data[x][y];
}

matrix& matrix::dowroc() {
    // Zamieniamy wiersze z kolumnami
    matrix temp = *this;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = temp.data[j][i];
        }
    }
    return *this;
}

matrix& matrix::losuj() {
    // Losujemy wartości do macierzy
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = rand() % 10;
        }
    }
    return *this;
}

matrix& matrix::losuj(int x){
    // wypełniamy cyframi od 0 do 9 elementy macierzy. Zmienna x określa ile cyfr będziemy losować. 
    // Następnie algorytm losuje, w które miejsca wstawi wylosowane cyfry, aż do wypełnienia macierzy
    srand(static_cast<unsigned int>(time(0)));
    int* t = new int[x];
    for(int i = 0; i < x; ++i){
        t[i] = rand() % 10;
    }
    int i = 0;
    int j = 0;
    while(i < size){
        while(j < size){
            data[i][j] = t[rand() % x];
            ++j;
        }
        j = 0;
        ++i;
    }
    return *this;
}

matrix& matrix::diagonalna(int* t) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                data[i][j] = t[i];
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& matrix::diagonalna_k(int k, int* t) {
    // Wstawiamy wartości do macierzy na przekątnej k
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j + k) {
                data[i][j] = t[i];
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& matrix::diagonalna() {
    // Wstawiamy wartości do macierzy na przekątnej
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& matrix::kolumna(int x, int* t) {
    // Wstawiamy wartości do kolumny x
    for (int i = 0; i < size; ++i) {
        data[i][x] = t[i];
    }
    return *this;
}

matrix& matrix::wiersz(int x, int* t) {
    // Wstawiamy wartości do wiersza x
    for (int i = 0; i < size; ++i) {
        data[x][i] = t[i];
    }
    return *this;
}

matrix& matrix::pod_przekatna() {
    // Wstawiamy wartości pod przekątną
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i > j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& matrix::nad_przekatna() {
    // Wstawiamy wartości nad przekątną
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i < j) {
                data[i][j] = 1;
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}

matrix& matrix::szachownica() {
    // Wstawiamy wartości do macierzy w szachownicę
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i + j) % 2 == 0) {
                data[i][j] = 0;
            }
            else {
                data[i][j] = 1;
            }
        }
    }
    return *this;
}

matrix& matrix::operator+(matrix& m) {
    // Dodawanie macierzy A+B
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return *temp;
}

// Operatorzy

matrix& matrix::operator-(matrix& m) {
    // Odejmowanie macierzy A-B
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] - m.data[i][j];
        }
    }
    return *temp;
}

matrix& matrix::operator*(matrix& m) {
    // Mnożenie macierzy A*B
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                temp->data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return *temp;
}

matrix& matrix::operator*(int x) {
    // Mnożenie macierzy przez liczbę całkowitą x
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] * x;
        }
    }
    return *temp;
}

matrix& matrix::operator-(int a) {
    // Odejmowanie liczby całkowitej a od macierzy
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] - a;
        }
    }
    return *temp;
}

matrix& matrix::operator++() {
    // Dodawanie 1 do każdego elementu macierzy
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] + 1;
        }
    }
    return *temp;
}

matrix& matrix::operator--() {
    // Odejmowanie 1 od każdego elementu macierzy
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] - 1;
        }
    }
    return *temp;
}

matrix& matrix::operator+(int a) {
    // Dodawanie liczby całkowitej a do macierzy
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] + a;
        }
    }
    return *temp;
}

matrix& matrix::operator=(matrix& m) {
    // Przypisanie macierzy A = B
    if (this == &m) {
        return *this;
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                data[i][j] = m.data[i][j];
            }
        }
    }
    return *this;
}

matrix& matrix::operator*(double a) {
    // Mnożenie macierzy przez liczbę zmiennoprzecinkową a
    matrix* temp = new matrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp->data[i][j] = data[i][j] * a;
        }
    }
    return *temp;
}


std::ostream& operator<<(std::ostream& o, matrix& m) {
    // Wypisywanie macierzy
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            o << m.data[i][j] << " ";
        }
        o << std::endl;
    }
    return o;
}

bool matrix::operator==(const matrix& m) {
    // Porównywanie macierzy
    if (size != m.size) {
        return false;
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] != m.data[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool matrix::operator>(const matrix& m) {
    // Porównywanie większości macierzy
    if (size != m.size) {
        return false;
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] <= m.data[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool matrix::operator<(const matrix& m) {
    // Porównywanie mniejszości macierzy
    if (size != m.size) {
        return false;
    }
    else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (data[i][j] >= m.data[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}
