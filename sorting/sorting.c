#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void sort1(int *vetor)
{
	/*
  Ordenação por XSort.
  Ordenando...
  Ordenação concluída, tempo gasto: %dns, tempo_xsort
  Trocas realizadas: %d; Comparações realizadas: %d, trocas_xsort, comparacoes_xsort
  Pressione enter para ver o vetor ordenado
  mostra(vetor);
  */
}
void sort2(int *vetor)
{
  /*
  Ordenação por YSort.
  Ordenando...
  Ordenação concluída, tempo gasto: %dns, tempo_ysort
  Trocas realizadas: %d; Comparações realizadas: %d, trocas_ysort, comparacoes_ysort
  Pressione enter para ver o vetor ordenado
  mostra(vetor);
  */
}
void sort3(int *vetor)
{
  /*
  Ordenação por ZSort.
  Ordenando...
  Ordenação concluída, tempo gasto: %dns, tempo_zsort
  Trocas realizadas: %d; Comparações realizadas: %d, trocas_zsort, comparacoes_zsort
  Pressione enter para ver o vetor ordenado
  mostra(vetor);
  */
}
void sortall(int *vetor)
{
  sort1(vetor);
  sort2(vetor);
  sort3(vetor);
  /*
  Resultados finais(vetor com %d valores, tamanho):
	XSort:
  Tempo: %dns, tempo_xsort
	Trocas %d, trocas_xsort
	Comparações %d	comparacoes_xsort

	YSort:
  Tempo: %dns, tempo_ysort
	Trocas %d, trocas_ysort
	Comparações %d	comparacoes_ysort

  ZSort:
  Tempo: %dns, tempo_zsort
	Trocas %d, trocas_zsort
	Comparações %d	comparacoes_zsort
  */
}
void preenche(int *vetor)
{
	int i;
	for (i=0; i<TAM; i++)
	{
		vetor[i]=rand()%somevalue;
		printf("%d\t", vetor[i]);
	}
}
void mostra(int *vetor)
{
	printf("\nVetor ordenado:\n");
	int i;
	for(i=0;i<TAM;i++)
	{
		printf("%d\t",vetor[i]);
	}
}
