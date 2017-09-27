#include <stdio.h>

int main() {
    char str[50];
    scanf("%[^\n]%*c", str);
    printf("%s\n", str);
}
