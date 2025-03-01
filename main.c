#include "header.h"

int main()
{
    int len_of_pass;
    int stop_of_run;
    char *password;
    char site_name[100];

    stop_of_run = 1;
    while (stop_of_run == 1)
    {
        printf("Quelle taille doit faire le mot de passe? ->");
        scanf("%d", &len_of_pass);
        printf("\n");

        password = pass_generator(len_of_pass);
        printf("Mot de passe généré : %s\n", password);

        printf("Quel est le nom du site ou service pour ce mot de passe?(sans espaces)\n");
        scanf("%s", site_name);

        save_password(site_name, password);

        free(password);
        printf("Avez vous un autre mpd a generer? 1.OUI / 2.NON->");
        scanf("%d", &stop_of_run);
    }

    return (0);
}

void save_password(const char *site, const char *password)
{
    FILE *file = fopen("passwords.txt", "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    fprintf(file, "%s : %s\n", site, password);

    fclose(file);
}
