#include "sort.h"
/**
 * counting_sort - sorts an array of integers using
 * counting sort algorithm
 * @array: array to be sorted
 * @size: length of array
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int max, i, *count_arr, *sorted_arr;

	if (size < 2)
		return;
	/*Determine max value in the array*/
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/*Allocate memory*/
	count_arr = malloc(sizeof(int) * (max + 1));
	if (count_arr == NULL)
		return;
	/*initialize counting array with zeros*/
	for (i = 0; i <= max; i++)
		count_arr[i] = 0;
	/*Count occurrences of each element*/
	for (i = 0; i < (int)size; i++)
		++count_arr[array[i]];
	/*get the positions*/
	for (i = 1; i <= max; i++)
		count_arr[i] = count_arr[i] + count_arr[i - 1];
	print_array(count_arr, (max + 1));
	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];
	free(count_arr);
	free(sorted_arr);
}
