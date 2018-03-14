#include "trie.h"
#include "formata.h"
#include "frequencia.h"

using namespace std;

int main(int argc, char *argv[]){

	int M, i, j, prop;
	char texto[20], dicionario[20], cidades[50];
	ifstream name_file(argv[1]);
	ifstream lastname_file(argv[2]);
	trie *Nome, *Sobrenome;
	Nome = (trie *) malloc(sizeof(trie));
	Sobrenome = (trie *) malloc(sizeof(trie));
	iniciaTrie(Nome);
	iniciaTrie(Sobrenome);

	while(name_file >> prop >> dicionario >> cidades){
		for(j = 0; j < strlen(dicionario); j++){
			caseSensitive(dicionario, j);
			accents(dicionario, j);
		}
		adicionar(Nome, dicionario, prop);
	}
	while(lastname_file >> prop >> dicionario >> cidades ){
		for(j = 0; j < strlen(dicionario); j++){
			caseSensitive(dicionario, j);
			accents(dicionario, j);
		}
		adicionar(Sobrenome, dicionario, prop);
	}

	ifstream files_in(argv[3]);
	files_in >> M;
	for(i = 0; i < M; i++){
		files_in >> texto;
		for(j = 0; j < strlen(texto); j++){
			caseSensitive(texto, j);
			accents(texto, j);
		}
		busca(Nome, Sobrenome, texto);
		printf("\n");
	}

	return 0;
}
