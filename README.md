# Maze Solver

> Mój pierwszy projekt programistyczny — prosty solver labiryntów napisany w języku C.

Program wczytuje labirynt zapisany jako obraz **PGM**, szuka drogi od wskazanego pola do krawędzi planszy, a następnie zapisuje odnalezioną trasę w nowym pliku. Projekt powstał jako okazja do nauki pracy ze strukturami danych, dynamiczną alokacją pamięci, rekurencją i obsługą plików binarnych.

## Jak to działa?

Solver porusza się po dostępnych polach labiryntu i zapamiętuje kolejne współrzędne na własnej implementacji stosu. Gdy trafi w ślepą uliczkę, cofa się do ostatniego miejsca, z którego może wybrać inną drogę.

W obrazie wynikowym:

- czarne piksele oznaczają ściany,
- białe piksele oznaczają wolne pola,
- szare piksele pokazują znalezioną trasę.

## Najważniejsze elementy projektu

- odczyt i zapis binarnych plików PGM (`P5`),
- algorytm przeszukiwania labiryntu z nawrotami,
- własna implementacja stosu,
- dynamiczne zarządzanie pamięcią,
- zapis rozwiązania w formie obrazu.

## Uruchomienie

Do kompilacji potrzebny jest kompilator C, na przykład **GCC**.

```bash
cd labirynt
gcc main.c -o maze-solver
```

Uruchom program:

```bash
./maze-solver
```

W systemie Windows:

```powershell
.\maze-solver.exe
```

Program domyślnie:

1. wczytuje plik `lab.pgm`,
2. rozpoczyna szukanie od współrzędnych `{0, 1}`,
3. wypisuje współrzędne znalezionej trasy,
4. zapisuje wynik jako `nowylab.pgm`.

Nazwy plików oraz punkt startowy można zmienić w pliku [`labirynt/main.c`](labirynt/main.c).

## Struktura projektu

```text
MazeSolver2022/
├── labirynt/
│   ├── main.c          # punkt wejścia programu
│   ├── labirynt.c      # solver oraz obsługa plików PGM
│   ├── labirynt.h      # struktury i deklaracje funkcji
│   ├── stos.c          # implementacja stosu
│   └── *.pgm           # przykładowe labirynty i wyniki
└── mergesort/
    ├── main.c
    ├── mergesort.c     # Merge Sort dla listy jednokierunkowej
    └── mergesort.h
```

Folder `mergesort` zawiera dodatkowe ćwiczenie z implementacji sortowania przez scalanie na liście jednokierunkowej.

## Czego nauczył mnie ten projekt?

Ponieważ był to mój pierwszy projekt, pozwolił mi w praktyce poznać podstawy języka C i lepiej zrozumieć działanie algorytmów. Najważniejsze doświadczenia to praca ze wskaźnikami, strukturami, pamięcią dynamiczną, rekurencją oraz reprezentacją danych obrazu.

## Autor

**Mikołaj Szuba**  
Pierwszy projekt programistyczny, rozwijany w ramach nauki języka C.
