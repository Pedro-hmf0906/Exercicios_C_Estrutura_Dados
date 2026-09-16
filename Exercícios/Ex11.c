#include <stdio.h>
#include <stdlib.h>

void pares(int v[], int n){

    if(n<2){

        return 1;

    }

    for(int i = 0; i < n; i++){

        if(v[i]%2 == 0){

            printf("%d ", v[i]);

        }

    }

    printf("\n");

}

int main(){
    
    int n = 5;
    
    int *vetor = (int *) malloc(n * sizeof(int));

    if(vetor == NULL){
        return 1;
    }

    for(int i = 0; i < n; i++){

        printf("Posição %d: ", i+1);
        scanf("%d", vetor+i);

    }

    pares(vetor, n);

    return 0;

}