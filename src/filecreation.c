#include "../include/filecreation.h"
#include "../include/arguments.h"

int create_file()
{
    newfile *file = malloc(21 * sizeof(*file));

    file->readmode = (char *)malloc(5 * sizeof(char));
    file->filename = (char *)malloc(20 * sizeof(char));

    alert_message("\n<novo arquivo>\n");

    alert_message("nome do arquivo> ");
    scanf("%s", file->filename);

    strcpy(file->readmode, "w+");

    file->fileptr = fopen(file->filename, file->readmode);

    if (file->fileptr == NULL)
    {
        fprintf(stderr, "erro ao abrir o arquivo!\n");
        return EXIT_FAILURE;
    }

    systemf("mv %s -t ./data/", file->filename);

    boot_program();

    printf("\narquivo %s ", file->filename);
    alert_message("criado com sucesso.\n");

    fclose(file->fileptr);

    free(file->readmode);
    free(file->filename);
    free(file);

    get_arg(TRUE);
    return 0;
}
