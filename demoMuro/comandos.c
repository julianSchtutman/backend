#include <stdio.h>
#include "comandos.h"
#include "matriz.h"


void ejecutarApagarTodo(void);
void ejecutarPrenderTodo(void);
void ejecutarToggleToma(int linea, int columna);
void ejecutarPrenderToma(int linea, int columna);
void ejecutarApagarToma(int linea, int columna);


void comandos_ejecutarComando(tComando comando){
	
	switch(comando.tipo){
		
			case APAGAR_TODO:
				ejecutarApagarTodo();
				break;
		
			case PRENDER_TODO: 
				ejecutarPrenderTodo();
				break;
			
			case TOGGLE_TOMA:
				ejecutarToggleToma(comando.p1, comando.p2);
				break;
			
			case PRENDER_TOMA:
				ejecutarPrenderToma(comando.p1, comando.p2);
				break;
			
			case APAGAR_TOMA:
				ejecutarApagarToma(comando.p1, comando.p2);
				break;
		
			default:
				printf("ERROR: Comando inexistente \n");
		
	}
	
	
	return;
}



void ejecutarApagarTodo(){
	printf("Ejecutando comando: Apagar todo \n");
	matriz_setAllTomas(MODE_OFF);
}
void ejecutarPrenderTodo(){
	printf("Ejecutando comando: Prender todo \n");
	matriz_setAllTomas(MODE_ON);
}

void ejecutarToggleToma(int fila, int columna){
	tToma toma;
	printf("Ejecutando comando: Toggle toma \n");
	toma.fila = fila;
	toma.columna = columna;
	matriz_toggleToma(toma);
}
	
void ejecutarPrenderToma(int fila, int columna){
	tToma toma;
	printf("Ejecutando comando: Prender toma \n");
	toma.fila = fila;
	toma.columna = columna;
	matriz_setToma(toma, MODE_ON);
	
}
	
void ejecutarApagarToma(int fila, int columna){
	tToma toma;
	printf("Ejecutando comando: Apagar toma \n");
	toma.fila = fila;
	toma.columna = columna;
	matriz_setToma(toma, MODE_OFF);
	
}
