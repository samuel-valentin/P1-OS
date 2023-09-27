#include <stdio.h>
#include <time.h>

#define n 999999
#define upper 1
#define lower 0

double area (double );
double pi_value ();
double fx (double);


double pi_value(){
    double base = (upper - lower) / (double)n;      //Calculo de la base, en realidad se calcula la distancia entre los centros de los rectangulos, pero esto es lo mimso que la base
    double suma = 0;

    for (double i = 0; i < n; i++){
        suma+= (fx(i*base) + fx((i + 1) * base)) / 2 * base;
    }

    return suma;
}

double fx (double x) {
    return 4.0 / (1.0+(x*x));     //Funcion para calcular pi
}

int main() {
    clock_t inicio, fin;
    double tiempo;
    inicio = clock();       // Inicio del temporizador

    double pi = pi_value();
    printf("El valor de PI con %d intervalo es: %.20f\n", n,pi);

    fin = clock();      // Fin del temporizador

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;           // Calcular el tiempo transcurrido en segundos

    printf("Tiempo de ejecucion: %.4fs\n", tiempo);

    return 0;
}
