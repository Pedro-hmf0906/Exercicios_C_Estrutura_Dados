#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Pilha{

    int dado[MAX];
    int topo;
}Pilha;

void inicializarPilhaEstatica(Pilha *p){

    p->topo = -1;

}

int pilhaVazia(Pilha *p){

    return p->topo == -1;

}

int pilhaCheia(Pilha *p){

    return p->topo == MAX - 1;

}

int empilhar(Pilha *p, int valor){

    if(pilhaCheia(p)){
        printf("Pilha cheia !");
        return 0;
    }

    p->topo++;
    p->dado[p->topo] = valor;

    return 1;
}

int desempilhar(Pilha *p, int *valor){

    if(pilhaVazia(p)){
        printf("Pilha vazia !");
        return 0;
    }

    *valor = p->dado[p->topo];
    p->topo--;

    return 1;
}

void liberarPilha(Pilha *p){

    p->topo = -1;

}

void imprimirPilha(Pilha *p){

    if(pilhaVazia(p)){
        printf("Pilha vazia !");
        return;
    }

    printf("Topo -> ");
    for(int i = p->topo; i >= 0; i--){
        printf("%d ", p->dado[i]);
    }
    printf("\n");

}

