#include <stdio.h>
#include <unistd.h>
#include "pintor.h"
#include "matriz.h"


void inicializar(void);
void pintarVirtual(void);
void pintarReal(void);

//Entrada al proceso de pintado
void * procesoDePintado(void * argument)
{
	printf("Iniciando proceso de pintado \n");
	//inicializa
    #ifdef BOARD_PRESENT
		printf("Pintando en palestra real...\n");
	#else
		printf("Pintando en palestra virtual...\n");
	#endif
	
	while(1){
		#ifdef BOARD_PRESENT
		pintarReal();
		#else
		pintarVirtual();
		usleep(1000000);
		#endif
	  
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
	//int f,c;
	
	
	//por cada columna	
	//for(c=0;c<NN;c++){
		
		//Pongo a 0 todas las filas
		//for(f=0; f<NN; f++)
			//setPin(pinData[pinF[f]], LOW);	
		
		//Pongo a 1 esta columna
		//setPin(pinData[pinC[c]], HIGH);

		//Pongo a 1 las filas que correspondan
		//for(f=0; f<NN; f++){
			//if(m[f][c] == MODE_ON) 
				//setPin(pinData[pinF[f]], HIGH);
		//}
		
		//usleep(500);		
		

		//Pongo a 0 esta columna
		//setPin(pinData[pinC[c]], LOW);
	
		
}

