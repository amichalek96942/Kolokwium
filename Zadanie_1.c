#include <stdio.h>

int process_number(int n);

int main() {
    int start;

    printf("Podaj liczbe startowa (wieksza od 0): ");
    scanf("%d", &start);

    int result = process_number(start);
    if (result != -1) {
        printf("Liczba wykonanych krokow: %d\n", result);
    }

    return 0;
}

int process_number(int n) {
    int steps = 0;


    if (n <= 0) {
        printf("Liczba startowa musi być większa od 0.\n");
        return -1;
    }


    while (n > 1) {
        if (n % 3 == 0) {
            n = n / 3;
        } else if (n % 3 == 1) {
            n = n + 5;
        } else if (n % 3 == 2) {
            n = n - 1;
        }
        steps++;
    }


    return steps;
}