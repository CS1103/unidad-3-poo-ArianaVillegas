//
// Created by ariana on 26/04/19.long long calculate_series(Progression* p,int quantity)
//

#include "Simulador.h"
#include "catch.hpp"

SCENARIO("Carga"){
    GIVEN("Comprobar métodos"){
        WHEN("pos_x y pos_y pueden ser accedidos mediante el método get_x y get_y. Y el voltaje se obtiene a partir"
             "de los datos de la inicialización") {
            Carga carga(12, 30, 0.0000231);
            double voltaje=8.99*pow(10,9)*0.0000231/pow(pow(8,2)+pow(5,2),0.5);
            THEN("posx=12") {
                REQUIRE(carga.Getx() == 12);
                REQUIRE(carga.Gety() == 30);
            }
            THEN("Los puntos x2 y y2 serán 20 y 35 respectivamente"){
                REQUIRE(carga.CalcularVoltaje(20,35)==voltaje);
            }
        }
    }
}

SCENARIO("Simulación"){
    GIVEN("Voltaje interacción"){
        WHEN("EL voltaje de las cargas en el origen de coordenadas cuando no hay cargas") {
            Simulador simulador(0,40,40,2,2);
            THEN("Comprobar que la función obtiene el mismo valor que esta en voltaje total"){
                REQUIRE(simulador.VoltajeInterceccion(6,6)==0);
            }
        }
    }
    GIVEN("Voltaje interacción"){
        WHEN("EL voltaje de las cargas en el origen de coordenadas cuando hay dos cargas") {
            Simulador simulador(2,40,40,2,2);
            simulador.AgregarCarga(0,12, 30, 0.0000231);
            simulador.AgregarCarga(1,32, 35, 0.0000923);
            double voltaje_total =8.99 * pow(10, 9) * 0.0000231 / pow(pow(11, 2) + pow(29, 2), 0.5) + 8.99 * pow(10, 9)
                    *0.0000923 /pow(pow(31, 2) + pow(34, 2),0.5);
            THEN("Comprobar que la función obtiene el mismo valor que esta en voltaje total"){
                REQUIRE(simulador.VoltajeInterceccion(1,1)==voltaje_total);
            }
        }
    }
}