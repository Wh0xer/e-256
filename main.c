// Editor de Texto CLI - Wh0xer.tess3ract.dat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TRUE 1
#define FALSE 0

#define QUIT        "q"
#define NEW_FILE    "c"
#define OPEN_FILE   "o"
#define SAVE_FILE   "s"
#define GET_HELP    "h"

const int match = 0; 

void boot_program();
void alert_message(char alert[50]);

struct newfile {
  FILE *fileptr;
  
  char readmode[4];
  char filename[20];
};


int get_arg(int getting_arg);
int create_file();

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
}


int create_file() {
    struct newfile file;
    
    printf("<novo arquivo>\n");
    
    printf("nome: ");
    scanf("%s", file.filename);
    
    printf("modo de leitura: ");
    scanf("%s", file.readmode);
    
    file.fileptr = fopen(file.filename, file.readmode);
     
    if (file.fileptr == NULL) {
        alert_message("erro: incapaz de criar o arquivo.");
    }
    
    boot_program();
    
    printf("\narquivo %s ", file.filename);
    alert_message("criado com sucesso.\n");
    
    fclose(file.fileptr);
    
    get_arg(TRUE);   
    return 1;
}

int get_arg(int getting_arg) {
  char arg[2];
  
  while (getting_arg) {
    scanf("%s", arg);
    
    if (strcmp(NEW_FILE, arg) == match) {
        create_file();
        return 0;
    } else if (strcmp(OPEN_FILE, arg) == match) {
      //code
    } else if (strcmp(SAVE_FILE, arg) == match) {
    //code
    } else if (strcmp(QUIT, arg) == match) {
      printf("> até uma próxima!\n");
      exit(1);
    } 
  }
 
  return 0;
}
