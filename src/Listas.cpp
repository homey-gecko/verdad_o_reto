#include "Datos.h"

std::string reglas_juego = 
    "1. Es importante beber con moderacion\n2. La organizacion ideal es masculino - femenino - masculino...,\ncon tu pareja alejado de tus laterales\n3. Las verdades se puedencontar a la persona\nde la izquierda solamente, o puedes decirlo\nen voz alta si prefieres\n4. Las verdades pueden responderse con 'si'\no 'no', o se puede narrar el contexto completo y\ndar la respuesta larga\n5. Los mejores besos tienen una duracion\nmayor a un 'piquito', pero como se sientan\ncomodos esta bien\n6.Las prendas pequeñas (ej. zarcillos,\npulseras...), cuentan todos como uno solo\n\nY mas importante ¡Pasemos un rato divertido!";


std::vector<Pregunta> lista_preguntas = {
    {"¿estarias con alguien de aqui aparte\nde tu pareja?"},

    {"¿alguna vez te ha gustado alguien de\ntu mismo sexo?"},

    {"¿alguna vez te ha gustado un/a profesor/a?"},

    {"¿con quienes de aqui harias un trio?"},

    {"¿cual es un secreto que tu pareja\naun no sabe?"},

    {"¿a que edad fue tu primera vez?"},

    {"¿alguna vez has grabado un casero?"},

    {"¿cual es el lugar mas loco donde has\ntenido sexo?"},

    {"¿si pudieras cambiar algo en tu pareja\nque cambiarias?"},

    {"¿que habito de tu pareja te parece\nraro?"},

    {"¿cual es un secreto que tus padres\nno saben de ti?"},

    {"¿alguna vez te han visto por accidente\nen una situacion MUY incomoda?"}
};

std::vector<Reto> lista_retos = {
    //retos globales
    {"¡Todos beben un shot!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Todos beben agua!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Reorganicense!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Tomense una foto grupal!", INDIVIDUAL, CUALQUIERA, false},

    //retos individual
    {"aprendete 20 segundos (o menos) de una\ncoreografia y ejecutala lo mejor que puedas.\nSi fallas, bebes un shot", INDIVIDUAL, CUALQUIERA, false},

    {"hasta tu siguiente turno, tienes que\nterminar cada frase con 'mmm, q rico'. Si lo\nolvidas, toma un shot", INDIVIDUAL, CUALQUIERA, false},

    {"no puedes negarte a ninguna peticion\nhasta tu siguiente turno", INDIVIDUAL, CUALQUIERA, false},

    {"vendate los ojos y juega 'tocar, besar\nmorder'", INDIVIDUAL, CUALQUIERA, false},


    //retos de dos personas
    {"tienes que besarte con %s. Si alguno\nse niega, esa persona bebe un shot", DUO, CUALQUIERA, false},

    {"quitate una prenda y no te la puedes poner\nde vuelta. Si solo te queda una prenda,\nquitale una prenda a %s y no se la puede volver a poner.\nSi a esa persona solo le queda una prenda,\nbebes un shot", DUO, OPUESTO, false},

    {"bebe un shot desde el abdomen de %s hasta\nsu pecho, siendo este shot escurrido\npor otra persona", DUO, OPUESTO, false},

    {"imita tu posicion sexual favorita con %s", DUO, OPUESTO, false},

    {"cambia una prenda con %s, ambos deben traer\npuesta el mismo tipo de prenda. Si\nalguno ya esta en ropa interior, se salta el reto", DUO, CUALQUIERA, false},

    {"muestrale un nude de tu galeria a %s. Puede\nser explicito o no explicito. Si no\ntienes, tomate una foto en el baño y se la muestras", DUO, CUALQUIERA, false},

    {"dibuja con marcador, una cara sonriente en\nel gluteo de %s", DUO, OPUESTO, false},



    {"eres masajista profesional, y tienes que\nhacerle un masaje durante %d minutos a %s.\n(los masajes no se reciben con toda la ropa puesta, ¿cierto?)", DUO, OPUESTO, true},

    {"tienes %d minutos en el cielo con %s, disfrutenlos.\nY recuerden, lo que pasa en el cielo se queda en el cielo", DUO, OPUESTO, true},

    {"sientate durante %d minutos en las piernas de\n%s en silencio. Si hablas, bebes un shot", DUO, OPUESTO, true},


    //retos de tres personas
    {"tienes que besarte con %s y %s (beso de tres).\nSi alguno se niega, esa persona bebe un shot", TRIO, OPUESTO, false},
};