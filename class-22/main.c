#include <stdio.h>
#include <stdlib.h>

const int ROWS = 3;
const int COLS = 4;
const int DEPTH = 2;

// Tentativa de matriz tridimensional
int main(int argc, char const *argv[])
{
	// [DEPTH][ROWS][COLS];
	int ***m = NULL;

	// Vetor de ponteiros triplos
	m = (int ***) calloc(DEPTH, sizeof(int **));

	// Alocando vetor de ponteiros duplos em cada posicao do vetor de ponteiros triplos
	for (int i = 0; i < DEPTH; i++)
	{
		m[i] = (int **) calloc(ROWS, sizeof(int *));
	}

	// Alocando vetor de inteiros em cada ponteiro duplo
	for (int i = 0; i < DEPTH; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			m[i][j] = (int *) calloc(COLS, sizeof(int));
		}
	}


	printf("&m = %p (stack), m = %p (heap) \n\n", &m, m);

	for (int i = 0; i < DEPTH; i++)
	{
		printf("Depth -> &m[%d] = %p, m[%d] = %p \n", i, &m[i], i, m[i]);

		for (int j = 0; j < ROWS; j++)
		{
			printf("	Row -> &m[%d][%d] = %p, m[%d][%d] = %p \n", i, j, &m[i][j], i, j, m[i][j]);

			for (int k = 0; k < COLS; k++)
			{
				printf("		Column -> &m[%d][%d][%d] = %p, m[%d][%d][%d] = %d \n", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);
			}
		}

		puts("");
	}


	// Apenas exemplo mostrando o acesso a um tunel dentro desse cubo tridimensional
	for (int i = 0; i < DEPTH; i++)
	{
		printf("%d \n", m[i][2][3]);
	}

	puts("");

	return 0;
}