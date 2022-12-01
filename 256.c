// Editor de Texto CLI - Wh0xer.tess3ract.dat

/*
                        , ".bin",
                        ".c", ".cpp",
                        ".html";
*/

#include <stdio.h>          
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TRUE 1
#define FALSE 0

#define QUIT "q"
#define NEW_FILE "c"
#define OPEN_FILE "o"
#define SAVE_FILE "s"

const int match = 0;

const char texttype[] = ".txt";


typedef struct newfile {
  char readmode;
  char filename[20];
  
  char filetype;
}txt, c, bin, cpp, html; 

void boot_program();

int get_arg(int getting_arg);

int main(int argc, char **argv) {
  boot_program();
  get_arg(TRUE);
  
  return 0;
}

void boot_program() {
  for (int count = 0; count < 2; count++) {
    printf("----*-----*------*-----*----*-----*--*----*------*------*-------*-----------*\n");
  }
  
  printf("\t\t\t\t<e-256>\n");
  
  for (int count = 0; count < 3; count++) {
    printf("----*-----*------*-----*----*-----*--*----*------*------*-------*-----------*\n");
  }
}

int get_arg(int getting_arg) {
  char arg[2];
  
  while (getting_arg) {
    scanf("%s", arg);
    
    if (strcmp(NEW_FILE, arg) == match) {
        //code
    } else if (strcmp(OPEN_FILE, arg) == match) {
      //code
    } else if (strcmp(SAVE_FILE, arg) == match) {
    //code
    } else if (strcmp(QUIT, arg) == match) {
      printf("> até uma próxima!\n");
      getting_arg = FALSE;
      exit(1);
    } 
  }
 
  return 0;
}
