#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort
 * algorithm
 * @array: array of integers to sort
 * @size: number of integers in the array
 *
*/
void bubble_sort(int *array, size_t size)
{
	size_t i_index = 0, j_index = 0;
	int before = 0, after = 0;

	while (i_index < size)
	{
		j_index = 0;
		while (j_index < ((size - i_index)) - 1)
		{
			if (array[j_index] > array[j_index + 1])
			{
				before = array[j_index];
				after = array[j_index + 1];
				array[j_index] = after;
				array[j_index + 1] = before;
				print_array(array, size);
			}
			j_index++;
		}
		i_index++;
	}

}
