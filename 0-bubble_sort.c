#include "sort.h"
/**
 * bubble_sort -  sorts array using bubble sort algorithm
 * @array: - array to be sorted
 * @size: - length of the array to be sorted
 * Return: sorted array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
