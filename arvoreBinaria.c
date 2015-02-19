#include "biblioteca.h"

void AlgoritmoDSW(Apontador *Dicionario)
	{  Apontador *p;  int nodecount; int i;
	
	for((*p)=Dicionario,nodecount=0;(*p)!=0;(*p)=(*p)->Dir,++nodecount)
		{
		while(RotacaoDireita(p)==1) { }
		}

	for(i=nodecount/2; i>0; i/=2 )
		{  int k;
		for((*p)=Dicionario,k=0;k<i;++k,(*p)=(*p)->Dir)
			{ RotacaoEsquerda(p);  }
		}
	}

/////////////////////////////////////
// Rotates around the current node 
int RotacaoEsquerda(Apontador *node)  // =1 if rotate works,=0 otherwise 
	{  Apontador *nd;  char* data;
	if(node==0 || (*node)->Dir==0) { return 0; }	// No Right Node!!

	(*nd)=(*node)->Dir; (*node)->Dir=(*nd)->Dir;  // Move Node
	(*nd)->Dir=(*nd)->Esq; (*nd)->Esq=(*node)->Esq;
	(*node)->Esq=(*nd);

	data=(*node)->Reg.Chave;  (*node)->Reg.Chave=(*nd)->Reg.Chave; (*nd)->Reg.Chave=data;
	return 1;
	}


/////////////////////////////////////
// Rotate around current node
int RotacaoDireita(Apontador *node) // =1 if rotate works, =0 otherwise
	{  Apontador *nd;  char* data;
	if(node==0 || (*node)->Esq==0) { return 0; }	

	(*nd)=(*node)->Esq; (*node)->Esq=(*nd)->Esq;
	(*nd)->Esq=(*nd)->Esq; (*nd)->Esq=(*node)->Esq;
	(*node)->Dir=(*nd);

	data=(*node)->Reg.Chave; (*node)->Reg.Chave=(*nd)->Reg.Chave;  (*nd)->Reg.Chave=data;
	return 1;
	}


void Pesquisa(Registro *x, Apontador *p)
{ if (*p == NULL) 
  { printf("Erro : Registro nao esta presente na arvore\n");
    return;
  }
  if (strcmp(x->Chave, (*p)->Reg.Chave)<0) 
  { Pesquisa(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x->Chave, (*p)->Reg.Chave)>0)
  Pesquisa(x, &(*p)->Dir);
  else
    *x = (*p)->Reg;
} 

void Insere(Registro x, Apontador *p)
{ if (*p == NULL) 
  { *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x; (*p)->Esq = NULL; (*p)->Dir = NULL;
    (*p)->ocorrencia = 1;
    return;
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave)<0) 
  { Insere(x, &(*p)->Esq); return; }
  if (strcmp(x.Chave, (*p)->Reg.Chave)>0)
  Insere(x, &(*p)->Dir);
  else {
    (*p)->ocorrencia = (*p)->ocorrencia + 1;
    printf("Registro %s já existente na árvore.\nAcrescentando mais uma recorrencia desse registro!..\n", x.Chave);
  }
} 




void Insereinicial(Registro x, Apontador *p)
{ if (*p == NULL) 
  { *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x; (*p)->Esq = NULL; (*p)->Dir = NULL;
    (*p)->ocorrencia = 1;
    return;
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave)<0) 
  { Insereinicial(x, &(*p)->Esq); return; }
  if (strcmp(x.Chave, (*p)->Reg.Chave)>0)
  Insereinicial(x, &(*p)->Dir);
  else {
    (*p)->ocorrencia = (*p)->ocorrencia + 1;
    //printf("Registro %s já existente na árvore.\nAcrescentando mais uma recorrencia desse registro!..\n", x.Chave);
  }
} 


void Inicializa(Apontador *Dicionario)
{ *Dicionario = NULL;
}

void Antecessor(Apontador q, Apontador *r)
{ if ((*r)->Dir != NULL) 
  { Antecessor(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
  printf("Registro removido com sucesso\n");
} 

void Retira(Registro x, Apontador *p)
{  Apontador Aux;
  if (*p == NULL) 
  { printf("Erro : Registro nao esta na arvore\n");
    return;
  }
  if (strcmp(x.Chave, (*p)->Reg.Chave)<0) 
  { Retira(x, &(*p)->Esq); return; }
  if (strcmp(x.Chave, (*p)->Reg.Chave)>0)
  { Retira(x, &(*p)->Dir); return; }
  if ((*p)->Dir == NULL) 
  { Aux = *p;
    *p = (*p)->Esq;
    free(Aux);
    printf("Registro removido com sucesso\n");
    return;
  }
  if ((*p)->Esq != NULL) 
  { Antecessor(*p, &(*p)->Esq);
    return;
  }
  Aux = *p;
  *p = (*p)->Dir;
  free(Aux);
  printf("Registro removido com sucesso\n");
}  

void Central(Apontador p)
{ if (p == NULL)
  return;
  Central(p->Esq);
  printf("%s ", p->Reg.Chave);
  printf("- Ocorrencia: %d\n", p->ocorrencia);
  Central(p->Dir);
} 

void TestaI(No *p, char* pai)
{ if (p == NULL)
  return;
  if (p->Esq != NULL) 
  { if (strcmp(p->Reg.Chave, p->Esq->Reg.Chave)<0) 
    { printf("Erro: Pai %s menor que filho a esquerda %s\n", p->Reg.Chave, p->Esq->Reg.Chave);
      exit(1);
    }
  }
  if (p->Dir != NULL) 
  { if (strcmp(p->Reg.Chave, p->Dir->Reg.Chave)>0) 
    { printf("Erro: Pai %s maior que filho a direita %s\n",  p->Reg.Chave, p->Dir->Reg.Chave);
    exit(1);
    }
  }
  TestaI(p->Esq, p->Reg.Chave);
  TestaI(p->Dir, p->Reg.Chave);
}


void Testa(No *p)
{ if (p != NULL)
  TestaI(p, p->Reg.Chave);
}

// Função que mostra a arvore identada em relação aos niveis
void imprimeMargem(Apontador p,int indent)
{
      int i=0;
      for(i=0;i<indent;i++)
      printf("  ");
      if (p == NULL){
            printf("---\n");
            return;
      }
      printf("%s\n",p->Reg.Chave);
      imprimeMargem(p->Esq,indent + 1);
      imprimeMargem(p->Dir,indent + 1);
}

// Função para calculo da altura
int calculaAltura(Apontador p){
    if (p == NULL) return -1;
    int he = calculaAltura(p->Esq);
    int hd = calculaAltura(p->Dir);
    
    if (he < hd) return hd + 1;
    else return he + 1;
}

void imprimeRecuoDeMargem(Apontador p, int cont){   //Exercício 6
     int i;
     if(p == NULL){
            cont = cont-1;
            printf("\n");
            for(i=0; i<cont+2; i++){
              printf("  ");
            }
            printf("---");
            return;
     }
     else{
          cont = cont+1;
     }
     printf("\n");
     for(i=0; i<cont; i++){
              printf("  ");
     }
     printf("%s", p->Reg.Chave);
     imprimeRecuoDeMargem(p->Esq, cont);
     imprimeRecuoDeMargem(p->Dir, cont);
}
