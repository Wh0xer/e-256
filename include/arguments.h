#include <stdarg.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define QUIT "q"     // concluido
#define NEW_FILE "c" // concluido
#define CLEAR_S "cls"
#define OPEN_FILE "o" // em curso
// #define SAVE_FILE   "s" //em curso
#define GET_HELP "h" // em curso
#define LIST_ARQ "l" // concluido

#define CMD_TAM_MAX (1024)
#define LINE_MAX 9999999999999

#define match 0

int get_arg(int getting_arg);