#include <stdio.h>
#include <stdlib.h>

int *alocar_vetor(int n)
{

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro ao alocar na memória !");
        return 1;
    }
    return vetor;
}

void ler_valores(int *p, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("Posição %d: ", i + 1);
        scanf("%d", &p[i]);
    }
}

void imprimir_estatisticas(int *p, int tamanho)
{

    int maior = p[0];
    int menor = p[0];
    long soma = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (maior < p[i])
        {
            maior = p[i];
        }
        if (menor > p[i])
        {
            menor = p[i];
        }
        soma += p[i];
    }

    float media = (float)soma / tamanho;

    printf("----------Resultado----------");
    printf("\nMaior: %d", maior);
    printf("\nMenor: %d", menor);
    printf("\nSoma: %ld", soma);
    printf("\nMédia: %.2f", media);
}

int main()
{
    int n;
    int *vetor = NULL;

    while (1)
    {
        printf("Insira o tamanho desejado: ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("\nInsira um valor maior que 0 !\n");
            continue;
        }
        else
        {
            break;
        }
    }

    vetor = alocar_vetor(n);

    ler_valores(vetor, n);

    imprimir_estatisticas(vetor, n);

    free(vetor);
    vetor = NULL;

    return 0;
}