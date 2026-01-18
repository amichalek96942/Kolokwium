#include <stdio.h>

void grid_update(const int src[5][5], int dest[5][5]) {
    // Iteracja po każdym polu w macierzy
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Oblicz sumę wartości bezpośrednich sąsiadów
            int suma_sasiadow = 0;

            // Sprawdź sąsiada z góry
            if (i - 1 >= 0) {
                suma_sasiadow += src[i - 1][j];
            }
            // Sprawdź sąsiada z dołu
            if (i + 1 < 5) {
                suma_sasiadow += src[i + 1][j];
            }
            // Sprawdź sąsiada z lewej
            if (j - 1 >= 0) {
                suma_sasiadow += src[i][j - 1];
            }
            // Sprawdź sąsiada z prawej
            if (j + 1 < 5) {
                suma_sasiadow += src[i][j + 1];
            }

            // Porównaj wartość src[i][j] z obliczoną sumą sąsiadów
            if (src[i][j] > suma_sasiadow) {
                dest[i][j] = 2; // Jeśli wartość większa od sumy, wpisz 2
            } else if (src[i][j] == suma_sasiadow) {
                dest[i][j] = 1; // Jeśli wartość równa sumie, wpisz 1
            } else {
                dest[i][j] = 0; // Jeśli wartość mniejsza od sumy, wpisz 0
            }
        }
    }
}

int main() {
    int src[5][5];
    int dest[5][5] = {0};

    // Wczytywanie wartości do macierzy wejściowej
    printf("Podaj wartosci dla macierzy 5x5 (wiersz po wierszu):\n");
    for (int i = 0; i < 5; i++) {
        printf("Podaj wartosci dla wiersza %d (5 liczb):\n", i);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &src[i][j]);
        }
    }

    // Wywołanie funkcji grid_update
    grid_update(src, dest);

    // Wypisanie macierzy wejściowej (src)
    printf("\nMacierz wejściowa (src):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", src[i][j]);
        }
        printf("\n");
    }

    // Wypisanie macierzy wynikowej (dest)
    printf("\nMacierz wynikowa (dest):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", dest[i][j]);
        }
        printf("\n");
    }

    return 0;
}