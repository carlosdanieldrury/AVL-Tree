#include "biblioteca.h"

int main(int argc, char **argv)
{
	Apontador *Dicionario, *DicionarioAVL;
	int x;
	char *texto;
	while (( x = getopt( argc, argv, "a:" )) != -1) { 	/*Primitiva GetOpt*/
		switch (x){
			case 'a':
			leArquivoBinaria(texto);
		}
			break;
		}
	return 0;
}

