#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>

#include "pintor.h"
#include "matriz.h"


void inicializar(void);
void pintarVirtual(void);
void pintarReal(void);

//globales
int filas[] = {FIL0,FIL1,FIL2,FIL3,FIL4,FIL5,FIL6,FIL7};
int columnas[] = {COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7};

//Entrada al proceso de pintado
void * pintor_procesoDePintado(void * argument)
{
	int i;
	printf("Iniciando proceso de pintado \n");
	//inicializa
		
			printf("Pintando en palestra real...\n");
		wiringPiSetup();
		for(i=0;i<NN;i++){
			pinMode(filas[i], OUTPUT);
			pinMode(columnas[i], OUTPUT) ;
		}
		
	

	
	while(1){
		
		pintarReal();
	  
	}
  
	return NULL;
}


//Esta funcion hace las inicializaciones correspondientes del GPIO y luego hace una secuencia 
// de encendido y apagado de los leds de modo de verificar que todos funcionen correctamente. 
void inicializar(){
	
	
	return;
}

void pintarVirtual(){
	int i,j;
		
	for(i=0;i<NN;i++){
		for(j=0;j<NN;j++){
			printf("%d ", m[i][j]);			
		}
	printf("\n");
	
	}
	printf("\n");
}



void pintarReal(){
	int f,c;
	
	
	//por cada columna	
	for(c=0;c<NN;c++){
		
		//Pongo a 0 todas las filas
		for(f=0; f<NN; f++)
			digitalWrite(filas[f], LOW);	
		
		//Pongo a 1 esta columna
		digitalWrite(columnas[c], HIGH);

		//Pongo a 1 las filas que correspondan
		for(f=0; f<NN; f++){
			if(m[f][c] == MODE_ON) 
				digitalWrite(filas[f], HIGH);
		}
		
		usleep(500);		
		

		//Pongo a 0 esta columna
		digitalWrite(columnas[c], LOW);
	
		
	}
}


