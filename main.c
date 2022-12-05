// Editor de Texto CLI - Wh0xer.tess3ract.dat

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <locale.h>

#define TRUE 1
#define FALSE 0

#define QUIT        "q" // concluido 
#define NEW_FILE    "c" // concluido
#define CLEAR_S     "cls"
#define OPEN_FILE   "o" //em curso
//#define SAVE_FILE   "s" //em curso
#define GET_HELP    "h" //em curso
#define LIST_ARQ    "l" // concluido

#define CMD_TAM_MAX   (1024)

const int match = 0; 

void boot_program();
void alert_message(char alert[50]);
void aloca(char **ptr, int tamanho);

char *preenche();
int systemf( const char * fmt, ... ); 

typedef struct {
  FILE *fileptr;
  
  char *readmode;
  char *filename;
}newfile;


int get_arg(int getting_arg);
int create_file();

int open_file();

int main(int argc, char **argv) {
  setlocale(LC_ALL, "portuguese");
  boot_program();
  get_arg(TRUE);
  
  return 0;
}
void alert_message(char alert[50]) {
    puts(alert);
}

void boot_program() {
  system("clear");
  FILE *interf;
  char c;
 
  interf = fopen("interf.txt", "r");
  
  if (interf == NULL) {
      alert_message("erro: interface não aberta.");
  }
  
  do {
      c = fgetc(interf);
      
      printf("%c", c);
  } while(c != EOF);
  
  printf("\n");
}


int create_file() {
    newfile *file = malloc(20 * sizeof(*file));
    
  
    file->readmode = (char *) malloc(5 * sizeof(char));
    file->filename = (char *) malloc(20 * sizeof(char));
    
    printf("\n<novo arquivo>\n");
    
    printf("nome do arquivo> ");
    file->filename = preenche();

    strcpy(file->readmode, "wr");
    
    file->fileptr = fopen(file->filename, file->readmode);
    
    if (file->fileptr == NULL) {
        alert_message("erro: incapaz de criar o arquivo.");
    }
        
    systemf("mv %s -t ./files/", file->filename);
    
    boot_program();
      
    printf("\narquivo %s ", file->filename);
    alert_message("criado com sucesso.\n");
    
    fclose(file->fileptr);
    
    free(file->readmode);
    free(file);
    free(file->fileptr);
    
  
    get_arg(TRUE);   
    return 0;
}

int get_arg(int getting_arg) {
  char *arg;
  
  while (getting_arg) {
    printf("> ");
    arg = preenche();
    
    if (strcmp(NEW_FILE, arg) == match) {
        create_file();
        return 0;
    } else if (strcmp(OPEN_FILE, arg) == match) {
      //code
    } else if (strcmp(QUIT, arg) == match) {
      alert_message("> até uma próxima!\n");
      exit(1);
    } else if (strcmp(LIST_ARQ, arg) == match) {
      systemf("ls ./files/");
    } else if (strcmp(CLEAR_S, arg) == match) {
      systemf("clear");
      boot_program();
    } 
  }
 
  return 0;
}

int systemf( const char * fmt, ... ) {
    va_list args;
    char cmd[ CMD_TAM_MAX + 1 ];

    va_start( args, fmt );
    vsnprintf( cmd, CMD_TAM_MAX + 1, fmt, args );
    va_end(args);

    return system(cmd);
}

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

