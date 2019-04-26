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
    int posx;
    int posy;
    double q;
public:
    Carga(int nposx, int nposy, double nq):posx(nposx),posy(nposy),q(nq){};
    ~Carga(){};
    double CalcularVoltaje(int posx2, int posy2);
    int Getx(){ return posx;};
    int Gety(){ return posy;};
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
    Simulador(int nnumcargas, double nh, double nw, int nn, int nm);
    ~Simulador();
    Carga ** GetListCarga(){ return ListCarga;};
    void RellenarAleatorio();
    double VoltajeInterceccion(int posx, int posy);
    void ImprimirVolInteracciones();
};

#endif //PROY_SIMULADOR_H
