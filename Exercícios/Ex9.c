#include <stdio.h>
#include <stdlib.h>

void imprimirvetor(int *v, int n)
{

    for (int i = 0; i < n; i++)
    {

        printf("\nPosição %d: %d", i + 1, *(v+i));
    }

    printf("\n");
}

void escrevervetor(int *v, int n)
{

    int *p = v;

    for (int i = 0; i < n; i++)
    {

        printf("Digite o valor da posição %d: ", i + 1);
        scanf("%d", p + i);
    }
}

void fusao(int *v1, int *v2, int *v3, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n)
    {
        if (*(v1 + i) < *(v2 + j))
        {
            *(v3 + k) = *(v1 + i);
            i++;
        }
        else
        {
            *(v3 + k) = *(v2 + j);
            j++;
        }
        k++;

        while (i < n)
        {
            *(v3 + k) = *(v1 + i);
            i++;
            k++;
        }

        while (j < n)
        {
            *(v3 + k) = *(v2 + j);
            j++;
            k++;
        }
    }
}

void organizarvetor(int *v, int n)
{

    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(v + j) > *(v + j + 1))
            {
                temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Digite o tamanho dos vetores (ordenados): ");
    scanf("%d", &n);

    // Alocação
    int *vetor1 = (int *)malloc(n * sizeof(int));
    int *vetor2 = (int *)malloc(n * sizeof(int));
    int *vetor3 = (int *)malloc((2 * n) * sizeof(int));

    // Verificação de segurança (IMPORTANTE: usar ||, pois se UM falhar, o programa para)
    if (vetor1 == NULL || vetor2 == NULL || vetor3 == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("\nVETOR 1 (Insira em ordem crescente):\n");
    escrevervetor(vetor1, n);

    printf("\nVETOR 2 (Insira em ordem crescente):\n");
    escrevervetor(vetor2, n);

    // Realiza a fusão
    fusao(vetor1, vetor2, vetor3, n);
    organizarvetor(vetor3, 2*n);

    printf("\n--- VETOR RESULTANTE (FUSAO) ---");
    imprimirvetor(vetor3, 2 * n); // Tamanho agora é 2n


    // Liberação
    free(vetor1);
    free(vetor2);
    free(vetor3);

    return 0;
}