#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <assert.h>


typedef struct{
	int tipo;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	} tComando;

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    tComando comando;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port \n", argv[0]);
       fprintf(stderr,"Comandos: APAGAR_TODO=1 PRENDER_TODO=2 TOGGLE_TOMA=3 PRENDER_TOMA=4 APAGAR_TOMA=5 \n");
       exit(0);
    }



    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        assert("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        assert("ERROR connecting");
    
while(1){
printf("\nComandos: APAGAR_TODO=1 PRENDER_TODO=2 TOGGLE_TOMA=3 PRENDER_TOMA=4 APAGAR_TOMA=5 \n");
printf("Tipo: ");
   scanf("%d", &comando.tipo);
printf("p1: ");
   scanf("%d", &comando.p1);
printf("p2: ");
   scanf("%d", &comando.p2);
printf("p3: ");
   scanf("%d", &comando.p3);
printf("p4: ");
   scanf("%d", &comando.p4);
printf("p5: ");
   scanf("%d", &comando.p5);
  
    n = write(sockfd,&comando,sizeof(tComando));
    if (n < 0) 
         assert("ERROR writing to socket");

}

    close(sockfd);
    return 0;
}
