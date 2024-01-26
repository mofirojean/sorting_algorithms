#include "sort.h"


/**
 * bubble_sort - Bubble sorts an array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j = 0;
	int tmp;
	unsigned int sorted;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sorted = 1;
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				sorted = 0;
			}
		/* Checking if the array is already sorted */
		if (sorted)
			return;
	}
}
