#include "Pantalla.h"
#include "Datos.h"

void actualizar_pantalla_reglas(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 mouse_pos = GetMousePosition();

        if(CheckCollisionPointRec(mouse_pos, boton_regresar)){

            if(estado_actual == REGLAS1){
                estado_actual = REGLAS2;

            }else if(estado_actual == REGLAS2){
                estado_actual = REGLAS3;

            }else{
                estado_actual = MENU;
            }
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

    if(estado_actual == REGLAS1){
        DrawText(reglas_pagina1.c_str(), caja_mostrar_reglas.x + 15, caja_mostrar_reglas.y + 60, 20, WHITE);

    }else if(estado_actual == REGLAS2){
        DrawText(reglas_pagina2.c_str(), caja_mostrar_reglas.x + 15, caja_mostrar_reglas.y + 60, 20, WHITE);

    }else{
        DrawText(reglas_pagina3.c_str(), caja_mostrar_reglas.x + 15, caja_mostrar_reglas.y + 60, 20, WHITE);
    }

    DrawRectangleRounded(boton_regresar, curva_fuerte, 12, color_iniciar);
    DrawRectangleRoundedLinesEx(boton_regresar, curva_fuerte, 12, borde_grueso, BLACK);
    if(estado_actual == REGLAS3){
        DrawText("REGRESAR", boton_regresar.x + 62, boton_regresar.y + 12, 30, WHITE);
    }else{
        DrawText("AVANZAR", boton_regresar.x + 62, boton_regresar.y + 12, 30, WHITE);
    }

    DrawText("creado por: yo", 132, 770, 20, WHITE);
}
