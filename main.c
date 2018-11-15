#include "./header_files/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void unip_header();
void menu();

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	unip_header();
	menu();
	return 0;
}

void unip_header(){
	printf("\n _   _  _   _  _  ____\n| | | || \\ | ||	||    |\n| |_| ||  \\| || ||  __|\n|_____||_|\\__||_||_|");
	printf("\nCIÊNCIA DA COMPUTAÇÃO\nAPS 2018 - 4ºSEMESTRE\n ");
}

void menu()
{
	char recomecar;
	bool sair = false;
	while (sair == false)
	{
		printf("\n*** Programa de algoritmos de ordenação ***\n");
		printf("Insira o tamanho do vetor a ser gerado: ");

		int tamanho = 0;
		scanf("%d", &tamanho);
		int vetor[tamanho];

		printf("Vetor com %d números. Pressione enter para gerar os valores.\n", tamanho);
		system("pause>null");

		preenche(vetor, tamanho);
		printf("\nVetor gerado, esse vetor será usado em todo e qualquer algoritmo de ordenação até o fim desta execução.");

		bool first_loop = true;
		while (first_loop == true)
		{
			int opcao;
			printf("\nOpções: ");
			printf("\n1 - Ordenar o método com todos os algoritmos\n2 - Escolher um algoritmo individualmente \n3 - Recomeçar/Fechar\n");
			scanf("%d", &opcao);
			switch (opcao)
			{
				case 1:
					sortall(vetor, tamanho);
					break;
				case 2:
				{
					bool voltar = false;
					while (voltar == false)
					{
						int opcao_interna;
						printf("\n Opções de sort: ");
						printf("\n1 - Bubblesort \n2 - Mergesort \n3 - Quicksort \n4 - Voltar \n");
						scanf("%d", &opcao_interna);
						switch (opcao_interna)
						{
						case 1:
							bubble_result(vetor, tamanho);
							break;
						case 2:
							merge_result(vetor, tamanho);
							break;
						case 3:
							quick_result(vetor, tamanho);
							break;
						case 4:
							voltar = true;
							break;
						default:
							printf("Escolha inválida.\n");
							break;
						}
					}
					break;
				}
				case 3:
					first_loop = false;
					break;
				default:
					printf("Escolha inválida.\n");
					break;
				}
			}
			bool restart_loop = true;
			while (restart_loop == true)
			{
				restart_loop = false;
				printf("Você Deseja: \n1 - Recomeçar gerando um novo vetor \n2 - Sair do programa\n");
				scanf("%s", &recomecar);
				switch (recomecar)
				{
					case '1':
						system("cls");
						first_loop = true;
						break;
					case '2':
						first_loop = false;
						sair = true;
						break;
					default:
						printf("Escolha inválida.\n");
						restart_loop = true;
						break;
				}
			}
		}
	printf("\n***Programa encerrado***.");
	void unip_header();
}
