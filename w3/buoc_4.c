#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, int **argv) {
  struct in_addr addr;
  char str[30];
  printf("Nhap vao ip ascii : \n");
  scanf("%s%*c", str);
  if ( !inet_aton(str, &addr) ){
    printf("convert false!");
    return 0;
  }
  printf("Dia chi binary( dung inet_aton()) : %d\n", addr.s_addr);
  printf("Chuyen nguoc lai ip ascii : %s\n", inet_ntoa(addr));
  struct in_addr tmp;
  tmp.s_addr = inet_addr(str);
  printf("Dia chi binary( dung inet_addr()) : %d\n", tmp.s_addr);
  printf("Chuyen nguoc lai ip ascii: %s\n", inet_ntoa(tmp));
  return 0;
}
