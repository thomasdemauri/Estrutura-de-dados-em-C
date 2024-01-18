#include <stdio.h>
#include <stdlib.h>

const int ROWS = 3;
const int COLS = 3;

int main(int argc, char const *argv[])
{

	int m[ROWS][COLS];

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; j++)
		{
			m[i][j] = 2 * j * i + 1;	// Random formula
			printf("%d ", m[i][j]);
		}
		puts("");
	}
	return 0;
}