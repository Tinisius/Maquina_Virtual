#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct{
    unsigned short base;
    unsigned short size;
}r_descriptor;

void creartabla_segmentos(unsigned char tam[], r_descriptor tb[]);

int main(int argc, char *argv[]){
    r_descriptor tabla_segmentos[8];
    FILE *arch;
    arch=fopen(argv[1],"rb");
    char firma[6]={0};
    fread(firma,sizeof(char),5,arch);
   // printf("%s\n",firma);
    if (strcmp(firma,"VMX26")==0)
    {
       // printf("todo ok\n");
        unsigned char byte;
        
        fread(&byte,sizeof(unsigned char),1,arch);
        unsigned char tam[2];
                fread(tam,sizeof(unsigned char),2,arch);
                //printf("%02X %02X\n",tam[0],tam[1]);
        creartabla_segmentos(tam,tabla_segmentos);
        while (fread(&byte,sizeof(unsigned char),1,arch)==1)
        {
            printf("%02X ",byte);
        } 
    }
    else
        printf("no es un vmx26");

    return 0;
}
void creartabla_segmentos(unsigned char tam[], r_descriptor tb[]){
    unsigned short tamano=(tam[0]<<8)|tam[1];
    tb[0].base=0;
    tb[0].size=tamano;
    tb[1].base=tamano;
    tb[1].size=16384-tamano;
    for(int i=2;i<8;i++){
        tb[i].base=0xFFFF;
        tb[i].size=0xFFFF;
    }
    for(int i=0;i<8;i++)
        printf("%02X %02X \n",tb[i].base, tb[i].size);

}