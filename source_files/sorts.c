#include "../header_files/sorts.h"

void bubblesort(int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)

        for (j = 0; j < tamanho - i - 1; j++)
        {
            bubble_info.comparacoes++;
            if (vetor[j] > vetor[j + 1])
            {
                troca(&vetor[j], &vetor[j + 1]);
                bubble_info.trocas++;
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
        merge_info.comparacoes++;
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
            merge_info.trocas++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
            merge_info.trocas++;
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

void mergesort(int inicio, int fim)
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
    int pivo = vetor[fim];
    int indice = (inicio - 1);
    int j;

    for (j = inicio; j <= fim - 1; j++)
    {
        quick_info.comparacoes++;
        if (vetor[j] <= pivo)
        {
            indice++;
            troca(&vetor[indice], &vetor[j]);
            quick_info.trocas++;
        }
    }
    troca(&vetor[inicio + 1], &vetor[fim]);
    return (indice + 1);
}

void quicksort(int low, int high)
{
    if (low < high)
    {
        int indice_particao = particao(vetor, low, high);

        quicksort(vetor, low, indice_particao - 1);
        quicksort(vetor, indice_particao + 1, high);
    }
}

void bubble_result(int tamanho)
{
    int vetor_bubble[tamanho];
    memcpy(vetor_bubble, vetor, sizeof vetor_bubble);
    bubble_info.trocas = 0;
    bubble_info.comparacoes = 0;
    header_sorts("BubbleSort");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    bubblesort(vetor_bubble, tamanho);
    QueryPerformanceCounter(&tempo_fim);
    bubble_info.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    bubble_info.tempo *= 1000;
    footer_sorts(bubble_info);
    mostra_vetor(vetor_bubble, tamanho);
}

void merge_result(int tamanho)
{
    int vetor_merge[tamanho];
    memcpy(vetor_merge, vetor, sizeof vetor_merge);
    merge_info.trocas = 0;
    merge_info.comparacoes = 0;
    header_sorts("MergeSort");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    mergesort(vetor_merge, 0, tamanho - 1);
    QueryPerformanceCounter(&tempo_fim);
    merge_info.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    merge_info.tempo *= 1000;
    footer_sorts(merge_info);
    mostra_vetor(vetor_merge, tamanho);
}

void quick_result(int tamanho)
{
    int vetor_quick[tamanho];
    memcpy(vetor_quick, vetor, sizeof vetor_quick);
    quick_info.trocas = 0;
    quick_info.comparacoes = 0;
    header_sorts("QuickSort");
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_comeco);
    quicksort(vetor_quick, 0, tamanho - 1);
    QueryPerformanceCounter(&tempo_fim);
    quick_info.tempo = (double)(tempo_fim.QuadPart - tempo_comeco.QuadPart) / frequencia.QuadPart;
    quick_info.tempo *= 1000;
    footer_sorts(quick_info);
    mostra_vetor(vetor_quick, tamanho);
}

void sortall(int tamanho)
{
    bubble_result(vetor, tamanho);
    merge_result(vetor, tamanho);
    quick_result(vetor, tamanho);
    printf("\nResultados finais (vetor com %d valores):\n", tamanho);
    printf("\nBubblesort:\nTempo: %fms\nTrocas: %lu\nComparações: %d\n", bubble_info.tempo, bubble_info.trocas, bubble_info.comparacoes);
    printf("\nMergesort:\nTempo: %fms\nTrocas: %lu\nComparações: %d\n", merge_info.tempo, merge_info.trocas, merge_info.comparacoes);
    printf("\nQuicksort:\nTempo: %fms\nTrocas: %lu\nComparações: %d\n", quick_info.tempo, quick_info.trocas, quick_info.comparacoes);
}

void header_sorts(char *nome) {
    printf("\n\nOrdenação por %s.", nome);
    printf("\nOrdenando...");
}

void footer_sorts(struct info_sort sort_info) {
    printf("\nOrdenação concluída, tempo gasto: %fms\nTrocas realizadas: %lu; Comparações realizadas: %d\n", sort_info.tempo, sort_info.trocas, sort_info.comparacoes);
    printf("Pressione enter para ver o vetor ordenado.");
    system("pause>null");
}
