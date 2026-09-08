#include <stdio.h>
#include "utils.c"
#include <string.h>
#define N_MEM 16384
#define N_SEG 8
#define N_REG 32
#define N_OP 32


typedef struct {
    char *name;
    int value;
}reg;

typedef struct {
    char *name;
    short int code;
    //puntero a func;
}operatorASM;

int main(int argc, char *argv[]) {
    printf("%d \n", argc);
    printf("args: %s\n", *(argv+1));

    reg registers[N_REG];
    int segments[N_SEG];
    char memory[N_MEM];
    operatorASM operations[N_OP];
    
    

    return 0;
}
