#include <stdio.h>

#define CANTIDAD_PLACAS 491

void mostrarPlacas(int placas[], int cantidad) {
    printf("Placas electrónicas creadas:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d\n", placas[i]);
    }
}

void ingresarTemperaturas(float temperaturas[], int cantidadPlacas) {
    printf("Ingrese las temperaturas para las %d placas:\n", cantidadPlacas);
    for (int i = 0; i < cantidadPlacas; i++) {
        printf("Temperatura para la placa %d (en grados Celsius): ", i + 1001);
        scanf("%f", &temperaturas[i]);
    }
}

float encontrarTemperaturaMaxima(float temperaturas[], int cantidadPlacas, int *placasMaximas) {
    float maxima = temperaturas[0];
    *placasMaximas = 1;

    for (int i = 1; i < cantidadPlacas; i++) {
        if (temperaturas[i] > maxima) {
            maxima = temperaturas[i];
            *placasMaximas = 1; // 
        } else if (temperaturas[i] == maxima) {
            (*placasMaximas)++;
        }
    }

    return maxima;
}

int main() {
    int placas[CANTIDAD_PLACAS];
    float temperaturas[CANTIDAD_PLACAS];
    int placasMaximas;
    float temperaturaMaxima;

    for (int i = 0; i < CANTIDAD_PLACAS; i++) {
        placas[i] = 1001 + i;
    }

    ingresarTemperaturas(temperaturas, CANTIDAD_PLACAS);
    mostrarPlacas(placas, CANTIDAD_PLACAS);

    temperaturaMaxima = encontrarTemperaturaMaxima(temperaturas, CANTIDAD_PLACAS, &placasMaximas);
    printf("Temperatura máxima encontrada: %.2f°C\n", temperaturaMaxima);
    printf("Número de placas que alcanzaron la temperatura máxima: %d\n", placasMaximas);

    return 0;
}