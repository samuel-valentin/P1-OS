#include <stdio.h>
#include <math.h>
#define n 10
#define upper 1
#define lower 0

double area (double );
double pi_value (double );
double fx (double);


double pi_value(double value){
    double base = (upper - lower) / (double)n;      //Calculo de la base, en realidad se calcula la distancia entre los centros de los rectangulos, pero esto es lo mimso que la base
    double suma = 0;

    for (double i = 0; i < n; i++){
        suma+= (fx(i*base) + fx((i + 1) * base)) / 2 * base;
    }

    return suma;
}

double area(double x){
    double value = fx(x);
    return pi_value(value);
}

double fx (double x) {
    return 4.0 / (1.0+(x*x));     //Funcion para calcular pi
}

int main() {
    double pi = area(n);

    printf("El valor de PI con %d intervalo es: %.20f", n,pi);

    return 0;
}
