#include<stdlib.h>

#define MAX 100

typedef struct{

    int dado[MAX];
    int inicio;
    int fim;
    int qtd;
}Deque;

void inicializarDeque(Deque *d){

    d->inicio = 0;
    d->fim = -1;
    d->qtd = 0;

}

int dequeVazio(Deque *d){

    return d->qtd == 0;

}

int dequeCheio(Deque *d){

    return d->qtd == MAX;

}

int inserirInicio(Deque *d, int valor){
    if(dequeCheio(d)){
        printf("Deque cheio !");
        return 0;
    }

    d->inicio = (d->inicio - 1 + MAX) % MAX;
    d->dado[d->inicio] = valor;
    d->qtd++;
    return 1;
}

int inserirFim(Deque *d, int valor){
    if(dequeCheio(d)){
        printf("Deque cheio !");
        return 0;
    }

    d->fim = (d->fim + 1) % MAX;
    d->dado[d->fim] = valor;
    d->qtd++;
    return 1;
}

int removerInicio(Deque *d, int *valor){
    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->dado[d->inicio];
    d->inicio = (d->inicio + 1) % MAX;
    d->qtd--;
    return 1;
}

int removerFim(Deque *d, int *valor){
    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->dado[d->fim];
    d->fim = (d->fim - 1 + MAX) % MAX;
    d->qtd--;
    return 1;
}

void imprimirDeque(Deque *d){
    if(dequeVazio(d)){
        printf("Deque vazio !");
        return;
    }

    printf("Deque: ");
    for(int i = 0; i < d->qtd; i++){
        int index = (d->inicio + i) % MAX;
        printf("%d ", d->dado[index]);
    }
    printf("\n");
}

void liberarDeque(Deque *d){
    d->inicio = 0;
    d->fim = -1;
    d->qtd = 0;
}

int consultarInicio(Deque *d, int *valor){
    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->dado[d->inicio];
    return 1;
}

int consultarFim(Deque *d, int *valor){
    if(dequeVazio(d)){
        printf("Deque vazio !");
        return 0;
    }

    *valor = d->dado[d->fim];
    return 1;
}

