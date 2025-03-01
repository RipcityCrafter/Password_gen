#include "header.h"

int main()
{
    int len_of_pass;
    char *password;
    char site_name[100];
    int n_of_pass;
    int i;

    printf("Combien de mpd voulez vous enregistre? ->\n");
    scanf("%d", &n_of_pass);

    i = 0;
    while (i < n_of_pass)
    {
        printf("\nQuelle taille doit faire le mot de passe? ->");
        scanf("%d", &len_of_pass);
        password = pass_generator(len_of_pass);
        printf("Mot de passe généré : %s\n", password);

        printf("Quel est le nom du site ou service pour ce mot de passe?(sans espaces)\n");
        scanf("%s", site_name);

        save_password(site_name, password);

        free(password);
        i++;
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

    fprintf(file, "@%-25s : %s\n", site, password);
    fclose(file);
}

