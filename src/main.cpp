#include "Pantalla.h"
#include "raylib.h"

#include <string>

static Color color_fondo = GetColor(0x1E1B24FF);

int main(){
    const int anchoPantalla = 400;
    const int altoPantalla = 800;
    InitWindow(anchoPantalla, altoPantalla, "Verdad o Reto - C++ & Raylib");
    SetTargetFPS(60);

    std::string buffer_nombre = "";
    char sexo_selecionado = 'M';

    // Bucle principal del juego
    while(!WindowShouldClose()){

        if(estado_actual == MENU){
            actualizar_pantalla_registro(buffer_nombre, sexo_selecionado);

        }else if(estado_actual == REGLAS1 || estado_actual == REGLAS2 || estado_actual == REGLAS3){
            actualizar_pantalla_reglas();

        }else{
            actualizar_pantalla_juego();
        }

        BeginDrawing();
        ClearBackground(color_fondo);

        if(estado_actual == MENU){
            dibujar_pantalla_registro(buffer_nombre, sexo_selecionado);

        }else if(estado_actual == REGLAS1 || estado_actual == REGLAS2 || estado_actual == REGLAS3){
            dibujar_pantalla_reglas();

        }else{
            dibujar_pantalla_juego();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
