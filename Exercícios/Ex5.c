#include <stdio.h>
#include <stdlib.h>

void inverter(int *p, int n)
{

    int *inicio = p;        // Primeira posição
    int *fim = p + (n - 1); // Ultima posição
    int temp;               // Variável de referência

    while (inicio < fim)
    {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main()
{

    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / 4;

    inverter(vetor, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("Posição %d: %d\n", i + 1, vetor[i]);
    }
    return 0;
}