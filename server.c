#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>

char SELECT;
char ReMesge[2];
int PID;

void Communication();
void DoWhat(char[], int);

int main(){
   
//    Communication();

    
    DoWhat("abc", 8);
    return 0;

}

void DoWhat(char ReMesge[], int clientfd){

    printf("%s\n", ReMesge);

    char slt;

    char SdMesge[64][64];

    sprintf(SdMesge[0], "%d", getpid());
    printf("%s\n", SdMesge[0]);
/*
    if(ReMesge[0] == 'a'){
        SdMesge[0] = (int)getpid();
        send(clientfd, SdMesge[0], sizeof(SdMesge[0]), 0);
    }
    else
        switch(slt){
            case 'b': break;
            case 'c': break;
            case 'd': break;
            case 'e': break;
            case 'f': break;
            case 'g': break;
            case 'h': break;
            case 'i': break;
            case 'j': break;
        }
*/
//    send(clientfd, SdMesge, sizeof(SdMesge), 0);

    
}

void Communication(){

    int sockfd;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in dest;

	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(8889);
	dest.sin_addr.s_addr = INADDR_ANY;

	bind(sockfd, (struct sockaddr*)&dest, sizeof(dest));

	listen(sockfd, 20);

	while(1){
		int clientfd;
		struct sockaddr_in client_addr;
		int addrlen = sizeof(client_addr);
		
		clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);

        recv(clientfd, ReMesge, sizeof(ReMesge), 0);        
        DoWhat(ReMesge, clientfd);

        close(clientfd);

	}

	close(sockfd);
   
}
