#include "trie.h"

using namespace std;

void iniciaTrie(trie *t){
	int i;
	for(i = 0; i < 27; i++){
		t->letras[i] = NULL;
		t->isword[i] = 0;
		t->freq[i] = 0;
	}
	t->character = 'A';
}

void adicionar(trie *t, char *p, int freq){
	int n = strlen(p), i;
	trie *aux = (trie *)malloc (sizeof(trie));
	aux = t;
	trie *add;
	for(i = 0; i < n; i++){
		if (aux->letras[p[i] - 'a'] == NULL){
			add = (trie *) malloc(sizeof(trie));
			iniciaTrie(add);
			add->character = p[i];
			aux->letras[p[i] - 'a'] = add;
			aux->freq[p[i] - 'a'] = 0;
			aux->isword[p[i] - 'a'] = 0;
			if(i == n-1 && aux->isword[p[i] - 'a'] == 0){
				aux->isword[p[i] - 'a'] = 1;
				aux->freq[p[i] - 'a'] = freq;
			}
			else if(aux->isword[p[i] - 'a'] != 1){
				aux->isword[p[i] - 'a'] = 0;
				aux->freq[p[i] - 'a'] = 0;
			}
			aux = aux->letras[p[i] - 'a'];
		}
		else{
			if(i == n-1 && aux->isword[p[i] - 'a'] == 0){
				aux->isword[p[i] - 'a'] = 1;
				aux->freq[p[i] - 'a'] = freq;
			}
			aux = aux->letras[p[i] - 'a'];
		}
	}
}

int existe(trie *t1, trie *t2, char *p, int pos, int stat){
	int n = strlen(p), i, j = 0;

	trie *aux = (trie *) malloc(sizeof(trie));
	if(pos < n){
		aux = t2;
		for(i = pos; i < n; i++){
			if(aux->letras[p[i] - 'a'] == NULL){
				break;
			}
			else{
				if(i == n-1 and aux->isword[p[i] - 'a'] == 1){
					return 2;
				}
				if(aux->isword[p[i] - 'a'] == 1 and
						stat < aux->freq[p[i] - 'a'] and existe(t2, t2, p, pos+i+1, stat)){
					return 2;
				}
				else aux = aux->letras[p[i] - 'a'];
			}
			j++;
		}
		aux = t1;
		for(i = 0; i < n; i++){
			if(aux->letras[p[i] - 'a'] == NULL){
				break;
			}
			else{
				if((aux->isword[p[i] - 'a'] == 1) and (i >= pos) and stat < aux->freq[p[i] - 'a']){
					return 0;
				}
				else aux = aux->letras[p[i] - 'a'];
			}
			j++;
		}
		return 1;
	}
	else return 1;

}

int busca(trie *t, trie *t2, char *p){
	int n = strlen(p), i, j = 0;
	string c;
	trie *aux = (trie *) malloc(sizeof(trie));
	aux = t;
	if(n>0){
		for(i = 0; i < n; i++){
			c.push_back(p[j]);
			if(aux->letras[p[i] - 'a'] == NULL){
				printf("%s ERRORPRINTING", p);
				return 0;
			}
			else{
				if(i > 0 and aux->isword[p[i] - 'a'] == 1 and existe(t, t2, p, i+1, aux->freq[p[i] - 'a'])){
						j++;
						c.push_back(' ');
						break;
				}
				else aux = aux->letras[p[i] - 'a'];
			}
			j++;
		}
		cout << c << " ";
		busca(t2, t2, p+i+1);
	}
	return 0;
}

void printFreq(trie *t, char *p){
	int n = strlen(p), i;
	trie *aux = (trie *) malloc(sizeof(trie));
	aux = t;
	for(i = 0; i < n; i++){
		if(aux->letras[p[i] - 'a'] != NULL){
			if(i == n-1 && aux->isword[p[i] - 'a'] == 1){
				printf("%d", aux->freq[p[i] - 'a']);
				break;
			}
		else aux = aux->letras[p[i] - 'a'];
		}
	}
}
