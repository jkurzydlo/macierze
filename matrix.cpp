#include "matrix.h"
#include <iostream>
matrix matrix::operator+(matrix& m2)
{
    matrix temp(rozmiar_m);
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++) {
            temp.tab[i][j] = tab[i][j] + m2.tab[i][j];
        }
    return temp;
}

matrix matrix::operator*(matrix& m2)
{
    matrix temp(rozmiar_m);

    for (int i = 0; i < rozmiar_m; i++) {
        for (int j = 0; j < rozmiar_m; j++) {
            for (int k = 0; k < rozmiar_m; k++) {
                temp.tab[i][j] += tab[i][k] * m2.tab[k][j];
            }
        }
    }
    return temp;
}

matrix matrix::operator-(int l)
{
    matrix temp(rozmiar_m);

    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            temp.tab[i][j] = tab[i][j] - l;
}

matrix matrix::operator*(int l)
{
    matrix temp(rozmiar_m);

    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            temp.tab[i][j] = tab[i][j] * l;
}

matrix matrix::operator+(int l)
{
    matrix temp(rozmiar_m);

    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            temp.tab[i][j] = tab[i][j] + l;
}

matrix& matrix::operator++(int)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            tab[i][j]++;
    return *this;
}

matrix& matrix::operator--(int)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            tab[i][j]--;
    return *this;
}

matrix& matrix::operator+=(int l)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            tab[i][j]+=l;
    return *this;
}

matrix& matrix::operator*=(int l)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            tab[i][j]*=l;
    return *this;
}

matrix& matrix::operator-=(int l)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            tab[i][j]-=l;
    return *this;
}


bool matrix::operator==(const matrix& m2)
{
    for (int i = 0; i < rozmiar_m; i++)
        for (int j = 0; j < rozmiar_m; j++)
            if (tab[i][j] != m2.tab[i][j]) 
                return false;
    return true;
}

bool matrix::operator>(const matrix& m2)
{
    int sum1=0, sum2 = 0;
    for (int i = 0; i < rozmiar_m; i++) sum1 += tab[i][j];
    for (int i = 0; i < rozmiar_m; i++) sum2 += m2.tab[i][j];

    return (sum1 > sum2);

}

bool matrix::operator<(const matrix& m2)
{
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < rozmiar_m; i++) sum1 += tab[i][j];
    for (int i = 0; i < rozmiar_m; i++) sum2 += m2.tab[i][j];

    return (sum1 < sum2);

}


matrix& matrix::alokuj(int rozmiar)
{

    rozmiar_m = rozmiar;
    tab = new int*[rozmiar * rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        tab[i] = new int[rozmiar];
    }

    for (int i = 0; i < rozmiar;i++)
        for (int j = 0; j < rozmiar; j++) tab[i][j] = 0;
    return *this;

}

matrix& matrix::wstaw(int x, int y, int wartosc)
{
    tab[x][y] = wartosc;
    return *this;
}

matrix operator+(int l, matrix& m2)
{
    matrix temp(m2.rozmiar_m);
    for (int i = 0; i < m2.rozmiar_m; i++) {
        for (int j = 0; j < m2.rozmiar_m; j++) {
            temp.tab[i][j] = m2.tab[i][j] + l;
        }
    }
    return temp;
}

matrix operator*(int l, matrix& m2)
{
    matrix temp(m2.rozmiar_m);
    for (int i = 0; i < m2.rozmiar_m; i++) {
        for (int j = 0; j < m2.rozmiar_m; j++) {
            temp.tab[i][j] = m2.tab[i][j] * l;
        }
    }
    return temp;
}

matrix operator-(int l , matrix& m2)
{
    matrix temp(m2.rozmiar_m);
    for (int i = 0; i < m2.rozmiar_m; i++) {
        for (int j = 0; j < m2.rozmiar_m; j++) {
            temp.tab[i][j] = m2.tab[i][j] - l;
        }
    }
    return temp;
}

std::ostream& operator<<(std::ostream os, matrix& m2)
{
    for (int i = 0; i < m2.rozmiar_m; i++) {
        for (int j = 0; j < m2.rozmiar_m; j++) os << m2.tab[i][j] << " ";
        os << std::endl;
    }

}
