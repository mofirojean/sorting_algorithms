#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @size: Size of the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 *
 * Return: Index of the pivot element
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursion - Recursively sorts the array using Quick sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, high);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm with Lomuto partition scheme
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, size, 0, size - 1);
}
