#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, int **argv) {
  struct in_addr addr;
  char str[30];
  printf("Nhap vao ip ascii : \n");
  scanf("%s%*c", str);

  if ( !inet_pton( AF_INET, str, &addr)){
    printf("inet_pton false!");
    return 0;
  }
  printf("Dia chi binary( dung inet_pton()) : %d\n", addr.s_addr);
  char str2[30];
  if ( !inet_ntop( AF_INET, &addr, str2, sizeof(str2))){
    printf("inet_ntop false!");
    return 0;
  }
  printf("Chuyen nguoc lai ip ascii ( dung inet_ntop()): %s\n", str2);
  return 0;
}
