#include<stdlib.h>
#include<stdio.h>

int pai(int i){
    return (i - 1) / 2;
}

int filhoEsquerdo(int i){
    return 2 * i + 1;
}

int filhoDireito(int i){
    return 2 * i + 2;
}

int consultar_maximo ( int heap [] , int tamanho ) { 
    if ( tamanho <= 0) {
        printf (" Heap vazio .\n");
        return -1;
    }
    
    return heap [0];
}

void inserir_max_heap( int heap [] , int * tamanho , int capacidade , int valor ) {
    if (*tamanho >= capacidade ) {
        printf (" Heap cheio .\n");
        return ;
    }
    
    int i = *tamanho ;
    heap [i] = valor ;
    (*tamanho ) ++;
    
    while (i > 0 && heap [ pai (i)] < heap [i ]) {
        trocar (& heap [ pai (i) ], & heap [i ]) ;
        i = pai (i);
    }
}

void heapify_down_max( int heap[] , int tamanho , int i) {
    int maior = i;
    int esq = filhoEsquerdo ( i);
    int dir = filhoDireito (i );

    if ( esq < tamanho && heap [ esq ] > heap [ maior ]) {
        maior = esq ;
    }
    if ( dir < tamanho && heap [ dir ] > heap [ maior ]) {
        maior = dir ;
    }
    if ( maior != i) {
        trocar (& heap [i ], & heap [ maior ]) ;
        heapify_down_max ( heap , tamanho , maior );
    }  
}

int remover_maximo( int heap[] , int *tamanho ) {
    if (* tamanho <= 0) {
        printf ("Heap vazio .\n");
        return -1;
    }
    
    int maximo = heap[0];
    heap [0] = heap[*tamanho - 1];
    (* tamanho )--;
    heapify_down_max(heap , *tamanho , 0) ;
    return maximo;
}