#include "Pantalla.h"

#include <cstddef>

#include "raylib.h"

#include "Jugador.h"
#include "Listas.h"

Estado_Juego estado_actual = MENU;

//colores
static Color color_fondo = {30, 27, 36, 255};
static Color color_titulo = {58, 30, 122, 255};
static Color color_cajas = {42, 36, 56, 255};
static Color color_agregar = {255, 161, 0, 255};
static Color color_masculino = {32, 51, 255, 255};
static Color color_femenino = {192, 65, 255, 255};
static Color color_siguiente = {116, 0, 165, 255};
static Color color_verdad = {0, 230, 118, 255};
static Color color_reto = {255, 61, 0, 255};

static Color borde_fucsia = {152, 127, 194, 255};

std::string texto_pantalla_retos = "Presiona 'Verdad' o 'Reto' para iniciar";
std::string texto_jugador_siguiente = "";
std::string texto_seleccion = "";

static Rectangle caja_titulo = {0, 0, 410, 105};
static Rectangle caja_agregar_jugador = {17, 120, 380, 230};
static Rectangle caja_nombre = {47, 201, 320, 50};
static Rectangle boton_masculino = {47, 271, 120, 60};
static Rectangle boton_femenino = {177, 271, 120, 60};
static Rectangle boton_agregar = {307, 271, 60, 60};
static Rectangle caja_lista_jugadores = {61, 427, 290, 250};
static Rectangle boton_iniciar_juego = {61, 724, 290, 80};

static Rectangle caja_mostrar_retos = {0, 125, 412, 320};
static Rectangle caja_siguiente = {20, 465, 370, 90};
static Rectangle boton_verdad = {62, 627, 290, 80};
static Rectangle boton_reto = {62, 727, 290, 80};


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
    }
}

void dibujar_pantalla_registro(const std::string buffer_nombre, char sexo_selec){
    DrawRectangleRec(caja_titulo, color_titulo);
    DrawRectangleLines(caja_titulo.x, caja_titulo.y, caja_titulo.width, caja_titulo.height, BLACK);
    DrawText("¿VERDAD O RETO?", 86, 33, 32, WHITE);

    DrawRectangleRounded(caja_agregar_jugador, 0.3f, 4, color_cajas);
    DrawRectangleRoundedLines(caja_agregar_jugador, 0.3f, 4, borde_fucsia);
    DrawText("AGREGAR JUGADOR", caja_agregar_jugador.x + 34, caja_agregar_jugador.y + 21, 32, WHITE);

    DrawRectangleRounded(caja_nombre, 0.3f, 4, LIGHTGRAY);
    DrawRectangleRoundedLines(caja_nombre, 0.3f, 4, DARKGRAY);
    if(buffer_nombre.empty()){
        DrawText("Escribe un nombre...", caja_nombre.x + 10, caja_nombre.y + 10, 24, GRAY);
    }else{
        DrawText(buffer_nombre.c_str(), caja_nombre.x + 10, caja_nombre.y + 10, 24, BLACK);
    }

    DrawRectangleRounded(boton_masculino, 0.3f, 4, (sexo_selec == 'M')? color_masculino : LIGHTGRAY);
    DrawText("M", boton_masculino.x + 10, boton_masculino.y + 10, 32, (sexo_selec == 'M')? WHITE : BLACK);

    DrawRectangleRounded(boton_femenino, 0.3f, 4, (sexo_selec == 'F')? color_femenino : LIGHTGRAY);
    DrawText("F", boton_femenino.x + 10, boton_femenino.y + 10, 32, (sexo_selec == 'F')? WHITE : BLACK);

    DrawRectangleRounded(boton_agregar, 0.3f, 4, color_agregar);
    DrawText("+", boton_agregar.x + 10, boton_agregar.y + 10, 32, BLACK);

    DrawText("LISTA DE JUGADORES", 36, 367, 32, WHITE);

    DrawRectangleRounded(caja_lista_jugadores, 0.3f, 4, color_cajas);
    DrawRectangleRoundedLines(caja_lista_jugadores, 0.3f, 4, borde_fucsia);
    for(size_t i = 0; i < lista_jugadores.size(); ++i){
        Color color_sexo = (lista_jugadores[i].sexo == 'M')? color_masculino : color_femenino;

        DrawText(TextFormat("- %s", lista_jugadores[i].nombre.c_str()), caja_lista_jugadores.x + 20, caja_lista_jugadores.y + (20 + (i * 25)), 24, color_sexo);
    }

    DrawRectangleRounded(boton_iniciar_juego, 0.3f, 4, (lista_jugadores.size() >= 2)? color_titulo : LIGHTGRAY);
    DrawRectangleRoundedLines(boton_iniciar_juego, 0.3f, 4, BLACK);
    DrawText("¡INICIAR JUEGO!", boton_iniciar_juego.x + 29, boton_iniciar_juego.y + 20, 32, (lista_jugadores.size() >= 2)? WHITE : DARKGRAY);
    if(lista_jugadores.size() < 2){
        DrawText("Necesitas al menos 2 jugadores", boton_iniciar_juego.x + 56, boton_iniciar_juego.y + 80, 20, RED);
    }

    DrawText("creado por: yo", 117, 877, 20, WHITE);
}

void actualizar_pantalla_juego(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !lista_jugadores.empty()){
        Vector2 mouse_pos = GetMousePosition();

        int id_p, id_c;
        Jugador principal, proximo;

        id_p = get_id(lista_jugadores.size());
        principal = lista_jugadores[id_p];

        if(CheckCollisionPointRec(mouse_pos, boton_verdad)){
            texto_seleccion = "VERDAD";

            int id_pregunta = get_id(lista_preguntas.size());
            Pregunta p = lista_preguntas[id_pregunta];

            texto_pantalla_retos = TextFormat(p.descripcion.c_str(), principal.nombre.c_str());

            escoger_jugadores(id_p, id_c);

            proximo = lista_jugadores[id_c];
            texto_jugador_siguiente = TextFormat("Siguiente: %s", proximo.nombre.c_str());
        }

        if(CheckCollisionPointRec(mouse_pos, boton_reto)){
            texto_seleccion = "RETO";

            int id_reto = get_id(lista_retos.size());
            Reto r = lista_retos[id_reto];

            switch(r.tipo){

                case GLOBAL:{
                    texto_pantalla_retos = r.descripcion;

                    escoger_jugadores(id_p, id_c);

                    break;
                }

                case INDIVIDUAL:{
                    texto_pantalla_retos = TextFormat(r.descripcion.c_str(), principal.nombre.c_str());

                    escoger_jugadores(id_p, id_c);

                    break;
                }

                case DUO:{
                    int id_s;
                    Jugador secundario;

                    escoger_jugadores(id_p, id_s, id_c);

                    secundario = lista_jugadores[id_s];

                    if(r.tiempo){
                        int tiempo = get_tiempo(id_reto);

                        texto_pantalla_retos = TextFormat(r.descripcion.c_str(), principal.nombre.c_str(), tiempo, secundario.nombre.c_str());

                    }else{
                        texto_pantalla_retos = TextFormat(r.descripcion.c_str(), principal.nombre.c_str(), secundario.nombre.c_str());
                    }

                    break;
                }

                case TRIO:{
                    int id_s, id_t;
                    Jugador secundario, terciario;

                    escoger_jugadores(id_p, id_s, id_t, id_c);

                    secundario = lista_jugadores[id_s];
                    terciario = lista_jugadores[id_t];

                    texto_pantalla_retos = TextFormat(r.descripcion.c_str(), principal.nombre.c_str(), secundario.nombre.c_str(), terciario.nombre.c_str());

                    break;
                }
            }
        }

        proximo = lista_jugadores[id_c];
        texto_jugador_siguiente = TextFormat("Siguiente: %s", proximo.nombre.c_str());
    }
}

void dibujar_pantalla_juego(){
    DrawRectangleRec(caja_titulo, color_titulo);
    DrawRectangleLines(caja_titulo.x, caja_titulo.y, caja_titulo.width, caja_titulo.height, BLACK);
    DrawText("¿VERDAD O RETO?", 86, 33, 32, WHITE);

    DrawRectangleRounded(caja_mostrar_retos, 0.3f, 4, color_cajas);
    DrawRectangleRoundedLines(caja_mostrar_retos, 0.3f, 4, borde_fucsia);
    DrawText(texto_seleccion.c_str(), caja_mostrar_retos.x + 86, caja_mostrar_retos.y + 12, 32, WHITE);

    DrawText(texto_pantalla_retos.c_str(), caja_mostrar_retos.x + 26, caja_mostrar_retos.y + 102, 24, WHITE);

    DrawRectangleRounded(caja_siguiente, 0.3f, 4, color_titulo);
    DrawRectangleRoundedLines(caja_siguiente, 0.3f, 4, BLACK);
    DrawText(texto_jugador_siguiente.c_str(), caja_siguiente.x + 25, caja_siguiente.y + 26, 32, WHITE);

    DrawRectangleRounded(boton_verdad, 0.3f, 4, color_verdad);
    DrawRectangleRoundedLines(boton_verdad, 0.3f, 4, BLACK);
    DrawText("VERDAD", boton_verdad.x + 81, boton_verdad.y + 20, 32, BLACK);

    DrawRectangleRounded(boton_reto, 0.3f, 4, color_reto);
    DrawRectangleRoundedLines(boton_reto, 0.3f, 4, BLACK);
    DrawText("RETO", boton_reto.x + 103, boton_reto.y + 20, 32, WHITE);
}