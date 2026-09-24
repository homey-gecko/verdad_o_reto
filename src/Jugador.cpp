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

    switch(id_reto){

        case 0: min = 6; max = 10; break;

        case 1: min = 3; max = 6; break;

        case 2: min = 1; max = 3; break;

        case 3: min = 5; max = 10; break;
    }

    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}