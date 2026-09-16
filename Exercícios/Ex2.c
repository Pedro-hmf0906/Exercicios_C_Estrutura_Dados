/*
Implemente uma função que receba um vetor de inteiros e seu tamanho, e retorne
o maior elemento presente no vetor.

A implementação deve obrigatoriamente utilizar aritmética de ponteiros, ou
seja, não é permitido o uso do operador de indexação (por exemplo, v[i]).
*/
#include <stdio.h>

int max(int *p, int tamanho){
    int maximo = *p;
    for(int i = 1; i<tamanho; i++){
        if(maximo < *(p+i)){
            maximo = *(p+i);
        }
    }
    return maximo;
}


int main(){
    
    int arr[] = {3, 7, 2, 9, 5};
    
    int tam = sizeof(arr) / 4;

    for(int i = 0; i < tam; i++){printf("Posição %d: %d\n", i+1, arr[i]);}

    int maior = max(arr, tam);

    printf("\n");
    printf("Resultado: %d", maior);

    return 0;
}