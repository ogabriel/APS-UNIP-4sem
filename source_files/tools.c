#include "../header_files/tools.h"

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void mostra_vetor(int *vetor, int tamanho)
{
    printf("\nVetor ordenado:\n");
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\t", vetor[i]);
    }
}

void preenche(int *vetor, int tamanho)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand();
        printf("%d\t", vetor[i]);
    }
}
