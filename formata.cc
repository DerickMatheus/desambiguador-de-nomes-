#include "formata.h"

void caseSensitive(char *s, int i){
	if(s[i] >= 'A' && s[i] <= 'Z'){
		s[i] = s[i] - 'A' + 'a';
	}
}

void accents(char *s, int i){
	int letter = s[i], j;
	if(letter == -61){
		letter = s[i+1];
		if((letter <=-93 && letter >= -95) || (letter <= -125 && letter >= -127))
			s[i] = 'a';
		else if((letter <=-86 && letter >= -87) || (letter <= -118 && letter >= -119))
			s[i] = 'e';
		else if((letter <=-82 && letter >= -83) || (letter <= -114 && letter >= -115))
			s[i] = 'i';
		else if((letter <=-75 && letter >= -77) || (letter <= -107 && letter >= -109))
			s[i] = 'o';
		else if((letter <=-69 && letter >= -70) || (letter <= -101 && letter >= -102))
			s[i] = 'u';
		else if(letter == -89)
			s[i] = 'c';
		if (s[i] >= 'a' && s[i] <= 'z'){
			for(j = i+2; j < strlen(s); j++){
				s[j-1] = s[j];
			}

			s[strlen(s)-1] = '\0';
		}
	}
}
