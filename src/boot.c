#include "../include/arguments.h"
#include "../include/filecreation.h"

void boot_program()
{
    system("clear");

    newfile interface;

    interface.filename = "interf.txt";
    interface.readmode = "r";

//    interface.f = (FILE *)malloc(21 * sizeof(FILE));

    char *c = (char *)malloc(9999 * sizeof(char));

    interface.fileptr = fopen(interface.filename, interface.readmode);

    if (interface.fileptr == NULL)
    {
        alert_message("erro: interface não aberta.");
    }

    do
    {
        *c = fgetc(interface.fileptr);
        printf("%s", c);
    } while (*c != EOF);

    printf("\n");
}
