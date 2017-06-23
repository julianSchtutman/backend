#include <stdio.h>
#include <assert.h>
#include "matriz.h"





//Setea un led en particular en el valor que le pasen
void matriz_setToma(tToma toma, int mode){
	m[toma.fila][toma.columna] = mode;
}

//Cambia el estado del led que le pasen
void matriz_toggleToma(tToma toma){
	if(m[toma.fila][toma.columna] == MODE_ON)
		m[toma.fila][toma.columna] = MODE_OFF;
	else
		m[toma.fila][toma.columna] = MODE_ON;
}

//Setea toda la matriz en el valor que le pasen
void matriz_setAllTomas(int mode){
	int i,j;
	for(i=0;i<NN;i++){
		for(j=0;j<NN;j++)
			m[i][j] = mode;
	}
}

