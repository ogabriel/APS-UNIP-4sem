#include "sorting.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void programa()
{
	char recomecar;
	bool sair = false;
	while (sair == false)
	{
		printf("\n*** Programa de algoritmos de ordenação ***\n");
		printf("Insira o tamanho do vetor a ser gerado: ");
		int tamanho;
		scanf("%d", &tamanho);
		int vetor[tamanho];
		printf("Vetor com %d números. Pressione enter para gerar os valores.\n", tamanho);
		system("pause>null");
		preenche(vetor, tamanho);
		printf("\nVetor gerado, esse vetor será usado em todo e qualquer algoritmo de ordenação até o fim desta execução.");
		bool loop = true;
		while (loop == true)
		{
			int opcao;
			printf("\nOpções: ");
			printf("\n1 - Ordenar o método com todos os algoritmos;  2 - Escolher um algoritmo individualmente \n");
			scanf("%d", &opcao);
			switch (opcao)
			{
			case 1:
				sortall(vetor, tamanho);
				loop = false;
				break;

			case 2:
			{
				bool voltar = true;
				do
				{
					int opcao_interna;
					printf("\n Opções de sort: ");
					printf("\n1 - Bubblesort;  2 - Mergesort;  3 - Quicksort;  4 - Voltar \n");
					scanf("%d", &opcao_interna);
					switch (opcao_interna)
					{
					case 1:
						bubble_result(vetor, tamanho);
						loop = false;
						break;

					case 2:
						merge_result(vetor, tamanho);
						loop = false;
						break;

					case 3:
						quick_result(vetor, tamanho);
						loop = false;
						break;

					case 4:
						break;

					default:
						printf("Escolha inválida.");
						voltar = false;
						break;
					}
				} while (voltar == false);
				break;
			}
			default:
				printf("Escolha inválida.\n");
				break;
			}
		}
		bool loop_externo = true;
		while (loop_externo == true)
		{
			printf("Deseja recomeçar gerando um novo vetor? Y/N\n");
			scanf("%s", &recomecar);
			switch (recomecar)
			{
			case 'Y':
			case 'y':
				system("cls");
				break;

			case 'N':
			case 'n':
				sair = true;
				break;

			default:
				printf("Escolha inválida.");
				loop_externo = true;
				break;
			}
		}
	}
	printf("\nPrograma encerrado.");
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	programa();

	return 0;
}
