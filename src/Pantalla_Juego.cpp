#include "Pantalla.h"
#include "Datos.h"

bool repetir;
int id_actual = 0, id_proximo = 1, id_segundo, id_tercero;
Jugador actual, proximo, segundo, tercero;

std::string texto_pantalla_retos = "Presiona 'Verdad' o 'Reto'\npara iniciar";
std::string texto_jugador_actual = "";
std::string texto_jugador_siguiente = "";
std::string texto_seleccion = "";

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
            int id_pregunta;
            Pregunta p;

            id_pregunta = get_id(static_cast<int>(lista_preguntas.size()));
            p = lista_preguntas[id_pregunta];

            texto_pantalla_retos = p.descripcion;
        }

        if(CheckCollisionPointRec(mouse_pos, boton_reto)){
            texto_seleccion = "RETO";
            boton_presionado = true;
            int id_reto;
            Reto r;

            do{
                repetir = false;

                id_reto = get_id(static_cast<int>(lista_retos.size()));
                r = lista_retos[id_reto];

                if((r.s_limitante == HOMBRE && actual.sexo != 'M') || (r.s_limitante == MUJER && actual.sexo != 'F')){
                    repetir = true;
                }

            }while(repetir);

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

                        if((r.t_pareja == MASCULINO && lista_jugadores[id_segundo].sexo != 'M') || (r.t_pareja == FEMENINO && lista_jugadores[id_segundo].sexo != 'F') || (r.t_pareja == OPUESTO && lista_jugadores[id_segundo].sexo == lista_jugadores[id_actual].sexo)){
                            repetir = true;
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

                        if((r.t_pareja == MASCULINO && lista_jugadores[id_segundo].sexo != 'M') || (r.t_pareja == FEMENINO && lista_jugadores[id_segundo].sexo != 'F') || (r.t_pareja == OPUESTO && lista_jugadores[id_segundo].sexo == lista_jugadores[id_actual].sexo)){
                            repetir = true;
                        }

                    }while(repetir);

                    do{
                        repetir = false;

                        id_tercero = get_id(static_cast<int>(lista_jugadores.size()));

                        if(id_tercero == id_actual) repetir = true;
                        if(id_tercero == id_segundo) repetir = true;

                        if((r.t_pareja == MASCULINO && lista_jugadores[id_tercero].sexo != 'M') || (r.t_pareja == FEMENINO && lista_jugadores[id_tercero].sexo != 'F') || (r.t_pareja == OPUESTO && lista_jugadores[id_tercero].sexo == lista_jugadores[id_actual].sexo)){
                            repetir = true;
                        }

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