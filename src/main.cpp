#include "Pantalla.h"
#include "raylib.h"

#include <string>

// Estados del juego
enum EstadoJuego{PANTALLA_REGISTRO, PANTALLA_JUEGO};

static Color color_fondo = {30, 27, 36, 255};

int main(){
    const int anchoPantalla = 800;
    const int altoPantalla = 917;
    InitWindow(anchoPantalla, altoPantalla, "Verdad o Reto - C++ & Raylib");
    SetTargetFPS(60);

    std::string buffer_nombre = "";
    char sexo_selecionado = 'M';


    // Bucle principal del juego
    while(!WindowShouldClose()){

        if(estado_actual == MENU){
            actualizar_pantalla_registro(buffer_nombre, sexo_selecionado);

        }else if(estado_actual == REGLAS){
            actualizar_pantalla_reglas();

        }else{
            actualizar_pantalla_juego();
        }

        BeginDrawing();
        ClearBackground(color_fondo);

        if(estado_actual == MENU){
            dibujar_pantalla_registro(buffer_nombre, sexo_selecionado);

        }else if(estado_actual == REGLAS){
            dibujar_pantalla_reglas();

        }else{
            dibujar_pantalla_juego();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
