#include "declaraciones.h"

void seguir(tipo_maquina_v *m){ 

    while (m->registros[0] < m->tabla_segmentos[0].size){
        uint8_t byte=m->memoria[m->registros[0]];
        m->registros[0]+=1;  //a medida q voy comiendo bytes voy sumando al registro IP se supone q va cortar cuando sea = al CS
        uint8_t tipo_opb = (byte >> 6) & 0x03;
        uint8_t tipo_opa = (byte >> 4) & 0x03;
        uint8_t tipo_op =   byte & 0x1F;

        if(tipo_op>=0x10 && tipo_op<=0x1F){
            switch (tipo_opa)
            {
            case 0x01: //es de tipo registro
                

                m->registros[0]+=1;
                break;

            case 0x11: //es memoria
                
                m->registros[0]+=3;
                break;
            }
            switch (tipo_opb)
            {
            case 0x10: //es inmediato
                

                m->registros[0]+=2;
                break;
            case 0x11:
                
                m->registros[0]+=3; // es memoria
                break;

            case 0x01:
                m->registros[0]+=1; // es registro
                break;
                
            }
        
        
        
        
        }

        
        
    }
    


}