#include <stdio.h>

void boot_program();
void alert_message(char alert[50]);
// void aloca(char **ptr, int tamanho);

// char *preenche();
int systemf(const char *fmt, ...);

int create_file();
int open_file();

typedef struct
{
    FILE *fileptr;

    char *readmode;
    char *filename;
} newfile;