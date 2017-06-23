#ifndef __comandos_h__
#define __comandos_h__

#include "muro.h"

//Defino los comandos que se le pueden dar a la palestra
#define APAGAR_TODO		1 //sin parametros
#define PRENDER_TODO	2 //sin parametros
#define TOGGLE_TOMA		3 //fila, columna
#define PRENDER_TOMA	4 //fila, columna
#define APAGAR_TOMA		5 //fila, columna


//defino la funcion que va a atajar el pedido del cliente. Por ahora es una funcion, en el futuro
// para un juego que sea mas largo tipo el de entrenamiento, se podría definir un proceso de forma que el cliente quede esperando
// comandos del tipo subir dificultad.

void comandos_ejecutarComando(tComando);

#endif

