#include "Jugador.h"

#include <iostream>

void agregar_jugador(){
    std::string nom;
    std::string sex;

    std::cout<<"Nombre: ";
    getline(std::cin, nom);

    std::cout<<"\n\nSexo: ";
    getline(std::cin, sex);

    lista_jugadores.push_back(Jugador{nom, sex});
}