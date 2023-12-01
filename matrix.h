#pragma once
#include <iostream>
class matrix
{
	int rozmiar_m = 0;
	int** tab;
public:
	matrix() {}
	matrix(int rozmiar) {
		this->rozmiar_m = rozmiar;
		alokuj(rozmiar_m);
	}
	matrix(int, int*) {}
	matrix(matrix&) {}
	~matrix() {}
	matrix& alokuj(int);
	matrix& wstaw(int, int, int);
	int pokaz(int x, int y) const  { return tab[x][y]; }
	matrix& odwroc();
	matrix& losuj();
	matrix& losuj(int);
	matrix& diagonalna(int*);
	matrix& diagonalna_k(int, int*);
	matrix& kolumna(int, int*);
	matrix& wiersz(int, int*);
	matrix& przekatna();
	matrix& pod_przekatna();
	matrix& szachownica();
	matrix operator+(matrix&);
	matrix operator*(matrix&);
	matrix operator-(int);
	matrix operator*(int);
	matrix operator+(int);
	friend matrix operator+(int, matrix&);
	friend matrix operator*(int, matrix&);
	friend matrix operator-(int, matrix&);
	matrix& operator++(int);
	matrix& operator--(int);
	matrix& operator+=(int);
	matrix& operator*=(int);
	matrix& operator-=(int);
	matrix& operator+(double);
	friend std::ostream& operator<<(std::ostream, matrix&);
	bool operator==(const matrix&);
	bool operator>(const matrix&);
	bool operator<(const matrix&);


};

