#include <stdio.h>
#include <stdlib.h>

/*
	**pp_vector is a pointer of int pointers
	*pp_vector is the adress of the current int pointer
	**pp_vector is the containt of what the current int pointer
*/
void free_dynamic_memory(int **pp_vector)
{
	printf("Containt: %d  | Adress in heap: %p \n", **pp_vector, *pp_vector);
	free(*pp_vector);
	*pp_vector = NULL;
	return;
}

int main()
{
	int length = 4;
	int *v_dynamic = calloc(length, sizeof(int));

	for (int i = 0; i < length; ++i)
	{
		v_dynamic[i] += i * 2 + 1;
	}

	printf("Adress in heap: %d --> %p \n", *&v_dynamic[2], &v_dynamic[2]);

	free_dynamic_memory(&v_dynamic);

	printf("Adress base: %p \n", v_dynamic);

	return 0;
}