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

void inserirInicio(int valor){

    No *novo = criarNo(valor);

    novo->prox = cabeca;
    cabeca = novo;

}

void inserirFinal(int valor){

    No *novo = criarNo(valor);

    if(cabeca == NULL){
        cabeca = novo;
        return;
    }

    No *aux = cabeca;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;

}

void imprimir(){

    No *aux = cabeca;
    while(aux != NULL){
        printf(" %d ", aux->dado);
        aux = aux->prox;
    }
    printf("NULL\n");

}

void removerInicio(){

    if(cabeca == NULL) return;

    No *aux = cabeca;
    cabeca = aux->prox;
    free(aux);

}

void liberarLista (){

    No *aux;

    while(cabeca != NULL){
        aux = cabeca;
        cabeca = cabeca->prox;
        free(aux);
    }

}

No *buscar(int valor){ 

    No *aux = cabeca;

    if(aux == NULL){
        printf("\nA lista é inexistente !\n");
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

int alterar(int valorSubstituido){

    No *temp = buscar(valorSubstituido);
    int novoValor;

    if(temp == NULL){
        printf("Valor não encontrado !");
        return 0;
    }

    printf("Digite um novo valor que substitua o valor %d: ", valorSubstituido);  
    scanf("%d", &novoValor);

    temp->dado = novoValor;
    return 1;

}

void inserirAntes(int valorBuscado){
    
    if (cabeca == NULL) { printf("Lista vazia!\n"); return; }

    No *ant   = NULL;
    No *atual = cabeca;

    while (atual != NULL && atual->dado != valorBuscado) {
        ant   = atual;
        atual = atual->prox;
    }

    if (atual == NULL) { printf("Valor não encontrado!\n"); return; }
    
    int valorAntes;
    printf("Qual valor você deseja inserir antes de %d ?\n", valorBuscado);
    scanf("%d", &valorAntes);

    No *nova = criarNo(valorAntes);

    if(ant == NULL){ //Verifica se está no início da lista
        nova->prox = cabeca;
        cabeca = nova;
    }else{
        nova->prox = atual;
        ant->prox = nova;
    }
}

int deletarUmElemento(int valor){

    No *alvo = buscar(valor);
    No *aux = cabeca;

    if(alvo == NULL) printf("Valor não encontrado !"); return 0;

    if(alvo == cabeca){
        cabeca = alvo->prox;
        free(alvo);
    }

    while(aux != NULL && aux->prox != alvo){
        aux = aux->prox;
    }

    //Caso específico
    if(aux == NULL){
        printf("Erro interno ao remover !");
        return 0;
    }

    aux->prox = alvo->prox;
    free(alvo);

    return 1;

}

int inserirOrdenado(int valor){
    No *novo = criarNo(valor);

    if(cabeca == NULL || valor < cabeca->dado){
        novo->prox = cabeca;
        cabeca = novo;
        return 1;
    }

    No *aux = cabeca;
    while(aux->prox != NULL && aux->prox->dado <= valor){
        aux = aux->prox; 
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    return 1;
}
