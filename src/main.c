// Editor de Texto CLI - Wh0xer.tess3ract.dat



#include "../include/arguments.h"
#include "../include/filecreation.h"



int main(int argc, char **argv) {
  setlocale(LC_ALL, "portuguese");
  boot_program();
  get_arg(TRUE);
  
  return 0;
}


// trabalhar nisso depois

int systemf( const char * fmt, ... ) {
    va_list args;
    char cmd[ CMD_TAM_MAX + 1 ];

    va_start( args, fmt );
    vsnprintf( cmd, CMD_TAM_MAX + 1, fmt, args );
    va_end(args);

    return system(cmd);
}























/*
void aloca(char **ptr, int tamanho) {
    *ptr = (char *)realloc(*ptr, tamanho + 1);
    if(ptr == NULL){
        puts("** Memória Insuficiente **");
        exit(0);
    }
}

char *preenche() {
    char *dados = NULL;
    int i = 0;
    do {
        aloca(&dados, i);
        dados[i++] = getchar();
    } while (dados[i - 1] != '\n');
    dados[i - 1] = '\0';
    return dados;
}
*/
