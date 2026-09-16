#include<stdlib.h>
#include<stdio.h>

typedef struct No{

    int dado;
    struct No *prox;
    struct No *ant;
}No;
typedef struct{

    No *inicio;
    No *fim;
}Deque;

void inicializarDeque(Deque *d){

    d->inicio = NULL;
    d->fim = NULL;

}

int dequeVazio(Deque *d){

    return d->inicio == NULL;

}

int inserirInicio(Deque *d, int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória !");
        return 0;
    }

    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = d->inicio;

    if(dequeVazio(d)){
        d->fim = novo;
        d->inicio = novo;
    }else{
        d->inicio->ant = novo;
        d->inicio = novo;
    }

    return 1;
}

int inserirFim(Deque *d, int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro ao alocar memória !");
        return 0;
    }

    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = d->fim;

    if(dequeVazio(d)){
        d->inicio = novo;
        d->fim = novo;
    }else{
        d->fim->prox = novo;
        d->fim = novo;
    }

    return 1;
}

int removerInicio(Deque *d, int *valor){

    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    No *aux = d->inicio;
    *valor = aux->dado;

    if(d->inicio == d->fim){
        d->inicio = NULL;
        d->fim = NULL;
    }else{
        d->inicio = aux->prox;
        d->inicio->ant = NULL;
    }

    free(aux);
    return 1;
}

int removerFim(Deque *d, int *valor){

    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    No *aux = d->fim;
    *valor = aux->dado;

    if(d->inicio == d->fim){
        d->inicio = NULL;
        d->fim = NULL;
    }else{
        d->fim = aux->ant;
        d->fim->prox = NULL;
    }

    free(aux);
    return 1;
}

int consultarInicio(Deque *d, int *valor){

    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->inicio->dado;
    return 1;
}

int consultarFim(Deque *d, int *valor){

    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->fim->dado;
    return 1;
}

void imprimirDeque(Deque *d){

    if(dequeVazio(d)){
        printf("Deque vazio !");
        return;
    }

    printf("Deque: ");
    No *aux = d->inicio;
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void liberarDeque(Deque *d){

    No *aux;

    while(d->inicio != NULL){
        aux = d->inicio;
        d->inicio = d->inicio->prox;
        free(aux);
    }
    d->fim = NULL;

}
