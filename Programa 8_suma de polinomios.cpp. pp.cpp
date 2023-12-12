#include <stdio.h>

/**
 * Sumar valores de arreglo, es decir, obtener sumatoria
 * usando el lenguaje C
 *
 * @author parzibyte
 * https://parzibyte.me/blog
 *
 * */
int main() {
    int numeros[] = {1, 2, 54, 28, 11, 96};
    int longitud = sizeof numeros / sizeof numeros[0];
    int sumatoria = 0;//Aquí vamos a almacenar cada valor
    for (int x = 0; x < longitud; x++) {
        int numeroActual = numeros[x];
        // Sumar el número actual a la sumatoria
        sumatoria = sumatoria + numeroActual;
        // También se puede sumar de forma más simple:
        // sumatoria += numeroActual;
    }
    printf("La sumatoria es: %d", sumatoria);
    return 0;
}

