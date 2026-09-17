#pragma once

#include <string>
#include <vector>

struct Jugador{
    std::string nombre;
    std::string sexo;
};

extern std::vector<Jugador> lista_jugadores;

void agregar_jugador();
void mostrar_jugadores();

void iniciar_turno();