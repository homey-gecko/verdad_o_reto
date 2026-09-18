#include "Listas.h"

std::string reglas = 
    "1. Es importante beber con moderacion\nLa organizacion ideal es masculino - femenino - masculino..., con tu pareja alejado de tus laterales\nLas verdades se pueden contar a la persona de la izquierda solamente, o puedes decirlo en voz alta si prefieres\nLas verdades pueden responderse con 'si' o 'no', o se puede narrar el contexto completo y dar la respuesta larga\nLos mejores besos tienen una duracion mayor a un 'piquito', pero como se sientan comodos esta bien\nLas prendas pequeñas (ej. zarcillos), cuentan en pares\nY mas importante ¡Pasemos un rato divertido!";


std::vector<Pregunta> lista_preguntas = {
    {"%s, ¿estarias con alguien de aqui aparte\nde tu pareja?"},

    {"%s, ¿alguna vez te ha gustado alguien de\ntu mismo sexo?"},

    {"%s, ¿alguna vez te ha gustado un/a profesor/a?"},

    {"%s, ¿con quienes de aqui harias un trio?"},

    {"%s, ¿cual es un secreto que tu pareja\naun no sabe?"},

    {"%s, ¿a que edad fue tu primera vez?"},

    {"%s, ¿alguna vez has grabado un casero?"},

    {"%s, ¿cual es el lugar mas loco donde has\ntenido sexo?"},

    {"%s, ¿si pudieras cambiar algo en tu pareja\nque cambiarias?"},

    {"%s, ¿que habito de tu pareja te parece\nraro?"},

    {"%s, ¿cual es un secreto que tus padres\nno saben de ti?"},

    {"%s, ¿alguna vez te han visto por accidente\nen una situacion MUY incomoda?"}
};

std::vector<Reto> lista_retos = {
    //retos individual
    {"%s, aprendete 20 segundos (o menos) de una\ncoreografia y ejecutala lo mejor que puedas.\nSi fallas, bebes un shot", INDIVIDUAL, false},

    {"%s, hasta tu siguiente turno, tienes que\nterminar cada frase con 'mmm, q rico'. Si lo\nolvidas, toma un shot", INDIVIDUAL, false},

    {"%s, no puedes negarte a ninguna peticion\nhasta tu siguiente turno", INDIVIDUAL, false},

    {"%s, vendate los ojos y juega 'tocar, besar\nmorder'", INDIVIDUAL, false},


    //retos de dos personas
    {"%s, tienes que besarte con %s. Si alguno\nse niega, esa persona bebe un shot", DUO, false},

    {"%s, quitate una prenda y no te la puedes poner\nde vuelta. Si solo te queda una prenda,\nquitale una prenda a %s y no se la puede volver a poner.\nSi a esa persona solo le queda una prenda,\nbebes un shot", DUO, false},

    {"%s, bebe un shot desde el abdomen de %s hasta\nsu pecho, siendo este shot escurrido\npor otra persona", DUO, false},

    {"%s, imita tu posicion sexual favorita con %s", DUO, false},

    {"%s, cambia una prenda con %s, ambos deben traer\npuesta el mismo tipo de prenda. Si\nalguno ya esta en ropa interior, se salta el reto", DUO, false},

    {"%s, muestrale un nude de tu galeria a %s. Puede\nser explicito o no explicito. Si no\ntienes, tomate una foto en el baño y se la muestras", DUO, false},

    {"%s, dibuja con marcador, una cara sonriente en\nel gluteo de %s", DUO, false},



    {"%s, eres masajista profesional, y tienes que\nhacerle un masaje durante %d minutos a %s.\n(los masajes no se reciben con toda la ropa puesta, ¿cierto?)", DUO, true},

    {"%s, tienes %d minutos en el cielo con %s, disfrutenlos.\nY recuerden, lo que pasa en el cielo se queda en el cielo", DUO, true},

    {"%s, sientate durante %d minutos en las piernas de\n%s en silencio. Si hablas, bebes un shot", DUO, true},


    //retos de tres personas
    {"%s, tienes que besarte con %s y %s (beso de tres).\nSi alguno se niega, esa persona bebe un shot", TRIO, false},


    //retos globales
    {"¡Todos beben un shot!", GLOBAL, false},

    {"¡Todos beben agua!", GLOBAL, false},

    {"¡Reorganicense!", GLOBAL, false},

    {"¡Tomense una foto grupal!", GLOBAL, false}
};