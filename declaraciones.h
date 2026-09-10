//bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string.h>

//constantes

#define TAM_MEMORIA 16384
#define CANT_REG 32
#define SEGMENTOS 8

//registros

typedef struct {
uint16_t base,size;
}t_segmentos;


typedef struct {
uint8_t memoria[TAM_MEMORIA];
int32_t registros[CANT_REG];
t_segmentos tabla_segmentos[SEGMENTOS];

}tipo_maquina_v;

//prototipado
void crear_tabla_segmentos(t_segmentos tbs[], uint8_t tam[]);
void seguir(tipo_maquina_v *m);
