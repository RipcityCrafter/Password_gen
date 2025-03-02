#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void malloc_pass_tab(char ***pass, int n_of_pass);
void save_password(const char *site, const char *password);
void pass_generator(const int len_of_pass, const int n_of_pass, char **pass_tab);

#endif