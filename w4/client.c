#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char buffer[100];
    int sockfd;
    struct sockaddr_in	servaddr;
    sockfd = socket (AF_INET, SOCK_STREAM, 0);
    printf("socketnum: %d\n", sockfd);
    if(sockfd == -1){
        printf("couldn't create socket!\n");
        close(sockfd);
        exit(1);
    }
    printf("Sockket created!\n");
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons( 8888);

    if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect false!\n");
        close(sockfd);
        exit(1);
    }
    else{
        printf("connected!\n");
        while(1){
            printf("Enter msg: \n");
            scanf("%[^\n]%*c", buffer);
            if ( send(sockfd, buffer, 100, 0) < 0){
                printf("send msg false!\n");
            }
            if ( recv(sockfd, buffer, 100, 0) < 0){
                printf("receve false!\n");
            }else{
                printf("receve: %s\n", buffer);
            }
            if(strcmp(buffer, "END") == 0){
                break;
            }
        }
        close(sockfd);
    }
    exit(0);
}
