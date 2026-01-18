#include <stdio.h>

int text_processor(const char *str);

int main() {
    char test_str[100];  // Tablica na ciąg znaków - zakładamy maksymalnie 99 znaków + 1 na '\0'

    printf("Podaj lancuch znakow do przetworzenia: ");
    scanf("%99s", test_str); // Wczytanie ciągu znaków z wejścia - ograniczenie długości do 99 znaków

    int result = text_processor(test_str);
    printf("Wynik dla podanego lancucha \"%s\": %d\n", test_str, result);

    return 0;
}

int text_processor(const char *str) {
    int total = 0;
    int sign = 1;

    // Przetwarzanie łańcucha znaków znak po znaku
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i]; // Aktualny znak

        if (ch >= 'A' && ch <= 'Z') {
            total += 10 * sign;
        }

        else if (ch >= '0' && ch <= '9') {
            int digit = ch - '0'; // Zamiana znaku na wartość cyfry
            if (digit % 2 == 0) {
                sign = 1; // Cyfra parzysta: ustaw znak na dodatni
            } else {
                sign = -1; // Cyfra nieparzysta: ustaw znak na ujemny
            }
        }
        // Jeśli znak jest wykrzyknikiem ('!'), zresetuj total do zera
        else if (ch == '!') {
            total = 0;
        }
    }

    return total; // Zwrócenie wyniku (wartości total)
}
