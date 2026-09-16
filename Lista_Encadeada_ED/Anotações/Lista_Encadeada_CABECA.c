#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int dado;
    struct No *prox;

}No;

No *cabeca = NULL;

int inicializarLista(void){

    cabeca = (No*)malloc(sizeof(No));

    if(cabeca == NULL){
        print("Erro ao alocar na memória !");
        return 0;
    }

    cabeca->prox = NULL;
    return 1;
}

int listaVazia(void){
    return cabeca->prox == NULL;
}

int criarNo(int valor){

    No *novo = (No*)malloc(sizeof(No));

    if(novo == NULL){
        return NULL;
    }

    novo->dado = valor;
    novo->prox = NULL;
    cabeca->prox = novo;

    return novo;
}

int inserirInicio(int valor){

    No *nova = criarNo(valor);
    
    nova->prox = cabeca->prox;
    cabeca->prox = nova;

    return 1;
}

int inserirFinal(int valor){

    No *nova = criarNo(valor);

    No *aux = cabeca;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = nova;

    return 1;
}

int inserirAntes(int valor, int valorAntes){

    No *novo = criarNo(valor);

    if(listaVazia()){
        printf("Lista vazia !");
        free(novo);
        return 0;
    }

    No *dps = cabeca->prox;
    No *atual = cabeca;

    while(dps != NULL){
        if(dps->dado == valorAntes){
            novo->prox = dps;
            atual->prox = novo;
            return 1;
        }
        atual = dps;
        dps = dps->prox;
    }
    printf("Valor não encontrado !");
    free(novo);
    return 1;
}

int imprimirLista(void){

    No *aux = cabeca->prox;

    if(aux == NULL){
        printf("Lista vazia !");
        return 0;
    }

    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
    return 1;
}

No *buscar(int valor){

    No *aux = cabeca->prox;

    if(aux == NULL){
        printf("Lista vazia !");
        return NULL;
    }

    while(aux != NULL){
        if(aux->dado == valor){
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}