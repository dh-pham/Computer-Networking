#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>

int main(){
    int listenfd, connfd, pid;
    char buffer[100];
    struct sockaddr_in	cliaddr, servaddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( listenfd == -1){
        printf("couldn't create socket!\n");
    }
    printf("socket created!\n");
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons( 8888);
    bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    if( listen(listenfd, 5) == 0){
        printf("listening...\n");
    }else {
        printf("Error listend!\n");
    }

    for( ; ; ) {
        int addr_size = sizeof(struct sockaddr_in);
        connfd = accept(listenfd, (struct sockaddr*)&servaddr, &addr_size);
        if ((pid = fork()) == 0){
            while(1){
                if ( recv(connfd, buffer, 100, 0) < 0){
                    printf("receve false!\n");
                }

                int i;
                for( i = 0; buffer[i]!='\0'; i++){
                    if(islower(buffer[i]) > 0){
                        buffer[i] = toupper(buffer[i]);
                    }
                }
                buffer[i] = '\0';
                printf("recv buffer length: %d\n", (int)strlen(buffer));
                if( send(connfd, buffer, 100, 0) < 0){
                    printf("send false!\n");
                }
                if( strcmp( buffer, "END") == 0){
                    close(connfd);
                    exit(0);
                }
            }
        }
        close(connfd);
        exit(0);
    }
}
