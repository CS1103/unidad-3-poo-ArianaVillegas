#define CATCH_CONFIG_MAIN

#include <iostream>
#include <cmath>
#include "Simulador.h"

#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN
int main() {
    double w,h;
    int num_cargas,n,m;
    std::cout<<"\nIngresa el ancho del tablero: ";std::cin>>w;
    std::cout<<"\nIngresa el largo del tablero: ";std::cin>>h;
    std::cout<<"\nIngresa el número de cargas: ";std::cin>>num_cargas;
    std::cout<<"\nIngresa el número de líneas en el ancho: ";std::cin>>m;
    std::cout<<"\nIngresa el número de líneas en el ancho: ";std::cin>>n;
    Simulador S(num_cargas,w,h,n,m);
    S.Rellenar();
    S.ImprimirVolInteracciones();
}
#endif