#include <stdio.h>
#include "header.h"

int main()
{
    int len_of_pass;
    char *password;

    printf("Quel taille dois faire votre mdp?\n");
    scanf("%d", &len_of_pass);
    printf("\n");
    password = pass_generator(len_of_pass);
    printf("%s\n", password);
    return (0);
}