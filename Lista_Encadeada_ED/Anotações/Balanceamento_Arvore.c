#include<stdlib.h>
#include<stdio.h>

typedef struct No{

    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
}No;

int altura(No *raiz){

    if(raiz == NULL){
        return -1;
    }
    return raiz->altura;
}

int maior(int a, int b){
    return (a > b) ? a : b;
}

No *criarNo(int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória !");
        return NULL;
    }

    novo->valor = valor;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int fatorBalanceamento(No *raiz){

    if(raiz == NULL){
        return 0;
    }

    return altura(raiz->esq) - altura(raiz->dir);
}

No *rotacaoDireita(No *y){

    No *x = y->esq;
    No *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = 1 + maior(altura(y->esq), altura(y->dir));
    x->altura = 1 + maior(altura(x->esq), altura(x->dir));

    return x;
}

No *rotacaoEsquerda(No *x){

    No *y = x->dir;
    No *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = 1 + maior(altura(x->esq), altura(x->dir));
    y->altura = 1 + maior(altura(y->esq), altura(y->dir));

    return y;
}

No *inserir(No *raiz, int valor){

    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->valor){
        raiz->esq = inserir(raiz->esq, valor);
    }else if(valor > raiz->valor){
        raiz->dir = inserir(raiz->dir, valor);
    }else{
        return raiz; // Valores duplicados não são permitidos
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    int fb = fatorBalanceamento(raiz);

    // Rotação à direita
    if(fb > 1 && valor < raiz->esq->valor){
        return rotacaoDireita(raiz);
    }

    // Rotação à esquerda
    if(fb < -1 && valor > raiz->dir->valor){
        return rotacaoEsquerda(raiz);
    }

    // Rotação dupla à direita
    if(fb > 1 && valor > raiz->esq->valor){
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Rotação dupla à esquerda
    if(fb < -1 && valor < raiz->dir->valor){
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

No *buscar(No *raiz, int valor){

    if(raiz == NULL || raiz->valor == valor){
        return raiz;
    }

    if(valor < raiz->valor){
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

No *remover(No *raiz, int valor){

    if(raiz == NULL){
        return NULL;
    }

    if(valor < raiz->valor){

        raiz->esq = remover(raiz->esq, valor);

    }else if(valor > raiz->valor){

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
        raiz->valor = temp->valor;
        raiz->dir = remover(raiz->dir, temp->valor);
    }

    raiz->altura = 1 + maior(altura(raiz->esq), altura(raiz->dir));

    int fb = fatorBalanceamento(raiz);

    // Rotação à direita
    if(fb > 1 && fatorBalanceamento(raiz->esq) >= 0){
        return rotacaoDireita(raiz);
    }

    // Rotação à esquerda
    if(fb < -1 && fatorBalanceamento(raiz->dir) <= 0){
        return rotacaoEsquerda(raiz);
    }

    // Rotação dupla à direita
    if(fb > 1 && fatorBalanceamento(raiz->esq) < 0){
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Rotação dupla à esquerda
    if(fb < -1 && fatorBalanceamento(raiz->dir) > 0){
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}