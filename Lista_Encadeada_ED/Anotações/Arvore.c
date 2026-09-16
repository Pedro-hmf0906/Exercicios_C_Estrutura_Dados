#include<stdio.h>
#include<stdlib.h>

typedef struct No{

    int dado;
    struct No *esq;
    struct No *dir;
}No;

No *criarNo(int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória !");
        return NULL;
    }

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void preOrdem(No *raiz){

    if(raiz == NULL) return;

    printf("%d ", raiz->dado);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void emOrdem(No *raiz){

    if(raiz == NULL) return;

    emOrdem(raiz->esq);
    printf("%d ", raiz->dado);
    emOrdem(raiz->dir);
}

void posOrdem(No *raiz){

    if(raiz == NULL) return;

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d ", raiz->dado);
}

//ARVORES DE BUSCA BINÁRIA -> MENORES À ESQUERDA E MAIORES À DIREITA

No *inserir(No *raiz, int valor){

    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->dado){
        raiz->esq = inserir(raiz->esq, valor);
    }else if(valor > raiz->dado){
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No *buscar(No *raiz, int valor){

    if(raiz == NULL || raiz->dado == valor){
        return raiz;
    }

    if(valor < raiz->dado){
        return buscar(raiz->esq, valor);
    }else{
        return buscar(raiz->dir, valor);
    }
}

No *encontrarMenor(No *raiz){

    No *atual = raiz;

    while(atual && atual->esq != NULL){
        atual = atual->esq;
    }

    return atual;
}

No *encontrarMaior(No *raiz){

    No *atual = raiz;

    while(atual && atual->dir != NULL){
        atual = atual->dir;
    }

    return atual;
}

int altura(No *raiz){

    if(raiz == NULL){
        return 0;
    }

    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);

    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int contarNos(No *raiz){

    if(raiz == NULL){
        return 0;
    }

    return contarNos(raiz->esq) + contarNos(raiz->dir) + 1;
}

No *remover(No *raiz, int valor){

    if(raiz == NULL){
        return NULL;
    }

    if(valor < raiz->dado){

        raiz->esq = remover(raiz->esq, valor);

    }else if(valor > raiz->dado){

        raiz->dir = remover(raiz->dir, valor);

    }else{
        
        if(raiz->esq == NULL && raiz->dir == NULL){
            
            free(raiz);
            return NULL;

        }else if(raiz->esq == NULL){
            
            No *temp = raiz->dir;
            free(raiz);
            return temp;

        }else if(raiz->dir == NULL){

            No *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        No *temp = encontrarMenor(raiz->dir);
        raiz->dado = temp->dado;
        raiz->dir = remover(raiz->dir, temp->dado);
    }

    return raiz;
}

void liberarArvore(No *raiz){

    if(raiz != NULL) {
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);}
}

int contarFolhas(No *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

int existe(No *raiz, int x) {
    if (raiz == NULL) return 0;
    if (raiz->dado == x) return 1;
    return existe(raiz->esq, x) || existe(raiz->dir, x);
}

