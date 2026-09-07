#include <stdio.h>
#include "utils.c"

int main(int argc, char *argv[]) {
    printf("%d \n", argc);
    
    printf("args: %s\n", *(argv+1));
    //printf("El valor de 3 despues de 2 shifts es: %d\n", lsh(3, 2));

    return 0;
}
