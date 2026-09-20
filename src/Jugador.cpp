#include "Datos.h"

#include <random>

std::vector<Jugador> lista_jugadores;

static std::random_device ran;
static std::mt19937 gen(ran());

void agregar_jugador(const std::string &nom, char sex){

    lista_jugadores.push_back({nom, sex});
}

const int get_id(int tamaño_vector){
    std::uniform_int_distribution<> distrib(0, tamaño_vector - 1);

    return distrib(gen);
}

const int get_tiempo(int id_reto){
    int min, max;

    if(id_reto == 15){
        min = 6;
        max = 10;
    }else if(id_reto == 16){
        min = 3;
        max = 6;
    }else{
        min = 1;
        max = 3;
    }

    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}