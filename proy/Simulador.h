//
// Created by ariana on 23/04/19.
//

#ifndef PROY_SIMULADOR_H
#define PROY_SIMULADOR_H

#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>

class Carga{
private:
    long k=8.99*pow(10,9);
    double posx;
    double posy;
    double q;
public:
    Carga(double nposx, double nposy, double nq):posx(nposx),posy(nposy),q(nq){};
    ~Carga(){};
    double CalcularVoltaje(double posx2, double posy2);
    double Getx(){ return posx;};
    double Gety(){ return posy;};
};

class Simulador{
private:
    Carga** ListCarga= nullptr;
    int numcargas;
    double h;
    double w;
    int n;
    int m;
public:
    Simulador(int nnumcargas, double nw, double nh, int nm, int nn);
    ~Simulador();
    void AgregarCarga(int i, double x, double y, double q);
    void Rellenar();
    double VoltajeInterceccion(int posx, int posy);
    void ImprimirVolInteracciones();
};

#endif //PROY_SIMULADOR_H
