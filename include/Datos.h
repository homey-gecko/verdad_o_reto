#pragma once

#include "raylib.h"

#include <string>
#include <vector>

extern std::string reglas_pagina1, reglas_pagina2, reglas_pagina3;

enum Tipo_Reto{INDIVIDUAL, DUO, TRIO};
enum Tipo_Pareja{CUALQUIERA, OPUESTO, MASCULINO, FEMENINO};
enum Sexo_Limitante{HOMBRE, MUJER, NINGUNO};

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
    Sexo_Limitante s_limitante;
    bool tiempo;
};

extern std::vector<Jugador> lista_jugadores;
extern std::vector<Pregunta> lista_preguntas;
extern std::vector<Reto> lista_retos;

void agregar_jugador(const std::string &nom, char sex);

const int get_id(int tamaño_vector);
const int get_tiempo(int id_reto);

/*const std::string &seleccionar_reto(const Reto &reto, const Jugador &jugador);*/

void texto_centrado(Font fuente, const std::string &texto, Rectangle contenedor, float pos_y, float tam_fuente, float espaciado, Color color);