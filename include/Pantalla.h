#pragma once

#include "raylib.h"

#include <string>

enum Estado_Juego{MENU, JUEGO, REGLAS1, REGLAS2, REGLAS3}; //pantallas

extern Estado_Juego estado_actual;

//colores
static Color color_titulo = GetColor(0x391143FF);
static Color color_cajas = GetColor(0x2A2438FF);
static Color color_agregar = GetColor(0xE5DC38FF);
static Color color_masculino = GetColor(0x3841E5FF);
static Color color_femenino = GetColor(0xDC38E5FF);
static Color color_iniciar = GetColor(0x111B43FF);
static Color color_reglas = GetColor(0x431134FF);
static Color color_actual = GetColor(0x3745AEFF);
static Color color_siguiente = GetColor(0x6537AEFF);
static Color color_verdad = GetColor(0x00E676FF);
static Color color_reto = GetColor(0xE67700FF);

static Color borde_fucsia = GetColor(0x987FC2FF);

static float borde_delgado = 2.5f;
static float borde_grueso = 3.5f;

static float curva_suave = 0.1f;
static float curva_fuerte = 0.2f;

static Rectangle caja_titulo = {0, 0, 400, 80};
static Rectangle caja_agregar_jugador = {25, 110, 350, 180};
static Rectangle caja_nombre = {45, 170, 310, 40};
static Rectangle boton_masculino = {45, 220, 110, 50};
static Rectangle boton_femenino = {175, 220, 110, 50};
static Rectangle boton_agregar = {305, 220, 50, 50};
static Rectangle caja_lista_jugadores = {60, 355, 280, 210};
static Rectangle boton_iniciar_juego = {60, 590, 280, 60};
static Rectangle boton_reglas = {60, 670, 280, 60};

static Rectangle caja_actual = {30, 110, 340, 60};
static Rectangle caja_mostrar_retos = {10, 180, 380, 320};
static Rectangle caja_siguiente = {30, 510, 340, 60};
static Rectangle boton_verdad = {55, 595, 290, 80};
static Rectangle boton_reto = {55, 685, 290, 80};

static Rectangle caja_mostrar_reglas = {10, 90, 380, 550};
static Rectangle boton_regresar = {60, 670, 280, 60};

void actualizar_pantalla_registro(std::string &buffer_nombre, char &sexo_selec);
void dibujar_pantalla_registro(const std::string buffer_nombre, char sexo_selec);

void actualizar_pantalla_reglas();
void dibujar_pantalla_reglas();

void actualizar_pantalla_juego();
void dibujar_pantalla_juego();