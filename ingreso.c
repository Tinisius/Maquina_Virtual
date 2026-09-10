#include "declaraciones.h"

int main(int argc, char const *argv[])
{
    tipo_maquina_v maquina;
    if (argc < 2){
        printf(" error cantidad de argumentos invalida");
        return -1;
    }
    
    char *extension = strrchr(argv[1], '.');
    if (extension == NULL || strcmp(extension, ".vmx") != 0) {
        printf("error el archivo debe tener extension .vmx\n");
        return -1;
    }

    FILE *arch;
    arch=fopen(argv[1],"rb");
    char firma[6]={0};
    fread(firma,sizeof(char),5,arch);
    if(strcmp(firma,"VMX26")!=0){
        printf("error el archivo no es VMX26");
        return -1;
    }

    uint8_t byte;
    fread(&byte,sizeof(unsigned char),1,arch);
    //validar version...

    uint8_t tam[2];
    fread(tam,sizeof(uint8_t),2,arch);
    memset(&maquina, 0, sizeof(tipo_maquina_v)); //setea todos los bytes de memorias en 0
    crear_tabla_segmentos(maquina.tabla_segmentos,tam);
    fread(maquina.memoria, sizeof(uint8_t), maquina.tabla_segmentos[0].size, arch); //se supone q carga todo lo restante archivo en la memoria 
    inicializar_reg(&maquina);
    seguir(&maquina);
    






















    return 0;
}
