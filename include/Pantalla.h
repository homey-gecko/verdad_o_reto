#pragma once

#include <string>

enum Estado_Juego{MENU, JUEGO}; //pantallas

extern Estado_Juego estado_actual;

void actualizar_pantalla_registro(std::string &buffer_nombre, char &sexo_selec);
void dibujar_pantalla_registro(const std::string buffer_nombre, char sexo_selec);

void actualizar_pantalla_juego();
void dibujar_pantalla_juego();