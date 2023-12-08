#include "matrix.h"

int main() {
    // Przykładowe użycie klasy matrix
    matrix A(30);  // Tworzymy macierz 2x2
    matrix B(30);  // Tworzymy kolejną macierz 2x2

    // Wypełniamy macierze losowymi wartościami
    A.losuj();
    B.losuj();

    matrix P(30);
    matrix P2(30);
    P.wczytaj("C:\\Users\\Jacek\\Desktop\\m1.txt");
    P2.wczytaj("C:\\Users\\Jacek\\Desktop\\m2.txt");
    std::cout << "Macierz P\n" << P << "\nMacierz P2\n" << P2;

    std::cout << "\nP+P2 =\n" << P + P2;
    std::cout << "\nP-P2 =\n" << P - P2;
    std::cout << "\nP*P2 =\n" << P * P2;
    std::cout << "\n++P =\n" << ++P;
    std::cout << "\n--P =\n" << --P;
    std::cout << "\nP-2 =\n" << P - 2;
    std::cout << "\nP+5 =\n" << P + 5;




    std::cout << "Losowa:\n" << A;
    std::cout << "Szachownica:\n" << P.szachownica();

    std::cout << "\nDiagonalna:\n" << A.diagonalna();
    int tab[30];
    for (int i = 0; i < 30; i++) tab[i] = 8;
    std::cout << "\nDiagonalna z parametrem\n" << A.diagonalna(tab);
    std::cout << "\nWybrana diagonalna z parametrem\n" << A.diagonalna_k(10, tab);



    std::cout << "\nOdwrócona P:\n" << P.dowroc();

    std::cout << "\nP nad przekątną\n" << P.nad_przekatna();
    std::cout << "\nP pod przekątną\n" << P.pod_przekatna();


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