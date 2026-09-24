#include "Datos.h"
#include "raylib.h"

std::string reglas_pagina1 = "- Beber con moderacion\n\n- La organizacion es m - f - m,\ncon tu pareja lejos de tus lados\n\n- Si eliges verdad, debes elegir\nreto luego para poder optar a\nverdad nuevamente\n\n- Las verdades se pueden contar\nsolo a la persona de la izquierda,\no decirse en voz alta\n\n- Las verdades pueden ser 'si' o\n'no', o ser narradas completas\n\n- El jugador actual es a quien se\nle impuso el reto\n\n- Los jugadores acompañantes son\na quienes el reto involucra con el\njugador actual";

std::string reglas_pagina2 = "- Los turnos inician cuando se lee\nel reto del actual, y terminan\ncuando se lee el reto del\nsiguiente jugador\n\n- Un reto termina cuando se\ncompleta o se acaba el tiempo\n\n- El fin de un turno, no es igual\nque el fin de un reto\n\n- Si un jugador decide no hacer\nun reto o falla en completarlo,\nbebe un shot\n\n- Se recomienda mantener entre\nlos jugadores involucrados, lo que\npaso en el reto\n\n- Las prendas que te quitas no te\nlas puedes volver a poner hasta\nque te vayas a dormir";

std::string reglas_pagina3 = "- El minimo de prendas con la que\npuedes quedar es 1 ropa interior\n\n- Las prendas pequeñas (pulseras,\nzarcillos...), cuentan todos como\nuno solo\n\n- Si hay jugadores fuera de la\nhabitacion cumpliendo un reto y\nson seleccionados como\nacompañantes, se saltan y se \nselecciona a alguien de la\nhabitacion que lo sustituya\n\n- Si un acompañante esta en otra\nhabitacion, y viene su turno, se\nsalta su turno hasta que regrese\ny se le dice el reto que tenia\npendiente\n\n\nY mas importante ¡a divertirse!";

std::vector<Pregunta> lista_preguntas = {
    {"¿estarias con alguien de\naqui aparte de tu pareja?"},

    {"¿alguna vez te ha gustado\nalguien de tu mismo sexo?"},

    {"¿alguna vez te ha gustado\nun/a jefe/a o profesor/a?"},

    {"¿con quienes de aqui\nharias un trio?"},

    {"¿cual es un secreto que tu\npareja no sabe?"},

    {"¿a que edad fue tu primera\nvez?"},

    {"¿cuanto es tu tiempo ideal\npara el sexo?"},

    {"¿alguna vez has grabado un\ncasero?"},

    {"¿cual es el lugar mas loco\ndonde has tenido sexo?"},

    {"¿que habito de tu pareja te\nparece raro?"},

    {"¿alguna vez te han visto por\naccidente en una situacion\nMUY incomoda?"}
};

std::vector<Reto> lista_retos = {
    //retos de dos personas con tiempo
    {"Masajea de cuerpo completo\ndurante %d minutos a %s.\n(Los masajes se reciben en ropa\ninterior)", DUO, OPUESTO, NINGUNO, true},

    {"Tienes %d minutos en el cielo\ncon %s. Lo que pase alla\nse queda alla", DUO, OPUESTO, NINGUNO, true},

    {"Sientate durante %d minutos\nen el regazo de %s\nen silencio", DUO, OPUESTO, NINGUNO, true},

    {"Besate con%s, durante %d\nsegundos", DUO, CUALQUIERA, NINGUNO, true},

    //retos globales
    {"¡Todos se quitan una prenda!", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"¡Todos beben un shot!", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"¡Todos beben agua!", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"¡Foto grupal!", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    //retos individual
    {"Aprende 20 segundos, o menos\nde una coreografia y ejecutala\nlo mejor que puedas.", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"Hasta tu siguiente turno,\ntienes que terminar cada frase\ncon: 'mmm, q rico'", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"No puedes negarte a ninguna\npeticion hasta tu siguiente\nturno", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"Vendate los ojos y juega\n'¿quien me ha tocado?'.\nTienes 3 intentos", INDIVIDUAL, CUALQUIERA, NINGUNO, false},

    {"Ve al baño y desnudate.\nLuego paseate corriendo por la\nsala y vuelve al baño a\nvestirte. Solo puedes taparte\ncon tus manos (si quieres)", INDIVIDUAL, CUALQUIERA, HOMBRE, false},

    //retos de dos personas
    {"Vendate los ojos y todos te\nbesaran durante 5 segundos c/u.\nTienes que adivinar quien de\nlos que te beso es %s.\nTienes 1 intento", DUO, CUALQUIERA, NINGUNO, false},

    {"Vendate los ojos y toca los\npechos de todas. Al finalizar,\ntienes que adivinar quien de\nlas que tocaste es %s.\nTienes 1 intento", DUO, OPUESTO, HOMBRE, false},

    {"Vendate los ojos y toca la\nentrepierna de todos. Al\nfinalizar, tienes que adivinar\nquien de los que tocaste es\n%s. Tienes 1 intento", DUO, OPUESTO, MUJER, false},

    {"Quitate una prenda. Si solo\nte queda una prenda, quitale\nuna prenda a %s. Si\nsolo le queda una prenda, tu\nbebe un shot", DUO, OPUESTO, NINGUNO, false},

    {"Bebe un shot del abdomen de\n%s hasta su pecho,\nsiendo este shot escurrido\npor alguien mas", DUO, OPUESTO, NINGUNO, false},

    {"Imita tu posicion sexual\nfavorita con %s", DUO, OPUESTO, NINGUNO, false},

    {"Cambia una prenda con\n%s. Ambos deben traer\npuesta el mismo tipo de prenda.\nSi alguno ya esta en ropa\ninterior, se salta el reto", DUO, CUALQUIERA, NINGUNO, false},

    {"Haz que %s califique\nun nude de tu galeria.\nExplicito o no explicito, no\npuedes mostrar la misma imagen\ndos veces. Si no tienes,\ntomate una foto en el baño\ny se la muestras", DUO, CUALQUIERA, NINGUNO, false},

    {"Nalguea sabroso a %s.\nSi no le gusta, bebe un shot", DUO, FEMENINO, NINGUNO, false},

    {"Pasale un hielo de boca a\nboca, a %s", DUO, CUALQUIERA, NINGUNO, false},

    //retos de tres personas
    {"Besate con %s y %s\n(beso de tres).", TRIO, OPUESTO, NINGUNO, false},

    {"Imita la 'torre eiffel' con\n%s y %s", TRIO, MASCULINO, MUJER, false}
};

void texto_centrado(Font fuente, const std::string &texto, Rectangle contenedor, float pos_y, float tam_fuente, float espaciado, Color color){
    Vector2 tamaño_texto = MeasureTextEx(fuente, texto.c_str(), tam_fuente, espaciado);

    float pos_x_centrada = contenedor.x + (contenedor.width - tamaño_texto.x) / 2.0f;

    DrawTextEx(fuente, texto.c_str(), Vector2{pos_x_centrada, pos_y}, tam_fuente, espaciado, color);
}