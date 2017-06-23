#ifndef __matriz_h__
#define __matriz_h__



//definiciones
#define MODE_ON 1
#define MODE_OFF 0
#define NN 8 

//Variables globales
int m[NN][NN];

//Estructuras
typedef struct{
	int fila;
	int columna;
	int dificultad; //por ahora vacio pero podria ir de uno a diez
	
} tToma;


//Funciones
void matriz_setToma(tToma, int);
void matriz_toggleToma(tToma);
void matriz_setAllTomas(int);


#endif

