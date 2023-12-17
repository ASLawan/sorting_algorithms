#include "sort.h"
/**
 * selection_sort - sorts an array base on selection sort algorithm
 * @array: array to be sorted
 * @size: length of array to be sorted
 * Return: sorted array in ascending order
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t minn;
	size_t temp;

	for (i = 0; i < size - 1; i++)
	{
		minn = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minn])
			{
				minn = j;
				continue;
			}
		}

		if (minn != i)
		{
			temp = array[i];
			array[i] = array[minn];
			array[minn] = temp;
			print_array(array, size);
		}
	}
}
