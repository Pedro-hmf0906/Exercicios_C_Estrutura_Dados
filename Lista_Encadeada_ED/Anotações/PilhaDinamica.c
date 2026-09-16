#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int dado;
    struct No *prox;
}No;

typedef struct {
    No *topo;
}Pilhas;

void inicializarPilhaDinamica(Pilhas *p){

    p->topo = NULL;

}

int pilhaVazia(Pilhas *p){

    return p->topo == NULL;

}

int push(Pilhas *p, int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória !");
        return 0;
    }

    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;

    return 1;
}

int pop(Pilhas *p, int *valor){

    if(pilhaVazia(p)){
        printf("Pilha vazia !");
        return 0;
    }

    No *aux = p->topo;
    *valor = aux->dado;
    p->topo = aux->prox;
    free(aux);

    return 1;
}

int top(Pilhas *p, int *valor){

    if(pilhaVazia(p)){
        printf("Pilha vazia !");
        return 0;
    }

    *valor = p->topo->dado;
    return 1;
}

void imprimirPilhaDinamica(Pilhas *p){

    if(pilhaVazia(p)){
        printf("Pilha vazia !");
        return;
    }

    printf("Topo -> ");
    No *aux = p->topo;
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");

}

void liberarPilhaDinamica(Pilhas *p){

    No *aux;

    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }

}