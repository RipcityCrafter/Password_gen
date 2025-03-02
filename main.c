#include "header.h"

int main()
{
    char    **password;
    int     n_of_pass;
    int     strenght_of_pass;
    int     len_of_pass;
    int     i;

    printf("=================================================\n");
    printf("How many passwords do you want to create?   ");
    scanf("%d",&n_of_pass);
    system("clear");
    printf("=================================================\n");
    printf("What level of security for your passwords?\n1.for low, 2.for medium, 3.for high   ");
    scanf("%d", &strenght_of_pass);
    system("clear");

    malloc_pass_tab(&password, n_of_pass);

    if (strenght_of_pass == 1)
        len_of_pass = 12;
    else if (strenght_of_pass == 2)
        len_of_pass = 20;
    else
        len_of_pass = 30;

    pass_generator(len_of_pass, n_of_pass, password);

    i = 0;
    while (i < n_of_pass)
    {
        char    site_name[100];
        printf("=================================================\n");
        printf("Enter the site name for password %d : ", i + 1);
        scanf("%s", site_name);
        save_password(site_name, password[i]);
        i++;
        system("clear");
    }
    i = 0;
    while (i < n_of_pass)
    {
        free(password[i]);
        i++;
    }
    free (password);
    printf("=================================================\n");
    printf("All your passwords are saved in the password.txt file.\nGo to the VAULT MAKER app to encrypt your passwords.\n");
    printf("=================================================\n");
    return (0);
}

void malloc_pass_tab(char ***pass, int n_of_pass)
{
    *pass = malloc(sizeof(char *) * (n_of_pass + 1));
    if (!(*pass))
    return;
}


void save_password(const char *site, const char *password)
{
    FILE *file;
    file = fopen("passwords.txt", "a");
    if (!file)
        return;
    fprintf(file, "@%-25s : %s\n", site, password);
    fclose(file);
}

