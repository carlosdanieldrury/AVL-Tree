#include "biblioteca.h"

void PesquisaAVL(RegistroAVL *xAVL, ApontadorAVL *p)
{ if (*p == NULL) 
  { printf("Erro : Registro nao esta presente na arvore\n");
    return;
  }
  if (strcmp(xAVL->ChaveAVL, (*p)->RegAVL.ChaveAVL)<0) 
  { PesquisaAVL(xAVL, &(*p)->EsqAVL);
    return;
  }
  if (strcmp(xAVL->ChaveAVL, (*p)->RegAVL.ChaveAVL)>0)
  PesquisaAVL(xAVL, &(*p)->DirAVL);
  else
    *xAVL = (*p)->RegAVL;
} 

void rebalanceamento1 (ApontadorAVL *p, int *h) {
  ApontadorAVL pu = (*p)->EsqAVL;
  if (pu->balanceamento == -1) { // rotacao a direita
    //printf("rotacao a direita com %s\n", pu->RegAVL.ChaveAVL);
    (*p)->EsqAVL = pu->DirAVL;
    pu->DirAVL = (*p);
    (*p)->balanceamento = 0;
    (*p) = pu;
  }
  else { // rotacao dupla esquerda-direita
    ApontadorAVL pv = pu->DirAVL;
    //printf("rotacao dupla esquerda-direita com %s\n", pv->RegAVL.ChaveAVL);
    pu->DirAVL = pv->EsqAVL;    pv->EsqAVL = pu;
    (*p)->EsqAVL = pv->DirAVL;  pv->DirAVL = (*p);
    if (pv->balanceamento == -1)  (*p)->balanceamento = 1;
    else (*p)->balanceamento = 0;
    if (pv->balanceamento == 1)  pu->balanceamento = -1;
    else pu->balanceamento = 0;
    (*p) = pv;
  }
  (*p)->balanceamento = 0;
  (*h) = 0;
}

void rebalanceamento2 (ApontadorAVL *p, int *h) {
  ApontadorAVL pu = (*p)->DirAVL;
  if (pu->balanceamento == 1) { // rotacao a esquerda
    //printf("rotacao a esquerda com %s\n", pu->RegAVL.ChaveAVL);
    (*p)->DirAVL = pu->EsqAVL;
    pu->EsqAVL = (*p);
    (*p)->balanceamento = 0;
    (*p) = pu;
  }
  else { // rotacao dupla direita-esquerda
    ApontadorAVL pv = pu->EsqAVL;
    //printf("rotacao dupla direita-esquerda com %s\n", pv->RegAVL.ChaveAVL);
    pu->EsqAVL = pv->DirAVL;    pv->DirAVL = pu;
    (*p)->DirAVL = pv->EsqAVL;  pv->EsqAVL = (*p);
    if (pv->balanceamento == 1)  (*p)->balanceamento = -1;
    else (*p)->balanceamento = 0;
    if (pv->balanceamento == -1)  pu->balanceamento = 1;
    else pu->balanceamento = 0;
    (*p) = pv;
  }
  (*p)->balanceamento = 0;
  (*h) = 0;
}

/*
InsereAVL o registro xAVL na arvore referenciada por p.
h retorna se houve ou nao alteracao na altura da subarvore do no em questao,
induzindo a atualizacao do campo balanceamento. 
*/
void InsereAVL (RegistroAVL xAVL, ApontadorAVL *p, int *h) {
  if (*p == NULL) {
    *p = (ApontadorAVL)malloc(sizeof(NoAVL));
    (*p)->RegAVL = xAVL; (*p)->EsqAVL = NULL; (*p)->DirAVL = NULL;
    (*p)->balanceamento = 0;
    (*p)->ocorrenciaAVL = 1;
    *h = 1;  // balanceamento deve ser verificado
  }
  else if (strcmp(xAVL.ChaveAVL, (*p)->RegAVL.ChaveAVL)<0) {
    InsereAVL(xAVL, &(*p)->EsqAVL, h);
    if (*h) {  // verifica balanceamento
      switch ((*p)->balanceamento) {
        case  1: // subarvores esquerda e direita passam a ter a mesma altura
                 (*p)->balanceamento = 0; (*h) = 0; break;
        case  0: // subarvore esquerda passa a ter uma unidade de altura maior do que a da direita
                 (*p)->balanceamento = -1; break;
        case -1: // subarvore esquerda passa a ter duas unidades de altura maior do que a da direita
                 rebalanceamento1(p, h); break;
      }
    }
  }
  else if (strcmp(xAVL.ChaveAVL, (*p)->RegAVL.ChaveAVL)>0) {
    InsereAVL(xAVL, &(*p)->DirAVL, h);
    if (*h) {  // verifica balanceamento
      switch ((*p)->balanceamento) {
        case -1: // subarvores esquerda e direita passam a ter a mesma altura
                 (*p)->balanceamento = 0; (*h) = 0; break;
        case  0: // subarvore direita passa a ter uma unidade de altura maior do que a da esquerda
                 (*p)->balanceamento = 1; break;
        case  1: // subarvore direita passa a ter duas unidades de altura maior do que a da esquerda
                 rebalanceamento2(p, h); break;
      }
    }
  }
  else {
    *h = 0;
    (*p)->ocorrenciaAVL = (*p)->ocorrenciaAVL + 1;
    printf("Registro %s já existente na árvore.\nAcrescentando mais uma ocorrencia desse registro!..\n", xAVL.ChaveAVL);
  }
} 






void InsereAVLinicial (RegistroAVL xAVL, ApontadorAVL *p, int *h) {
  if (*p == NULL) {
    *p = (ApontadorAVL)malloc(sizeof(NoAVL));
    (*p)->RegAVL = xAVL; (*p)->EsqAVL = NULL; (*p)->DirAVL = NULL;
    (*p)->balanceamento = 0;
    (*p)->ocorrenciaAVL = 1;
    *h = 1;  // balanceamento deve ser verificado
  }
  else if (strcmp(xAVL.ChaveAVL, (*p)->RegAVL.ChaveAVL)<0) {
    InsereAVLinicial(xAVL, &(*p)->EsqAVL, h);
    if (*h) {  // verifica balanceamento
      switch ((*p)->balanceamento) {
        case  1: // subarvores esquerda e direita passam a ter a mesma altura
                 (*p)->balanceamento = 0; (*h) = 0; break;
        case  0: // subarvore esquerda passa a ter uma unidade de altura maior do que a da direita
                 (*p)->balanceamento = -1; break;
        case -1: // subarvore esquerda passa a ter duas unidades de altura maior do que a da direita
                 rebalanceamento1(p, h); break;
      }
    }
  }
  else if (strcmp(xAVL.ChaveAVL, (*p)->RegAVL.ChaveAVL)>0) {
    InsereAVLinicial(xAVL, &(*p)->DirAVL, h);
    if (*h) {  // verifica balanceamento
      switch ((*p)->balanceamento) {
        case -1: // subarvores esquerda e direita passam a ter a mesma altura
                 (*p)->balanceamento = 0; (*h) = 0; break;
        case  0: // subarvore direita passa a ter uma unidade de altura maior do que a da esquerda
                 (*p)->balanceamento = 1; break;
        case  1: // subarvore direita passa a ter duas unidades de altura maior do que a da esquerda
                 rebalanceamento2(p, h); break;
      }
    }
  }
  else {
    *h = 0;
    (*p)->ocorrenciaAVL = (*p)->ocorrenciaAVL + 1;
  }
} 






void InicializaAVL(ApontadorAVL *DicionarioAVL)
{ *DicionarioAVL = NULL;
}

void CentralAVL(ApontadorAVL p)
{ if (p == NULL)
  return;
  CentralAVL(p->EsqAVL);
  printf("%s ", p->RegAVL.ChaveAVL);
  printf("- Ocorrencia: %d\n", p->ocorrenciaAVL);
  CentralAVL(p->DirAVL);
} 

int maximus(int x, int y) {
  if (x > y) return x;
  else return y;
}

int calculaAlturaAVL(ApontadorAVL p) {
  if (p == NULL) { return -1; }
  return 1 + maximus(calculaAlturaAVL(p->EsqAVL), calculaAlturaAVL(p->DirAVL));
}

void TestaIAVL(NoAVL *p, char* paiAVL)
{ if (p == NULL)
  return;
  if (p->EsqAVL != NULL) 
  { if (strcmp(p->RegAVL.ChaveAVL, p->EsqAVL->RegAVL.ChaveAVL)<0) 
    { printf("Erro: Pai %s menor que filho a esquerda %s\n", p->RegAVL.ChaveAVL, p->EsqAVL->RegAVL.ChaveAVL);
      exit(1);
    }
  }
  if (p->DirAVL != NULL) 
  { if (strcmp(p->RegAVL.ChaveAVL, p->DirAVL->RegAVL.ChaveAVL)>0) 
    { printf("Erro: Pai %s maior que filho a direita %s\n",  p->RegAVL.ChaveAVL, p->DirAVL->RegAVL.ChaveAVL);
    exit(1);
    }
  }
  TestaIAVL(p->EsqAVL, p->RegAVL.ChaveAVL);
  TestaIAVL(p->DirAVL, p->RegAVL.ChaveAVL);
}


void TestaAVL(NoAVL *p)
{ if (p != NULL)
  TestaIAVL(p, p->RegAVL.ChaveAVL);
}

