#include <iostream>
#include<locale.h>
#include<time.h>

using namespace std;


int MDC(int a, int b) {
    while (b != 0) {
        int resultado;
        resultado = a % b;
        a = b;
        b = resultado;
    }
    return a;
}

int mmc(int a, int b) {
    int resultado = a * (b / MDC(a, b));
    return resultado; 
}

int main() {
   
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    clock_t inicio, termino;
    inicio = clock();
    int vetA[20000], vetB[20000], resultado;

    for (int i = 0; i < 20000; i++) {
        vetA[i] = rand() % 2000 + 1;
    }

    for (int i = 0; i < 20000; i++) {
        vetB[i] = rand() % 25000 + 1;
    }

     printf("RESULTADO");
    for (int i = 0; i < 20000; i++) {
        resultado = mmc(vetA[i], vetB[i]);
        printf("MMC(%d,%d) = %d", vetA[i],vetB[i],resultado);
        printf("\n");

    }
    termino = clock();
    int tempo = 1000 * ((double)(termino - inicio) / (double)CLOCKS_PER_SEC);
    printf("tempo %d ms",tempo);
    printf("\n");
    system("pause");
    return 0;
}
