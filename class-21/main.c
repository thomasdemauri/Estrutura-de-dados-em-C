#include <stdio.h>
#include <stdlib.h>

const int ROWS = 3;
const int COLS = 3;

int main(int argc, char const *argv[])
{
	
	// Ponteiro para ponteiros de inteiros (vetor de ponteiros)
	int **m = (int **) calloc(ROWS, sizeof(int *));

	// Para cada ponteiro de inteiro alocado, alocar um vetor de inteiros
	for (int i = 0; i < ROWS; i++)
	{
		m[i] = (int *) calloc(COLS, sizeof(int));
	}

	// Exibe o endereco base e o valor do ponteiro duplo (m)
	printf("(**m) | &m = %p , m = %p \n", &m, m);

	puts("");

	// Exibe endereco de vetores e seus respectivos enderecos que estao apontando
	for (int i = 0; i < ROWS; i++)
	{
		printf("&m[%d] = %p , m[%d] = %p \n", i, &m[i], i, m[i]);
	}

	puts("");

	// Exibe a matriz inteira e os seus enderecos
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			m[i][j] = COLS * ROWS + 1 * j * i + 2 + i;	// Random formula
			printf("&m[%d][%d] = %p , m[%d][%d] = %d \n", i, j, &m[i][j], i, j, m[i][j]);
		}
	}

	puts("");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%d ", m[i][j]);
		}
		puts("");
	}

	puts("");

	return 0;
}