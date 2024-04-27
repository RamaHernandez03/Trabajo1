#include <stdio.h>

#define CANTIDAD_PLACAS 491

void mostrarPlacas(int placas[], int cantidad) {
    printf("Placas electrónicas creadas:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Placa %d: %d\n", i + 1001, placas[i]);
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
            *placasMaximas = 1; 
        } else if (temperaturas[i] == maxima) {
            (*placasMaximas)++;
        }
    }
    return maxima;
}

float calcularTemperaturaPromedio(float temperaturas[], int cantidadPlacas) {
    float suma = 0.0;

    for (int i = 0; i < cantidadPlacas; i++) {
        suma += temperaturas[i];
    }
    return suma / cantidadPlacas;
}

void generarResumen(float temperaturas[], int cantidadPlacas, float promedio) {
    printf("Resumen de placas con temperaturas superiores al promedio (%.2f°C):\n", promedio);
    for (int i = 0; i < cantidadPlacas; i++) {
        if (temperaturas[i] > promedio) {
            printf("Placa %d: %.2f°C\n", i + 1001, temperaturas[i]);
        }
    }
}

int contarPlacasMenores(float temperaturas[], int cantidadPlacas, float limite) {
    int contador = 0;

    for (int i = 0; i < cantidadPlacas; i++) {
        if (temperaturas[i] < limite) {
            contador++;
        }
    }

    return contador;
}

void mostrarPlacasEnRango(float temperaturas[], int cantidadPlacas, float min, float max) {
    printf("Placas con temperaturas entre %.2f°C y %.2f°C:\n", min, max);
    for (int i = 0; i < cantidadPlacas; i++) {
        if (temperaturas[i] >= min && temperaturas[i] <= max) {
            printf("Placa %d: %.2f°C\n", i + 1001, temperaturas[i]);
        }
    }
}

int main() {
    int opcion;
    int placas[CANTIDAD_PLACAS];
    float temperaturas[CANTIDAD_PLACAS];

    for (int i = 0; i < CANTIDAD_PLACAS; i++) {
        placas[i] = 1001 + i;
    }

    ingresarTemperaturas(temperaturas, CANTIDAD_PLACAS);

    do {
        printf("\nMenú:\n");
        printf("1) Encontrar temperatura máxima\n");
        printf("2) Calcular temperatura promedio\n");
        printf("3) Generar resumen de placas con temperaturas superiores al promedio\n");
        printf("4) Contar placas con temperaturas menores a 30°C\n");
        printf("5) Mostrar placas con temperaturas entre 50°C y 70°C\n");
        printf("0) Salir\n");

        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int placasMaximas;
                float maxima = encontrarTemperaturaMaxima(temperaturas, CANTIDAD_PLACAS, &placasMaximas);
                printf("Temperatura máxima: %.2f°C, alcanzada por %d placa(s)\n", maxima, placasMaximas);
                break;
            }
            case 2: {
                float promedio = calcularTemperaturaPromedio(temperaturas, CANTIDAD_PLACAS);
                printf("Temperatura promedio: %.2f°C\n", promedio);
                break;
            }
            case 3: {
                float promedio = calcularTemperaturaPromedio(temperaturas, CANTIDAD_PLACAS);
                generarResumen(temperaturas, CANTIDAD_PLACAS, promedio);
                break;
            }
            case 4: {
                int cantidadMenores = contarPlacasMenores(temperaturas, CANTIDAD_PLACAS, 30.0);
                printf("Cantidad de placas con temperaturas menores a 30°C: %d\n", cantidadMenores);
                break;
            }
            case 5: {
                mostrarPlacasEnRango(temperaturas, CANTIDAD_PLACAS, 50.0, 70.0);
                break;
            }
            case 0: {
                printf("Saliendo del programa...\n");
                printf("¡Programa Finalizado!");
                break;
            }
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } 
    
    while (opcion != 0);
    return 0;
}



