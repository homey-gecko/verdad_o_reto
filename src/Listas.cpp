#include "Datos.h"
#include "raylib.h"

std::string reglas_juego = "1. Beber con moderacion\n\n2. La organizacion es m - f - m,\ncon tu pareja lejos de tus lados\n\n3. Las verdades se pueden contar\nsolo a la persona de la izquierda,\no decirse en voz alta \n\n4. Las verdades pueden\nresponderse corto ('si' o 'no'),\no ser narradas completas\n\n5. Los besos deben ser mas que\nsolo un 'piquitico'\n\n6.Las prendas pequeñas (pulseras,\nzarcillos...), cuentan todos como\nuno solo\n\n\nY mas importante ¡a divertirse!";

std::vector<Pregunta> lista_preguntas = {
    {"¿estarias con alguien de\naqui aparte de tu pareja?"},

    {"¿alguna vez te ha gustado\nalguien de tu mismo sexo?"},

    {"¿alguna vez te ha gustado\nun/a profesor/a?"},

    {"¿con quienes de aqui\nharias un trio?"},

    {"¿cual es un secreto que tu\npareja aun no sabe?"},

    {"¿a que edad fue tu primera\nvez?"},

    {"¿alguna vez has grabado un\ncasero?"},

    {"¿cual es el lugar mas loco\ndonde has tenido sexo?"},

    {"¿si pudieras cambiar algo\nen tu pareja que cambiarias?"},

    {"¿que habito de tu pareja te\nparece raro?"},

    {"¿cual es un secreto que tus\npadres no saben de ti?"},

    {"¿alguna vez te han visto por\naccidente en una situacion\nMUY incomoda?"}
};

std::vector<Reto> lista_retos = {
    //retos globales
    {"¡Todos beben un shot!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Todos beben agua!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Reorganicense!", INDIVIDUAL, CUALQUIERA, false},

    {"¡Tomense una foto grupal!", INDIVIDUAL, CUALQUIERA, false},

    //retos individual
    {"aprendete 20 segundos\n(o menos) de una coreografia\ny ejecutala lo mejor que\npuedas. Si fallas, bebes un shot", INDIVIDUAL, CUALQUIERA, false},

    {"hasta tu siguiente turno,\ntienes que terminar cada frase\ncon 'mmm, q rico'. Si lo\nolvidas, toma un shot", INDIVIDUAL, CUALQUIERA, false},

    {"no puedes negarte a ninguna\npeticion hasta tu siguiente\nturno", INDIVIDUAL, CUALQUIERA, false},

    {"vendate los ojos y juega\n'tocar, besar o morder'", INDIVIDUAL, CUALQUIERA, false},


    //retos de dos personas
    {"tienes que besarte con\n%s. Si alguno se niega,\nesa persona bebe un shot", DUO, CUALQUIERA, false},

    {"quitate una prenda y no te la\npuedes poner de vuelta. Si\nsolo te queda una prenda,\nquitale una prenda a\n%s y no se la puede\nvolver a poner. Si a esa\npersona solo le queda una\nprenda, bebes un shot", DUO, OPUESTO, false},

    {"bebe un shot desde el\nabdomen de %s hasta su\npecho,siendo este shot\nescurrido por otro", DUO, OPUESTO, false},

    {"imita tu posicion sexual\nfavorita con %s", DUO, OPUESTO, false},

    {"cambia una prenda con\n%s. Ambos deben traer\npuesta el mismo tipo de\nprenda. Si alguno ya esta en\nropa interior, se salta\nel reto", DUO, CUALQUIERA, false},

    {"muestrale un nude de tu\ngaleria a %s. Puede ser\nexplicito o no explicito,\npero no puedes mostrar la\nmisma imagen dos veces. Si no\ntienes, tomate una foto en el\nbaño y se la muestras", DUO, CUALQUIERA, false},

    {"dibuja con marcador, una\ncara sonriente en el\ngluteo de %s", DUO, OPUESTO, false},



    {"eres masajista profesional,\ny tienes masajear\ndurante %d minutos a %s.\n(los masajes no se reciben\ncon toda la ropa puesta,\n¿cierto?)", DUO, OPUESTO, true},

    {"tienes %d minutos en el cielo\ncon %s. disfrutenlos.\nY recuerden, lo que pasa en\nel cielo se queda en el cielo", DUO, OPUESTO, true},

    {"sientate durante %d minutos\nen las piernas de %s\nen silencio. Si hablas,\nbebes un shot", DUO, OPUESTO, true},


    //retos de tres personas
    {"tienes que besarte con\n%s y %s\n(beso de tres). Si alguno se\nniega, esa persona bebe un\nshot", TRIO, OPUESTO, false},
};

void texto_centrado(Font fuente, const std::string &texto, Rectangle contenedor, float pos_y, float tam_fuente, float espaciado, Color color){
    Vector2 tamaño_texto = MeasureTextEx(fuente, texto.c_str(), tam_fuente, espaciado);

    float pos_x_centrada = contenedor.x + (contenedor.width - tamaño_texto.x) / 2.0f;

    DrawTextEx(fuente, texto.c_str(), Vector2{pos_x_centrada, pos_y}, tam_fuente, espaciado, color);
}