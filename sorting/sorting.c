#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

struct info_sort
{
    double tempo;
    int trocas;
    int comparacoes;
};

LARGE_INTEGER frequencia;
LARGE_INTEGER tempo_comeco;
LARGE_INTEGER tempo_fim;

struct info_sort bubble;
struct info_sort merge;
struct info_sort quick;

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesort(int *vetor, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)

        for (j = 0; j < tamanho - i - 1; j++)
        {
            bubble.comparacoes++;
            if (vetor[j] > vetor[j + 1])
            {
                troca(&vetor[j], &vetor[j + 1]);
                bubble.trocas++;
            }
        }
}

void fundir_vetor(int *vetor, int inicio, int meio, int fim)
{
    int i, j, k;
    int metade1 = meio - inicio + 1;
    int metade2 = fim - meio;

    int L[metade1], R[metade2];

    for (i = 0; i < metade1; i++)
        L[i] = vetor[inicio + i];
    for (j = 0; j < metade2; j++)
        R[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < metade1 && j < metade2)
    {
        merge.comparacoes++;
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
            merge.trocas++;
        }
        k++;
    }

    while (i < metade1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < metade2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);

        fundir_vetor(vetor, inicio, meio, fim);
    }
}

int particao(int *vetor, int inicio, int fim)
{
    troca(&vetor[inicio + (rand() % (fim - inicio + 1))], &vetor[fim]);
    quick.trocas++; // pivô aleatório colocado na última posição
    int indice = (inicio - 1);

    for (int j = inicio; j <= fim; j++)
    {
        quick.comparacoes++;
        if (vetor[j] <= vetor[fim])
        {
            troca(&vetor[++indice], &vetor[j]);
            quick.trocas++;
        }
    }
    return indice;
}

void quicksort(int *vetor, int low, int high)
{
    srand(time(NULL));
    if (low < high)
    {
        int indice_particao = particao(vetor, low, high);

        quicksort(vetor, low, indice_particao - 1);
        quicksort(vetor, indice_particao + 1, high);
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

void mostra(int *vetor, int tamanho)
{
    printf("\nVetor ordenado:\n");
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\t", vetor[i]);
    }
}

void bubble_result(int *vetor, int tamanho)
{
    bubble.trocas = 0;
    bubble.comparacoes = 0;
    printf("Ordenação por Bubblesort.");
    printf("\nOrdenando...");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    bubblesort(vetor, tamanho);
    QueryPerformanceCounter(&tempo_fim);
    bubble.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    bubble.tempo *= 1000000000;
    printf("\nOrdenação concluída, tempo gasto: %fns\nTrocas realizadas: %d; Comparações realizadas: %d\n", bubble.tempo, bubble.trocas, bubble.comparacoes);
    printf("Pressione enter para ver o vetor ordenado.");
    system("pause>null");
    mostra(vetor, tamanho);
}

void merge_result(int *vetor, int tamanho)
{
    merge.trocas = 0;
    merge.comparacoes = 0;
    printf("\nOrdenação por Merge sort.");
    printf("\nOrdenando...");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    mergesort(vetor, 0, tamanho - 1);
    QueryPerformanceCounter(&tempo_fim);
    merge.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    merge.tempo *= 1000000000;
    printf("\nOrdenação concluída, tempo gasto: %fns\nTrocas realizadas: %d; Comparações realizadas: %d\n", merge.tempo, merge.trocas, merge.comparacoes);
    printf("Pressione enter para ver o vetor ordenado.");
    system("pause>null");
    mostra(vetor, tamanho);
}

void quick_result(int *vetor, int tamanho)
{
    quick.trocas = 0;
    quick.comparacoes = 0;
    printf("\nOrdenação por Quicksort.");
    printf("\nOrdenando...");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    quicksort(vetor, 0, tamanho - 1);
    QueryPerformanceCounter(&tempo_fim);
    quick.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    quick.tempo *= 1000000000;
    printf("\nOrdenação concluída, tempo gasto: %fns\nTrocas realizadas: %d; Comparações realizadas: %d\n", quick.tempo, quick.trocas, quick.comparacoes);
    printf("Pressione enter para ver o vetor ordenado.");
    system("pause>null");
    mostra(vetor, tamanho);
}

void sortall(int *vetor, int tamanho)
{
    bubble_result(vetor, tamanho);
    merge_result(vetor, tamanho);
    quick_result(vetor, tamanho);
    printf("\nResultados finais (vetor com %d valores):\n", tamanho);
    printf("Bubblesort:\nTempo: %fns\nTrocas: %d\nComparações: %d\n", bubble.tempo, bubble.trocas, bubble.comparacoes);
    printf("Mergesort:\nTempo: %fns\nTrocas: %d\nComparações: %d\n", merge.tempo, merge.trocas, merge.comparacoes);
    printf("Quicksort:\nTempo: %fns\nTrocas: %d\nComparações: %d\n", quick.tempo, quick.trocas, quick.comparacoes);
}
