#pragma once

#include <string>
#include <vector>

extern std::string reglas_juego;

enum Tipo_Reto{INDIVIDUAL, DUO, TRIO};
enum Tipo_Pareja{CUALQUIERA, OPUESTO};

struct Jugador{
    std::string nombre;
    char sexo;
};

struct Pregunta{
    std::string descripcion;
};

struct Reto{
    std::string descripcion;
    Tipo_Reto t_reto;
    Tipo_Pareja t_pareja;
    bool tiempo;
};

extern std::vector<Jugador> lista_jugadores;
extern std::vector<Pregunta> lista_preguntas;
extern std::vector<Reto> lista_retos;

void agregar_jugador(const std::string &nom, char sex);

const int get_id(int tamaño_vector);
const int get_tiempo(int id_reto);

void escoger_jugadores(const int &p, int &c);
void escoger_jugadores(const int &p, int &s, int &c);
void escoger_jugadores(const int &p, int &s, int &t, int &c);

/*const std::string &seleccionar_reto(const Reto &reto, const Jugador &jugador);*/
