#include "sort.h"

/**
 * partition - Partition
 * @array: Array
 * @start: start array
 * @end: End array
 * @size: Size
 *
 * Return: Partition
 */
int partition(int *array, int start, int end, size_t size)
{
	int *pivot = &array[end];
	int part_idx = start - 1;
	int i;
	int tmp;
	int *first = NULL;
	int *second = NULL;

	for (i = start ; i <= end - 1 ; i++)
	{
		first = &array[i];
		if (*first < *pivot)
		{
			part_idx++;
			second = &array[part_idx];
			if (*second != *first)
			{
				tmp = *first;
				*first = *second;
				*second = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[part_idx + 1] != array[end])
	{
		second = &array[part_idx + 1];
		tmp = *second;
		*second  = *pivot;
		*pivot = tmp;
		print_array(array, size);

	}
	return (part_idx + 1);
}

/**
 * quick - Quick
 * @array: Array
 * @start: start array
 * @end: End array
 * @size: Size
 *
 * Return: Nothing
 */
void quick(int *array, int start, int end, size_t size)
{

	int part_idx;

	if (start >= end)
		return;

	part_idx = partition(array, start, end, size);
	quick(array, start, part_idx - 1, size);
	quick(array, part_idx + 1, end, size);
}

/**
 * quick_sort - Quick sort
 * @array: Array
 * @size: Size
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick(array, 0, size - 1, size);
}
