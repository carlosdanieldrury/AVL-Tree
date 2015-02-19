#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>
#include<time.h>

#ifndef max
    #define max(a,b) ((a) < (b) ? (a) : (b))
#endif

//Estruturas da Árvore AVL

typedef char* TipoChaveAVL;
typedef struct RegistroAVL {
  TipoChaveAVL ChaveAVL;
  /* outros componentes */
} RegistroAVL;
typedef struct NoAVL * ApontadorAVL;
typedef struct NoAVL {
  RegistroAVL RegAVL;
  ApontadorAVL EsqAVL, DirAVL;
  int balanceamento;
  int ocorrenciaAVL;
} NoAVL;
typedef ApontadorAVL TipoDicionarioAVL;



//Estruturas da Árvore Binária

typedef char* TipoChave;
typedef struct Registro {
  TipoChave Chave;
  /* outros componentes */
} Registro;
typedef struct No * Apontador;
typedef struct No {
  Registro Reg;
  Apontador Esq, Dir;
  int ocorrencia;
} No;
typedef Apontador TipoDicionario;


//Chamadas das funções
