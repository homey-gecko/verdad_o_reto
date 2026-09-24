#include "Pantalla.h"
#include "Datos.h"

#include <cstddef>

Estado_Juego estado_actual = MENU;

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

        if(CheckCollisionPointRec(mouse_pos, boton_reglas)) estado_actual = REGLAS1;
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


