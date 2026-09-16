#include <stdio.h>

typedef struct
{
    char nome[50];
    int idade;
    float notas;
} Aluno;

//      \n

Aluno *maiorNota(Aluno *v, int n)
{
    if (v == NULL || n <= 0)
    {
        return NULL;
    }

    Aluno *maior = v;
    Aluno *p = v + 1;

    for (p; p < v + n; p++)
    {

        if (p->notas > maior->notas)
        {
            maior = p;
        }
    }

    return maior;
}

int main()
{
    int n;

    printf("Quantos alunos deseja cadastrar ?\n");
    scanf("%d", &n);
    getchar();

    Aluno *turma = (Aluno *)malloc(n * sizeof(Aluno));

    if (turma == NULL)
    {
        printf("Erro ao alocar na memória !");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {

        printf("\n----Dados do Aluno----\n");

        printf("Nome: ");

        fgets((turma + i)->nome, 50, stdin);
        (turma + i)->nome[strcspn((turma + i)->nome, "\n")] = 0;

        printf("Idade: ");
        scanf("%d", &(turma + i)->idade);

        printf("Notas: ");

        while (1)
        {
            scanf("%f", &(turma + i)->notas);
            if ((turma + i)->notas < 0 || (turma + i)->notas > 10)
            {
                printf("\nDigite uma nota de 0 à 10 !!!\n");
                continue;
            }
            else
            {
                break;
            }
        }
        getchar();
    }

    Aluno *melhor = maiorNota(turma, n);

    if (melhor != NULL)
    {
        printf("\n==============================");
        printf("\nALUNO COM MAIOR NOTA:");
        printf("\nNome: %s", melhor->nome);
        printf("\nIdade: %d anos", melhor->idade);
        printf("\nNota Final: %.2f", melhor->notas);
        printf("\n==============================\n");
    }

    free(turma);
    return 0;
}
