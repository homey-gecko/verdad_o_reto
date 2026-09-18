#pragma once

#include <string>
#include <vector>

enum Tipo_Reto{INDIVIDUAL, DUO, TRIO, GLOBAL};

struct Pregunta{
    std::string descripcion;
};

struct Reto{
    std::string descripcion;
    Tipo_Reto tipo;
    bool tiempo;
};

extern std::vector<Pregunta> lista_preguntas;

extern std::vector<Reto> lista_retos;