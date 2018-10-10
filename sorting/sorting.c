#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
struct info_sort{
  int tempo;
  int trocas;
  int comparacoes;
};
struct info_sort shell;
struct info_sort merge;
struct info_sort quick;

void shellsort(int *vetor, int tamanho)
{  
  shell.trocas = 0;
  shell.comparacoes = 0;
  printf("Ordenação por Shellsort.");
  printf("Ordenando...");
  shell.tempo = clock_gettime();
  
  printf("Ordenação concluída, tempo gasto: %dns\n", clock_gettime() - shell.tempo);
  printf("Trocas realizadas: %d; Comparações realizadas: %d\n", shell.trocas, shell.comparacoes);
  printf("Pressione enter para ver o vetor ordenado.");
  system("pause>null");
  mostra(vetor, tamanho);
}
void mergesort(int *vetor, int tamanho)
{
  merge.trocas = 0;
  merge.comparacoes = 0;
  printf("Ordenação por Merge sort.");
  printf("Ordenando...");
  merge.tempo = clock_gettime();
  
  printf("Ordenação concluída, tempo gasto: %dns\n", clock_gettime() - merge.tempo);
  printf("Trocas realizadas: %d; Comparações realizadas: %d\n", merge.trocas, merge.comparacoes);
  printf("Pressione enter para ver o vetor ordenado.");
  system("pause>null");
  mostra(vetor, tamanho);
}
void quicksort(int *vetor, int tamanho)
{
  quick.trocas = 0;
  quick.comparacoes = 0;
  printf("Ordenação por Quicksort.");
  printf("Ordenando...");  
  quick.tempo = clock_gettime();
  
  printf("Ordenação concluída, tempo gasto: %dns\n", clock_gettime() - quick.tempo);
  printf("Trocas realizadas: %d; Comparações realizadas: %d\n", quick.trocas, quick.comparacoes);
  printf("Pressione enter para ver o vetor ordenado.");
  system("pause>null");
  mostra(vetor, tamanho);
}
void sortall(int *vetor, int tamanho)
{
  shellsort(vetor, tamanho);
  mergesort(vetor, tamanho);
  quicksort(vetor, tamanho);
  printf("Resultados finais (vetor com %d valores):\n", tamanho);
  printf("Shellsort:\nTempo: %dns\nTrocas: %d\nComparações: %d", shell.tempo, shell.trocas, shell.comparacoes);
  printf("Merge:\nTempo: %dns\nTrocas: %d\nComparações: %d", merge.tempo, merge.trocas, merge.comparacoes);
  printf("Quicksort:\nTempo: %dns\nTrocas: %d\nComparações: %d", quick.tempo, quick.trocas, quick.comparacoes);
  
}
void preenche(int *vetor, int tamanho)
{
	int i;
	for (i=0; i<tamanho; i++)
	{
		vetor[i]=rand();
		printf("%d\t", vetor[i]);
	}
}
void mostra(int *vetor, int tamanho)
{
	printf("\nVetor ordenado:\n");
	int i;
	for(i=0;i<tamanho;i++)
	{
		printf("%d\t",vetor[i]);
	}
}
