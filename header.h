#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *pass_generator(int len);
void save_password(const char *site, const char *password);


#endif