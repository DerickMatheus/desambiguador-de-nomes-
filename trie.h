#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

typedef struct celula{
	struct celula *letras[27];
	char character;
	int isword[27];
	int freq[27];
}trie;

void iniciaTrie(trie *);
void adicionar(trie *, char *, int);
int busca(trie *t, trie *t2, char *);
void printFreq(trie *, char *);
