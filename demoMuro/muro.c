#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <errno.h>

#include "muro.h"
#include "pintor.h"
#include "comandos.h" 
 
//printf("recv error: %s\n", strerror(errno));

int main( int argc, char** argv ){
	
	//Variables para el thread
	pthread_t threadPintado;
	int threadResult;
	int threadArgumento = 0; //por el momento no se usa
 
	//variables para el socket
	int sockfd, newsockfd, readSize;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	tComando comando;


 
    //Disparo el thread que se encarga de pintar la matriz constantemente
	threadResult = pthread_create( &threadPintado, NULL, pintor_procesoDePintado, &threadArgumento );
	assert( !threadResult );
	
printf("Hola\n");
 
 	//Inicializo el socket que espera la conexión del cliente
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		assert("ERROR opening socket");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PUERTO);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		assert("ERROR on binding");
    listen(sockfd,1); //por el momento se acepta una sola conexión
     	clilen = sizeof(cli_addr);
	
	printf("Esperando conexiones en puerto %d ....\n", PUERTO);
		    	

	//Me quedo esperando una conexión de un cliente
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) 
		assert("ERROR on accept");
     
    printf("Cliente conectado!\n");


 
	//A partir de ahora entra en un cliclo en el cual espera comandos del cliente. 
	//La comunicación es siempre del cliente hacia el muro, por ahora no hay vuelta
	
	
	
	while(1){
		
		
		
		readSize = recv(newsockfd, &comando , sizeof(tComando) , 0);

		if(readSize <= 0){
				printf("Cliente desconectado....");
				return 0;
		}
		
		//Manda a ejecutar el comando
		comandos_ejecutarComando(comando);
   
	}


    //Espero a que termine el thread de pintado, igual por ahora no va a llegar nunca aca porque el thread esta dentro de un while(1)
    threadResult = pthread_join(threadPintado, NULL );
    assert(threadResult);
    printf("Finalizando programa \n");
   
 

   return(0);
}
