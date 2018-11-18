#include "../header_files/tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

struct info_sort
{
    double tempo;
    int trocas;
    int comparacoes;
};

LARGE_INTEGER frequencia;
LARGE_INTEGER tempo_comeco;
LARGE_INTEGER tempo_fim;

struct info_sort bubble_info;
struct info_sort merge_info;
struct info_sort quick_info;

void bubblesort(int *vetor, int tamanho);
void fundir_vetor(int *vetor, int inicio, int meio, int fim);

void mergesort(int *vetor, int inicio, int fim);
int particao(int *vetor, int inicio, int fim);
void quicksort(int *vetor, int low, int high);

void bubble_result(int *vetor, int tamanho);
void merge_result(int *vetor, int tamanho);
void quick_result(int *vetor, int tamanho);
void sortall(int *vetor, int tamanho);

void header_sorts(char *nome);
void footer_sorts(struct info_sort sort_info);