#include "../include/filecreation.h"
#include "../include/arguments.h"

int open_file()
{
    // systemf("cd ./data/");

    newfile *opened_file = malloc(21 * sizeof(*opened_file));

    opened_file->filename = (char *)malloc(21 * sizeof(char));
    opened_file->readmode = (char *)malloc(21 * sizeof(char));

    opened_file->readmode = "r+";

    alert_message("<digite o nome do arquivo que deseja abrir> ");
    scanf("%s", opened_file->filename);

    opened_file->fileptr = fopen(opened_file->filename, opened_file->readmode);

    if (opened_file->fileptr == NULL)
    {
        fprintf(stderr, "erro ao abrir o arquivo!\n");
        return EXIT_FAILURE;
    }

    alert_message("arquivo aberto para edição!\n");

    free(opened_file);

    sleep(2);
    systemf("clear");
    printf("\t<editando arquivo %s>\n", opened_file->filename);

    char *input = (char *)malloc(21 * sizeof(char));


    do
    {
        
        scanf("%s", input);
        

        if (strcmp(input, "qs") == 0)
        {
            free(input);
            boot_program();
            alert_message("fim da edição");

            fclose(opened_file->fileptr);

            // systemf("cd ../");
            get_arg(TRUE);
        }
    } while (input);
    return 0;
}