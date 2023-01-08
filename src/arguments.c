#include "../include/arguments.h"
#include "../include/filecreation.h"

void alert_message(char alert[50])
{
    puts(alert);
}
int get_arg(int getting_arg)
{
    char *arg = (char *)malloc(21 * sizeof(char));

    while (getting_arg)
    {
        printf("> ");
        scanf("%s", arg);

        if (strcmp(NEW_FILE, arg) == match)
        {
            create_file();
        }
        else if (strcmp(OPEN_FILE, arg) == match)
        {
            open_file();
        }
        else if (strcmp(QUIT, arg) == match)
        {
            alert_message("> até uma próxima!\n");
            exit(1);
        }
        else if (strcmp(LIST_ARQ, arg) == match)
        {
            systemf("ls ./data/");
        }
        else if (strcmp(CLEAR_S, arg) == match)
        {
            systemf("clear");
            boot_program();
        }
    }

    free(arg);
    return 0;
}
