#include <iostream>
#include <cmath>
#include "Simulador.h"

int main() {
    srand(time(nullptr));
    int n=rand()%30+1;
    int m=rand()%40+1;
    Simulador S(2,200,200,n,m);
    S.RellenarAleatorio();
    S.ImprimirVolInteracciones();
}