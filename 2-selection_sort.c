#include "sort.h"

/**
 *swap - swap two integers
 *
 * @n1: first integer
 * @n2: second integer
 * return: nothing
 */

void swap(int *n1, int *n2)
{
	int aux = *n1;
		*n1 = *n2;
		*n2 = aux;
}

/**
 * selection_sort - implements selection_sort algorithm
 * @array: pointer to array
 * @size: size to array
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
