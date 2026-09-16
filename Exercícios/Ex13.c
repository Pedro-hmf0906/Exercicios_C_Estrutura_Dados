#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float notas;
} Aluno;

void aumentarNota(Aluno *v, int n)
{

    if (v == NULL || n <= 0)
    {
        return NULL;
    }

    Aluno *p = v;

    for (p; p < v + n; p++)
    {
        if (p->notas < 10)
        {
            p->notas *= 1.10;
        }
    }
}

void imprimirTurma(Aluno *v, int n)
{
    if (v == NULL || n <= 0)
        return;

    printf("\n--- RELATORIO DE NOTAS ATUALIZADAS (10%% de Aumento) ---\n");

    // Usamos um ponteiro auxiliar 'p' para navegar
    for (Aluno *p = v; p < v + n; p++)
    {
        printf("Nome: %-20s | Nota: %.2f\n", p->nome, p->notas);
    }
    printf("-------------------------------------------------------\n");
}

int main()
{

    Aluno *turma = (Aluno *)malloc(3 * sizeof(Aluno));

    if (turma == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {

        printf("\n----Dados do Aluno----\n");

        printf("Nome: ");

        fgets((turma + i)->nome, 50, stdin);
        (turma + i)->nome[strcspn((turma + i)->nome, "\n")] = 0;

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

    aumentarNota(turma, 3);
    imprimirTurma(turma, 3);

    free(turma);
    return 0;
}