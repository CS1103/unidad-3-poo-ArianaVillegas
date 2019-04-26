//
// Created by ariana on 26/04/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Simulador.h"

TEST_CASE("Carga"){
    Carga carga(12,30,0.0000231);
    SECTION("Comprobar getx"){
        REQUIRE(carga.Getx()==12);
    }
    SECTION("Comprobar gety"){
        REQUIRE(carga.Gety()==30);
    }
    SECTION("Comprobar voltaje"){
        double voltaje=8.99*pow(10,9)*0.0000231/pow(pow(8,2)+pow(5,2),0.5);
        REQUIRE(carga.CalcularVoltaje(20,35)==voltaje);
    }
}