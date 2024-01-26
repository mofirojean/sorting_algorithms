#include "sort.h"

/**
 * selection_sort - Implementation of selection sort
 * @array: Array to be sorted
 * @size: Size of array
 *
 * Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, smallest;
	int tmp;

	for (i = 0; i < size; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
			if (array[smallest] > array[j])
				smallest = j;
		if (array[smallest] != array[i])
		{
			tmp = array[smallest];
			array[smallest] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
	}
}
