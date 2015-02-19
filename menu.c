#include "biblioteca.h"
#include <time.h>

void menuArvoreBinaria(Apontador *p){
	printf("\e[H\e[2J"); //Limpa a tela
	No *Dicionario;
	Inicializa(&Dicionario);
	Dicionario = *p;
	int opcao, controle=0, altura =0, nivel;
	char chave[50];
	Registro x;
	clock_t inicio,fim;
	double time_DSW=0;
	while(controle == 0){
		printf("\n########## Menu Arvore binaria ##########\n\n");
		printf("Escolha uma opcao:\n");
		printf("1 Inserir chave\n");
		printf("2 Remover chave\n");
		printf("3 Pesquisar chave\n");
		printf("4 Balancear arvore usando DSW\n");
		printf("5 Imprimir altura da arvore\n");
		printf("6 Imprimir caminhamento In Ordem\n");
		printf("7 Imprimir arvore com margens\n");
		printf("8 Voltar ao menu anterior\n");
		printf("9 Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("Digite a chave que deseja inserir\n");
				scanf("%s", chave);
				x.Chave = chave;
				Insere(x.Chave, &Dicionario);
				break;
			case 2:
				printf("Digite a chave que deseja remover\n");
				scanf("%s", chave);
				x.Chave = chave;
				Retira(x.Chave, &Dicionario);
				break;
			case 3:
				printf("Digite a chave que deseja pesquisar\n");
				scanf("%s", x.Chave);
				Pesquisa(&x.Chave, &Dicionario);
				break;
			case 4:
				inicio = clock();
				fim = clock();
				//printf("Altura da Árvore antes do Balanceamento : %d\n",calculaAltura(Dicionario));
				//chamar aqui o DSW
				AlgoritmoDSW(&Dicionario);
				//printf("Altura da Árvore depois do Balanceamento  : %d\n",calculaAltura(Dicionario));
				time_DSW = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
				printf("\n%3.3f Segundos para utilizar o algoritmo de Balanceamento. \n\n",time_DSW);
				break;
				
			case 5:
				altura = calculaAltura(Dicionario);
				printf("Altura da arvore binaria = %d\n", altura);
				break;
			case 6:
				Central(Dicionario);
				break;
			case 7:
				imprimeRecuoDeMargem(Dicionario, 0);
				break;
			case 8:
				controle = 1;
				break;
			case 9:
				printf("O programa foi encerrado\n");
				exit(0);
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	}
}


void menuArvoreAVL(Apontador *p){
	printf("\e[H\e[2J"); //Limpa a tela
	No *DicionarioAVL;
	Inicializa(&DicionarioAVL);
	DicionarioAVL = *p;
	int opcao, controle =0, altura =0, nivel;
	char chave[50];
	RegistroAVL x;
	while(controle == 0){
		printf("\n########## Menu Arvore AVL ##########\n\n");
		printf("Escolha uma opcao:\n");
		printf("1 Inserir chave\n");
		printf("2 Pesquisar chave\n");
		printf("3 Imprimir altura da arvore\n");
		printf("4 Imprimir caminhamento In Ordem\n");
		printf("5 Imprimir arvore com margens\n");
		printf("6 Voltar ao menu anterior\n");
		printf("7 Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("Digite a chave que deseja inserir\n");
				scanf("%s", chave);
				x.ChaveAVL = chave;
				Insere(x.ChaveAVL, &DicionarioAVL);
				break;
			case 2:
				printf("Digite a chave que deseja pesquisar\n");
				scanf("%s", chave);
				x.ChaveAVL = chave;
				PesquisaAVL(&x.ChaveAVL, &DicionarioAVL);
				break;
			case 3:
				altura = calculaAlturaAVL(DicionarioAVL);
				printf("Altura da arvore AVL = %d",altura);
				break;
			case 4:
				Central(DicionarioAVL);
				break;
			case 5:
				imprimeRecuoDeMargem(DicionarioAVL, 0);
				//imprimeMargem(DicionarioAVL, nivel);
				break;
			case 6:
				controle = 1;
				break;
			case 7:
				printf("O programa foi encerrado\n");
				exit(0);
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	}
}

void menuPrincipal(Apontador *p, Apontador *q){
	int opcao;
	for(;;){
		printf("\n########## Menu principal ##########\n");
		printf("Escolha uma opcao:\n\n");
		printf("1 Arvore Binaria\n");
		printf("2 Arvore AVL\n");
		printf("3 Sair\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				menuArvoreBinaria(&(*p));
				break;
			case 2:
				menuArvoreAVL(&(*q));
				break;
			case 3:
				printf("O programa foi encerrado\n");
				exit(0);
			default:
				printf("Opcao invalida. Tente novamente\n\n");
		}
	}
}	


void leArquivoBinaria(char *texto){
	No *Dicionario;
	Registro x;
	Inicializa(&Dicionario);
	int flag=0, cont=0;
	char caractere;
	texto = optarg;
	int max = 50;
	char *vetor2;
	FILE *p;
	clock_t inicio,fim;
	double time_binaria=0;
    inicio=clock();
	p=fopen (texto,"r+");
	vetor2 = (char *) malloc (max * sizeof(char *));
	while(!feof(p)){
				caractere = getc(p);
				if ((caractere == ',')||(caractere == '.')||(caractere == '!')||(caractere == '?')||(caractere == ';')||(caractere == ':')||(caractere == '/')) {
					x.Chave = vetor2;
					Insereinicial(x, &Dicionario);
					cont = 0;
					vetor2 = (char *) malloc (max * sizeof(char *));
					caractere = getc(p);
					if ((caractere == ' ')||(caractere == '\n')||(caractere == '\0')) flag = 2;
				}
				if ((caractere == ' ')||(caractere == '\n')||(caractere == '\0')) flag = 1;
				if (flag == 0) {
					caractere = tolower(caractere);
					vetor2[cont] = caractere;
					cont++;
				}
				if (flag == 1) {
				  if(cont > 0){
					x.Chave = vetor2;
					Insereinicial(x, &Dicionario);
					cont = 0;
					vetor2 = (char *) malloc (max * sizeof(char *));
				  }
				}
				flag = 0;
	}
	fclose(p);
	fim=clock();
	time_binaria = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
	printf("\n%3.3f Segundos para inserir os dados do arquivo na Arvore Binaria \n\n",time_binaria);
	leArquivoAVL(*texto, &(*Dicionario));
	
}

void leArquivoAVL(char *texto, Apontador *Dicionario){
	No *DicionarioAVL, *DicionarioBinaria;
	Inicializa(&DicionarioBinaria);
	DicionarioBinaria = Dicionario;
	RegistroAVL x;
	Registro y;
	InicializaAVL(&DicionarioAVL);	
	int teste =0, h, flag=0, cont=0;
	char caractere;
	texto = optarg;
	int max = 50;
	char *vetor2;
	clock_t inicio,fim;
	double time_AVL=0;
    inicio=clock();
	FILE *p;
	p=fopen (texto,"r+");
	vetor2 = (char *) malloc (max * sizeof(char *));
	while(!feof(p)){
				caractere = getc(p);
				if ((caractere == ',')||(caractere == '.')||(caractere == '!')||(caractere == '?')||(caractere == ';')||(caractere == ':')||(caractere == '/')) {
					x.ChaveAVL = vetor2;
					InsereAVLinicial(x, &DicionarioAVL, &h);
					cont = 0;
					vetor2 = (char *) malloc (max * sizeof(char *));
					caractere = getc(p);
					if ((caractere == ' ')||(caractere == '\n')||(caractere == '\0')) flag = 2;
				}
				if ((caractere == ' ')||(caractere == '\n')||(caractere == '\0')) flag = 1;
				if (flag == 0) {
					caractere = tolower(caractere);
					vetor2[cont] = caractere;
					cont++;
				}
				if (flag == 1) {
				  if(cont > 0){
					x.ChaveAVL = vetor2;
					InsereAVLinicial(x, &DicionarioAVL, &h);
					cont = 0;
					vetor2 = (char *) malloc (max * sizeof(char *));
				  }

				}
				flag = 0;
	}
	fclose(p);
	fim=clock();
	time_AVL = (double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
	printf("\n%3.3f Segundos para inserir os dados do arquivo na Arvore AVL \n\n",time_AVL);
	menuPrincipal(&DicionarioBinaria, &DicionarioAVL);
	
}
