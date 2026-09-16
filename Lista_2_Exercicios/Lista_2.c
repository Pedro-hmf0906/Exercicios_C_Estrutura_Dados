#include<stdio.h>
#include<stdlib.h>

typedef struct No{

    int dado;
    struct No *prox;
}No;

No *cabeca;

No *criarNo(int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        return NULL;
    }

    novo->dado = valor;
    novo->prox = NULL;
    cabeca = novo;

    return novo;
}

void inserirAntes(int valorAntes, int valorBuscado){
    if(cabeca == NULL){
        printf("Lista vazia !");
        return;
    }
    No *ant = NULL;
    No *atual = cabeca;

    while(atual != NULL && atual->dado != valorBuscado){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Valor nao encontrado !");
        return;
    }

    No *nova = criarNo(valorAntes);

    if(ant == NULL){
        nova->prox = cabeca;
        cabeca = nova;
        return;
    }else{
        nova->prox = atual;
        ant->prox = nova;
    }
}