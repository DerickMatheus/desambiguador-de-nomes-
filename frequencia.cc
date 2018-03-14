#include "frequencia.h"

void allocar(dic **d, int size){
		*d = (dic *)malloc(size * sizeof(dic));
}

void adicionaFreq(dic *d, char *p, int pos){
	int i;
	for (i = 0; i < strlen(p); i++)
		d[pos].palavra[i] = p[i];
	d[pos].palavra[strlen(p)] = '\0';
}
