#include "Pantalla.h"
#include "Datos.h"
#include "raylib.h"

#include <cstddef>

bool repetir;
int id_actual = 0, id_proximo = 1, id_segundo, id_tercero;
Jugador actual, proximo, segundo, tercero;

Estado_Juego estado_actual = MENU;

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

std::string texto_pantalla_retos = "Presiona 'Verdad' o 'Reto'\npara iniciar";
std::string texto_jugador_actual = "";
std::string texto_jugador_siguiente = "";
std::string texto_seleccion = "";

float borde_delgado = 2.5f;
float borde_grueso = 3.5f;

float curva_suave = 0.1f;
float curva_fuerte = 0.2f;

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

void actualizar_pantalla_registro(std::string &buffer_nombre, char &sexo_selec){
    Vector2 mouse_pos = GetMousePosition();

    int clave = GetCharPressed();

    while(clave > 0){
        if(clave >= 32 && clave <= 125 && buffer_nombre.length() < 15){

            buffer_nombre += (char)clave;
        }

        clave = GetCharPressed();
    }

    if(IsKeyPressed(KEY_BACKSPACE) && !buffer_nombre.empty()){
        buffer_nombre.pop_back();
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

        if(CheckCollisionPointRec(mouse_pos, boton_masculino)) sexo_selec = 'M';

        if(CheckCollisionPointRec(mouse_pos, boton_femenino)) sexo_selec = 'F';

        if(CheckCollisionPointRec(mouse_pos, boton_agregar)){
            agregar_jugador(buffer_nombre, sexo_selec);
            buffer_nombre = "";
        }

        if(CheckCollisionPointRec(mouse_pos, boton_iniciar_juego) && lista_jugadores.size() >= 2) estado_actual = JUEGO;

        if(CheckCollisionPointRec(mouse_pos, boton_reglas)) estado_actual = REGLAS;
    }
}

void dibujar_pantalla_registro(const std::string buffer_nombre, char sexo_selec){
    DrawRectangleRec(caja_titulo, color_titulo);
    DrawRectangleLines(caja_titulo.x, caja_titulo.y, caja_titulo.width, caja_titulo.height, BLACK);
    DrawText("¿VERDAD O RETO?", caja_titulo.x + 20, caja_titulo.y + 20, 36, WHITE);

    DrawRectangleRounded(caja_agregar_jugador, curva_suave, 12, color_cajas);
    DrawRectangleRoundedLinesEx(caja_agregar_jugador, curva_suave, 12, borde_delgado,borde_fucsia);
    DrawText("AGREGAR JUGADOR", caja_agregar_jugador.x + 29, caja_agregar_jugador.y + 15, 30, WHITE);

    DrawRectangleRounded(caja_nombre, curva_suave, 12, LIGHTGRAY);
    DrawRectangleRoundedLines(caja_nombre, curva_suave, 12, DARKGRAY);
    if(buffer_nombre.empty()){
        DrawText("Escribe un nombre...", caja_nombre.x + 10, caja_nombre.y + 8, 20, GRAY);
    }else{
        DrawText(buffer_nombre.c_str(), caja_nombre.x + 10, caja_nombre.y + 8, 20, BLACK);
    }

    DrawRectangleRounded(boton_masculino, curva_suave, 12, (sexo_selec == 'M')? color_masculino : LIGHTGRAY);
    DrawText("M", boton_masculino.x + 15, boton_masculino.y + 7, 30, (sexo_selec == 'M')? WHITE : BLACK);

    DrawRectangleRounded(boton_femenino, curva_suave, 12, (sexo_selec == 'F')? color_femenino : LIGHTGRAY);
    DrawText("F", boton_femenino.x + 15, boton_femenino.y + 7, 30, (sexo_selec == 'F')? WHITE : BLACK);

    DrawRectangleRounded(boton_agregar, curva_suave, 12, color_agregar);
    DrawText("+", boton_agregar.x + 13, boton_agregar.y + 7, 30, BLACK);

    DrawText("LISTA DE JUGADORES", 39, 310, 30, WHITE);

    DrawRectangleRounded(caja_lista_jugadores, curva_suave, 12, color_cajas);
    DrawRectangleRoundedLinesEx(caja_lista_jugadores, curva_suave, 12, borde_delgado, borde_fucsia);
    for(size_t i = 0; i < lista_jugadores.size(); ++i){
        Color color_sexo = (lista_jugadores[i].sexo == 'M')? color_masculino : color_femenino;

        DrawText(TextFormat("- %s", lista_jugadores[i].nombre.c_str()), caja_lista_jugadores.x + 20, caja_lista_jugadores.y + (15 + (i * 20)), 20, color_sexo);
    }

    DrawRectangleRounded(boton_iniciar_juego, curva_fuerte, 12, (lista_jugadores.size() >= 2)? color_iniciar : LIGHTGRAY);
    DrawRectangleRoundedLinesEx(boton_iniciar_juego, curva_fuerte, 12, borde_grueso, BLACK);
    DrawText("INICIAR JUEGO", boton_iniciar_juego.x + 31, boton_iniciar_juego.y + 12, 30, (lista_jugadores.size() >= 2)? WHITE : DARKGRAY);
    if(lista_jugadores.size() < 2){
        DrawText("Necesitas al menos 2 jugadores", boton_iniciar_juego.x - 10, boton_iniciar_juego.y - 20, 20, RED);
    }

    DrawRectangleRounded(boton_reglas, curva_fuerte, 12, color_reglas);
    DrawRectangleRoundedLinesEx(boton_reglas, curva_fuerte, 12, borde_grueso, BLACK);
    DrawText("REGLAS", boton_reglas.x + 81, boton_reglas.y + 12, 30, WHITE);

    DrawText("creado por: yo", 132, 770, 20, WHITE);
}

void actualizar_pantalla_reglas(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 mouse_pos = GetMousePosition();

        if(CheckCollisionPointRec(mouse_pos, boton_regresar)){
            estado_actual = MENU;
        }
    }
}

void dibujar_pantalla_reglas(){
    DrawRectangleRec(caja_titulo, color_titulo);
    DrawRectangleLines(caja_titulo.x, caja_titulo.y, caja_titulo.width, caja_titulo.height, BLACK);
    DrawText("¿VERDAD O RETO?", caja_titulo.x + 20, caja_titulo.y + 20, 36, WHITE);

    DrawRectangleRounded(caja_mostrar_reglas, curva_suave, 12, color_cajas);
    DrawRectangleRoundedLinesEx(caja_mostrar_reglas, curva_suave, 12, borde_delgado, borde_fucsia);
    DrawText("REGLAS DE JUEGO", caja_mostrar_reglas.x + 37, caja_mostrar_reglas.y + 15, 30, color_reto);

    DrawText(reglas_juego.c_str(), caja_mostrar_reglas.x + 15, caja_mostrar_reglas.y + 60, 20, WHITE);

    DrawRectangleRounded(boton_regresar, curva_fuerte, 12, color_iniciar);
    DrawRectangleRoundedLinesEx(boton_regresar, curva_fuerte, 12, borde_grueso, BLACK);
    DrawText("REGRESAR", boton_regresar.x + 62, boton_regresar.y + 12, 30, WHITE);

    DrawText("creado por: yo", 132, 770, 20, WHITE);
}

void actualizar_pantalla_juego(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !lista_jugadores.empty()){
        Vector2 mouse_pos = GetMousePosition();
        bool boton_presionado = false;

        if(CheckCollisionPointRec(mouse_pos, boton_verdad) || CheckCollisionPointRec(mouse_pos, boton_reto)){
            actual = lista_jugadores[id_actual];
            proximo = lista_jugadores[id_proximo];

            texto_jugador_actual = TextFormat("Turno de: %s", actual.nombre.c_str());
            texto_jugador_siguiente = TextFormat("Siguiente: %s", proximo.nombre.c_str());
        }

        if(CheckCollisionPointRec(mouse_pos, boton_verdad)){
            texto_seleccion = "VERDAD";
            boton_presionado = true;

            int id_pregunta = get_id(static_cast<int>(lista_preguntas.size()));
            Pregunta p = lista_preguntas[id_pregunta];

            texto_pantalla_retos = p.descripcion;
        }

        if(CheckCollisionPointRec(mouse_pos, boton_reto)){
            texto_seleccion = "RETO";
            boton_presionado = true;

            int id_reto = get_id(static_cast<int>(lista_retos.size()));
            Reto r = lista_retos[id_reto];

            switch(r.t_reto){

                case INDIVIDUAL:{
                    texto_pantalla_retos = r.descripcion;

                    break;
                }

                case DUO:{
                    
                    do{
                        repetir = false;

                        id_segundo = get_id(static_cast<int>(lista_jugadores.size()));

                        if(id_segundo == id_actual) repetir = true;

                        if(r.t_pareja == OPUESTO){
                            if(lista_jugadores[id_segundo].sexo == lista_jugadores[id_actual].sexo) repetir = true;
                        }

                    }while(repetir);

                    segundo = lista_jugadores[id_segundo];

                    if(r.tiempo){
                        int tiempo = get_tiempo(id_reto);

                        texto_pantalla_retos = TextFormat(r.descripcion.c_str(), tiempo, segundo.nombre.c_str());

                    }else{
                        texto_pantalla_retos = TextFormat(r.descripcion.c_str(), segundo.nombre.c_str());
                    }

                    break;
                }

                case TRIO:{

                    do{
                        repetir = false;

                        id_segundo = get_id(static_cast<int>(lista_jugadores.size()));

                        if(id_segundo == id_actual) repetir = true;

                        if(r.t_pareja == OPUESTO){
                            if(lista_jugadores[id_segundo].sexo == lista_jugadores[id_actual].sexo) repetir = true;
                        }

                    }while(repetir);

                    do{
                        repetir = false;

                        id_tercero = get_id(static_cast<int>(lista_jugadores.size()));

                        if(id_tercero == id_actual) repetir = true;
                        if(id_tercero == id_segundo) repetir = true;

                    }while(repetir);

                    segundo = lista_jugadores[id_segundo];
                    tercero = lista_jugadores[id_tercero];

                    texto_pantalla_retos = TextFormat(r.descripcion.c_str(), segundo.nombre.c_str(), tercero.nombre.c_str());

                    break;
                }
            }
        }

        if(boton_presionado){
            id_actual = id_proximo;

            if(id_proximo + 1 >= static_cast<int>(lista_jugadores.size())){
                id_proximo = 0;
            }else{
                ++id_proximo;
            }
        }
    }
}

void dibujar_pantalla_juego(){
    DrawRectangleRec(caja_titulo, color_titulo);
    DrawRectangleLines(caja_titulo.x, caja_titulo.y, caja_titulo.width, caja_titulo.height, BLACK);
    DrawText("¿VERDAD O RETO?", caja_titulo.x + 20, caja_titulo.y + 20, 36, WHITE);

    DrawRectangleRounded(caja_actual, curva_suave, 12, color_actual);
    DrawRectangleRoundedLinesEx(caja_actual, curva_suave, 12, borde_delgado, BLACK);
    DrawText(texto_jugador_actual.c_str(), caja_actual.x + 15, caja_actual.y + 13, 30, WHITE);

    DrawRectangleRounded(caja_mostrar_retos, curva_suave, 12, color_cajas);
    DrawRectangleRoundedLinesEx(caja_mostrar_retos, curva_suave, 12, borde_delgado, borde_fucsia);
    texto_centrado(GetFontDefault(), texto_seleccion, caja_mostrar_retos, caja_mostrar_retos.y + 20, 30, 2.0f, (texto_seleccion == "VERDAD")? color_verdad : color_reto);

    DrawText(texto_pantalla_retos.c_str(), caja_mostrar_retos.x + 20, caja_mostrar_retos.y + 80, 24, WHITE);

    DrawRectangleRounded(caja_siguiente, curva_suave, 12, color_siguiente);
    DrawRectangleRoundedLinesEx(caja_siguiente, curva_suave, 12, borde_delgado, BLACK);
    DrawText(texto_jugador_siguiente.c_str(), caja_siguiente.x + 15, caja_siguiente.y + 13, 30, WHITE);

    DrawRectangleRounded(boton_verdad, curva_fuerte, 12, color_verdad);
    DrawRectangleRoundedLinesEx(boton_verdad, curva_fuerte, 12, borde_grueso, BLACK);
    DrawText("VERDAD", boton_verdad.x + 81, boton_verdad.y + 20, 32, BLACK);

    DrawRectangleRounded(boton_reto, curva_fuerte, 12, color_reto);
    DrawRectangleRoundedLinesEx(boton_reto, curva_fuerte, 12, borde_grueso, BLACK);
    DrawText("RETO", boton_reto.x + 103, boton_reto.y + 20, 32, WHITE);

    DrawText("creado por: yo", 132, 770, 20, WHITE);
}