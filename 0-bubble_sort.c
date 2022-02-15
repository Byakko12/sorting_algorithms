#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int *first = NULL;
	int *second = NULL;
	int flag = 0;
	int tmp;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			first = &array[j];
			second = &array[j + 1];
			if (*first > *second)
			{
				tmp = *first;
				*first = *second;
				*second = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
