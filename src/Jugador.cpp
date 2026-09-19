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

void escoger_jugadores(const int &p, int &c){
    do{
        c = get_id(lista_jugadores.size());
    }while(c == p);
}

void escoger_jugadores(const int &p, int &s, int &c){
    bool repetir;

    do{
        repetir = false;

        s = get_id(lista_jugadores.size());

        if(s == p) repetir = true;

        if(lista_jugadores[s].sexo == lista_jugadores[p].sexo) repetir = true;

    }while(repetir);

    do{
        repetir = false;

        c = get_id(lista_jugadores.size());

        if(c == p) repetir = true;
        if(c == s) repetir = true;

    }while(repetir);
}

void escoger_jugadores(const int &p, int &s, int &t, int &c){
    bool repetir;

    do{
        repetir = false;

        s = get_id(lista_jugadores.size());

        if(s == p) repetir = true;

        if(lista_jugadores[s].sexo == lista_jugadores[p].sexo) repetir = true;

    }while(repetir);

    do{
        repetir = false;

        t = get_id(lista_jugadores.size());

        if(t == p) repetir = true;
        if(t == s) repetir = true;

    }while(repetir);

    do{
        repetir = false;

        c = get_id(lista_jugadores.size());

        if(c == p) repetir = true;
        if(c == s) repetir = true;
        if(c == t) repetir = true;

    }while(repetir);
}