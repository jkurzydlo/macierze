#include "matrix.hpp"

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

    // Sprawdzamy, czy macierze A i B są równe
    if (A == B) {
        std::cout << "Macierze A i B są równe.\n";
    } else {
        std::cout << "Macierze A i B są różne.\n";
    }

    // Zakończenie programu
    return 0;
}
