#include "header.h"

void pass_generator(const int len_of_pass, const int n_of_pass, char **pass_tab)
{
    int i ;
    int j;

    i = 0;
    srand(time(NULL));
    while (i < n_of_pass)
    {
        pass_tab[i] = malloc(sizeof(char) * (len_of_pass + 1));
        if (!pass_tab[i])
            return;

        j = 0;
        while (j < len_of_pass)
        {
            pass_tab[i][j] = 32 + (rand() % 92);
            j++;
        }
        pass_tab[i][j] = '\0';
        i++;
    }
    pass_tab[i] = NULL;
}
