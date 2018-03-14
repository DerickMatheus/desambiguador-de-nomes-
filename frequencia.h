#ifndef FREQUENCIA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char palavra[20];
}dic;

void allocar(dic **, int);
void adicionaFreq(dic *, char *, int);

#endif
