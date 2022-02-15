#include "sort.h"

/**
 * selection_sort - Selection sort
 * @array: Array
 * @size: Size
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int tmp;
	int *first = NULL;
	int *second = NULL;
	int min_idx = 0;
	int swap;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		min_idx = i;
		first = &array[i];
		for (j = i; j < size; j++)
		{
			second = &array[j];
			if (*second < *first)
			{
				min_idx = j;
				first = &array[min_idx];
				swap = 1;
			}
		}
		if (swap == 1)
		{
			first = &array[i];
			second = &array[min_idx];
			tmp = *first;
			*first = *second;
			*second = tmp;
			print_array(array, size);
		}
	}
}
