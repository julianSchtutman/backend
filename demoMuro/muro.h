#ifndef __muro_h__
#define __muro_h__

//puerto al que se conecta el cliente
#define PUERTO 5002
//#define BOARD_PRESENT

//definicion del comando que manda el cliente
typedef struct{
	int tipo;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	} tComando;
#endif

