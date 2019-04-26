//
// Created by ariana on 23/04/19.
//

#include "Simulador.h"

double Carga::CalcularVoltaje(int posx2, int posy2) {
    int x=posx2-posx;
    int y=posy2-posy;
    double v=k*q*1.0/pow(pow(x,2)+pow(y,2),0.5);
    return v;
}

Simulador::Simulador(int nnumcargas, double nh, double nw, int nn, int nm) {
    numcargas=nnumcargas;
    ListCarga = new Carga*[nnumcargas];
    h=nh;
    w=nw;
    n=nn;
    m=nm;
}

Simulador::~Simulador() {
    for(int i=0;i<numcargas;i++)
        delete ListCarga[i];
    delete[] ListCarga;
}

bool PosNoOcupada(int i,double x,double y,Carga** l){
    for(int j=0;j<i;j++) {
        if (l[j]->Getx() == x && l[j]->Gety() == y)
            return 0;
    }
    return 1;
}

void Simulador::RellenarAleatorio() {
    srand(time(nullptr));
    int i=0;
    while (i<numcargas){
        int x,y;
        long q;
        std::cout<<"Ingresa x de la carga";std::cin>>x;
        std::cout<<"Ingresa y de la carga";std::cin>>y;
        std::cout<<"Ingresa q de la carga";std::cin>>q;
        //Rellenar aleatorio
        /*int x=rand()%(n+1);
        int y=rand()%(m+1);
        double q=rand()%int(pow(10,3))*0.001;*/
        if(PosNoOcupada(i,x,y,ListCarga)==1) {
            Carga *ncarga = new Carga(x, y, q);
            ListCarga[i]=ncarga;
        }
        i++;
    }
}

double Simulador::VoltajeInterceccion(int posx, int posy) {
    double voltaje=0;
    for (int i=0;i<numcargas;i++){
        voltaje+=ListCarga[i]->CalcularVoltaje(posx,posy);
    }
    return voltaje*pow(10,-9);
}

void Simulador::ImprimirVolInteracciones() {
    for(int i=m;i<w;i+=m)
        for(int j=n;j<h;j+=n)
            std::cout<<i<<' '<<j<<' '<<VoltajeInterceccion(i,j)<<'\n';
}