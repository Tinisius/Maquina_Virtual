#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> //libreria para estandarizar el tamaño en bytes de los tipos
#include "utils.c"

#define N_HEADER 8
#define ID "VMX26"
#define VERSION 1

#define N_MEM 16384
#define N_SEG 8
#define N_REG 32
#define N_OP 32

typedef struct
{
    char *name;
    int value;
} reg;

typedef struct
{
    char *name;
    short int code;
    void (*operation)(int, int);
} operatorASM;

void readHeader(char route[], uint16_t *code_size, int *res)
{
    uint8_t line[N_HEADER];
    FILE *arch = fopen(route, "rb");

    if (fread(line, 1, N_HEADER, arch) == N_HEADER)
    {
        // Bytes 0-4: identificador "VMX26"
        // Byte 5: version
        // Bytes 6-7: tamano codigo
        *code_size = ((uint16_t)line[6] << 8) | line[7];
        //uso memcmp porque line no es una cadena terminada en \0. comparo byte a byte contra ID
        *res = (memcmp(line, ID, 5) == 0) && (line[5] == VERSION) && ((*code_size) <= N_MEM - 1);

         // TEST: mostrar lectura
        printf("IDENTIFICADOR: \"%.5s\"\n", line);
        printf("VERSION: %d\n", line[5]);
        printf("TAMANO EN BYTES: %u\n", *code_size);
        
    }
    else
        *res = 0;
    fclose(arch);
}

int main(int argc, char *argv[])
{
    printf("%d \n", argc);
    printf("args: %s\n", *(argv + 1));
    
    uint16_t code_size;
    int res = 0;
    readHeader(*(argv + 1), &code_size, &res);

    // reg registers[N_REG];
    // int segments[N_SEG];
    // char memory[N_MEM];
    // operatorASM operations[N_OP];

    return 0;
}
