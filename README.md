# macierze
Napisz klasę matrix. Macierz jest kwadratowa (n na n) gdzie n jest wielkością macierzy.
Macierz jest przechowywana w zmiennej dynamicznej (na stercie). Funkcjonalność (metod) klasy:
• matrix(void); //konstruktor domyślny bez alokacji pamięci,
• matrix(int n); //przeciążeniowy alokuje macierz o wymiarach n na n,
• matrix(int n , int* t); //przeciążeniowy alokuje pamięć i przepisuje dane
z tabeli,
• matrix(matrix& m); //konstruktor kopiujący,
• ~matrix(void); //destruktor,
• matrix& alokuj(int n); //jeśli macierz nie ma zaalokowanej pamięci to ją
alokuje w wielkości n na n, jeśli macierz ma zaalokowaną pamięć to sprawdza czy
rozmiar alokacji jest równy zdeklarowanemu rozmiarowi. W przypadku gdy tej
pamięci jest mniej, pamięć ma zostać zwolniona i zaalokowana ponownie w żądanym
rozmiarze. W przypadku gdy tej pamięci jest więcej pozostawić alokację bez zmian.
• matrix& wstaw(int x, int y, int wartosc); //wiersz, kolumna, wartość,
• int pokaz(int x, int y); //zwraca wartość elementu x, y,
• matrix& dowroc(void); //zamienia wiersze z kolumnami
• matrix& losuj(void); //wypełniamy cyframi od 0 do 9 wszystkie elementy
macierzy
• matrix& losuj(int x); //wypełniamy cyframi od 0 do 9 elementy macierzy.
Zmienna x określa ile cyfr będziemy losować. Następnie algorytm losuje, w które
miejsca wstawi wylosowane cyfry,
• matrix& diagonalna(int* t); //po przekątnej są wpisane dane z tabeli,
a pozostałe elementy są równe 0,
• matrix& diagonalna_k(int k, int* t); // po przekątnej są wpisane dane z tabeli,
a pozostałe elementy są równe 0. Parametr k może oznaczać: 0 - przekątna
przechodząca przez środek (czyli tak jak metoda diagonalna), cyfra dodatnia przesuwa
diagonalną do góry macierzy o podaną cyfrę, cyfra ujemna przesuwa diagonalną
w dół o podaną cyfrę,
• matrix& kolumna(int x, int* t); //przepisuje dane z tabeli do kolumny, którą
wskazuje zmienna x,
• matrix& wiersz(int y, int* t); //przepisuje dane z tabeli do wiersza, który
wskazuje zmienna x,
• matrix& przekatna(void); //uzupełnia macierz: 1-na przekątnej, 0-poza
przekątną,
• matrix& pod_przekatna(void); //uzupełnia macierz: 1-pod przekątną, 0-nad
przekątną i po przekątnej,
• matrix& nad_przekatna(void); //uzupełnia macierz: 1-nad przekątną, 0-pod
przekątną i po przekątnej,
• matrix& szachownica(void); //uzupełnia macierz w ten sposób dla n=4:
0101
1010
0101
1010
• matrix& operator+(matrix& m); //A+B
• matrix& operator*(matrix& m); //A*B
• matrix& operator+(int a); //A+int
• matrix& operator*(int a); //A*int
• matrix& operator-(int a); //A-int
• friend matrix operator+(int a, matrix& m); //int+A
• friend matrix operator*(int a, matrix& m); //int*A
• friend matrix operator-(int a, matrix& m); //int-A
• matrix& operator++(int); //A++ wszystkie liczby powiększone o 1
• matrix& operator--(int); //A-- wszystkie liczby pomniejszone o 1
• matrix& operator+=(int a); //każdy element w macierzy powiększamy o „a”
• matrix& operator-=(int a); //każdy element w macierzy pomniejszamy o „a”
• matrix& operator*=(int a); //każdy element w macierzy mnożymy o „a”
• matrix& operator(double); //wszystkie cyfry są powiększone o część
całkowitą z wpisanej cyfry
• friend ostream& operator<<(ostream& o, matrix& m); //wypisanie macierzy
• bool operator==(const matrix& m); //sprawdza, czy każdy element macierzy
spełnia równość 𝐴(𝑛, 𝑚) = 𝐵(𝑛, 𝑚)
A=|1 2| B=|1 2|
 |3 4| |3 4|
jeśli nie, to nie możemy mówić że macierze są równe,
• bool operator>(const matrix& m); //operator większości sprawdza, czy każdy
element macierzy spełnia nierówność 𝐴(𝑛, 𝑚) > 𝐵(𝑛, 𝑚). Jeśli tak, to możemy
powiedzieć że macierz jest większa, w przeciwnym wypadku nie możemy stwierdzić,
że macierz jest większa.
• bool operator<(const matrix& m); //tak jak wyżej tylko operator mniejszości.
