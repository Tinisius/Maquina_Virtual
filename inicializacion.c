#include "declaraciones.h"

void crear_tabla_segmentos(t_segmentos tbs[], uint8_t tam[]){
    uint16_t tamano = (tam[0] << 8) | tam[1];
    tbs[0].base=0;
    tbs[0].size=tamano;
    tbs[1].base=tamano;
    tbs[1].size=TAM_MEMORIA-tamano;
    for(int i=2;i<8;i++){
        tbs[i].base=0xFFFF;
        tbs[i].size=0xFFFF;
    }

}
void inicializar_reg(tipo_maquina_v *m){
    m->registros[0]=0;
    m->registros[26]=0;
    m->registros[27]=(1 << 16) | 0;

}

