#include "header.h"

char *pass_generator(int len)
{
    srand(time(NULL));

    int i;
    char *password;
    password = malloc(sizeof(char) * (len + 1));
    if (!password)
    return (NULL);

    i = 0;
    while (i < len)
    {
        password[i] =  32 + (rand() % 92);
        i++;
    }
    password[i] = '\0';
    return (password);    
}