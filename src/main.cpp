#include <iostream>

#include "Jugador.h"
#include "Listas.h"

#include "raylib.h"



int main(){
    // 1. Inicializar la ventana (Resolución típica de pruebas 800x450)
    const int pantallaAncho = 800;
    const int pantallaAlto = 450;
    InitWindow(pantallaAncho, pantallaAlto, "Verdad o Reto - Pruebas Raylib");

    // 2. Variables del juego (Una pelota que se mueve)
    Vector2 posicionPelota = { (float)pantallaAncho / 2, (float)pantallaAlto / 2 };
    Vector2 velocidadPelota = { 5.0f, 4.0f };
    float radioPelota = 20.0f;

    SetTargetFPS(60); // Limitar a 60 fotogramas por segundo

    // 3. Bucle principal del juego
    while (!WindowShouldClose()) {
        // --- ACTUALIZAR LÓGICA ---
        posicionPelota.x += velocidadPelota.x;
        posicionPelota.y += velocidadPelota.y;

        // Rebotar en los bordes horizontales
        if ((posicionPelota.x >= (pantallaAncho - radioPelota)) || (posicionPelota.x <= radioPelota)) {
            velocidadPelota.x *= -1.0f;
        }
        // Rebotar en los bordes verticales
        if ((posicionPelota.y >= (pantallaAlto - radioPelota)) || (posicionPelota.y <= radioPelota)) {
            velocidadPelota.y *= -1.0f;
        }

        // --- DIBUJAR ---
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("¡Entorno configurado correctamente!", 190, 200, 20, LIGHTGRAY);
            DrawCircleV(posicionPelota, radioPelota, MAROON);
            
            DrawFPS(10, 10);
        EndDrawing();
    }

    // 4. Cerrar la ventana y liberar memoria
    CloseWindow();


    return 0;
}