#include <stdio.h>


int recursive_series(int n);

int main() {
    int n;

    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);


    int result = recursive_series(n);
    printf("Wynik dla n = %d to: %d\n", n, result);

    return 0;
}

int recursive_series(int n) {

    if (n <= 1) {
        return 1;
    }

    else if (n % 2 == 0) {
        return recursive_series(n / 2) + 2;
    }

    else {
        return recursive_series(n - 1) * 3;
    }
}