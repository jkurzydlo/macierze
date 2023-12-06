#include "matrix.h"

int main() {
    // Przykładowe użycie klasy matrix
    matrix A(2);  // Tworzymy macierz 2x2
    matrix B(2);  // Tworzymy kolejną macierz 2x2

    // Wypełniamy macierze losowymi wartościami
    A.losuj();
    B.losuj();

    // Wyświetlamy macierze
    std::cout << "Macierz A:\n" << A << std::endl;
    std::cout << "Macierz B:\n" << B << std::endl;

    // Dodajemy macierze
    matrix C = A + B;
    std::cout << "Macierz C = A + B:\n" << C << std::endl;

    // Mnożymy macierze
    matrix D = A * B;
    std::cout << "Macierz D = A * B:\n" << D << std::endl;
    matrix E = A * 2;
    std::cout << "Macierz E = 2 * A:\n" << E << std::endl;

    matrix J = A - 2;
    std::cout << "Macierz F = A-2:\n" << J << std::endl;

    matrix Z = A + 5;
    std::cout << "Macierz G = 5+A:\n" << J << std::endl;


    matrix G = A;
    matrix H = A;
    matrix F = A.szachownica();
    std::cout << "Szachownica:\n" << F;


    std::cout << "\nDiagonalna:\n" << A.diagonalna();

    std::cout << "\nOdwrócona A:\n" << H.dowroc();

    std::cout << "\nA nad przekątną\n" << G.nad_przekatna();

    // Sprawdzamy, czy macierze A i B są równe
    if (A == B) {
        std::cout << "Macierze A i B są równe.\n";
    }
    else {
        std::cout << "Macierze A i B są równe.\n";
    }


    // Zakończenie programu
    return 0;
}