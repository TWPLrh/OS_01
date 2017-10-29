#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>

void UserInterface();
void Communication();

char PID = '0', SELECT = '0';

int main(){

    while(SELECT != 'k'){
    UserInterface();
    Communication();
    }

    return 0;
}

void UserInterface(){

        printf("===========================================================================\n"
               "(a)list all process ids\n"
               "(b)thread's IDs\n"
               "(c)child's PIDs\n"
               "(d)process name\n"
               "(e)state of process(D,R,S,T,t,W,X,Z)\n"
               "(f)command line of excuting process(cmdline)\n"
               "(g)parent's PID\n"
               "(h)all ancients of PIDs\n"
               "(i)virtual memory size(VmSize)\n"
               "(j)physical memory size(VmRSS)\n"
               "(k)exit\n"
               "===========================================================================\n"
               );
        
        printf("which? ");
        scanf(" %c", &SELECT);
        
        if(SELECT == 'k')
            return;

        if(SELECT != 'a'){
            printf("pid? ");
            scanf(" %c", &PID);
        }
        
        printf("\n\n");

        
}

void Communication(){

    int sockfd;
    char SdMesge[2];
    char ReMesge[64] = {0};

    SdMesge[0] = SELECT;
    SdMesge[1] = PID;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in dest;
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8889);
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));
    
	send(sockfd, SdMesge, sizeof(SdMesge), 0);
    
    recv(sockfd, ReMesge, sizeof(ReMesge), 0);
    printf("%s\n", ReMesge);
    

    close(sockfd);

}

