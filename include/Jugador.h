#pragma once

#include <string>
#include <vector>

struct Reto;

struct Jugador{
    std::string nombre;
    char sexo;
};

extern std::vector<Jugador> lista_jugadores;

void agregar_jugador(const std::string &nom, char sex);

const int get_id(int tamaño_vector);
const int get_tiempo(int id_reto);

void escoger_jugadores(const int &p, int &c);
void escoger_jugadores(const int &p, int &s, int &c);
void escoger_jugadores(const int &p, int &s, int &t, int &c);

/*const std::string &seleccionar_reto(const Reto &reto, const Jugador &jugador);*/
