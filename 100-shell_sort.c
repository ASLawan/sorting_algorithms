#include "sort.h"
/**
 * sort_with_gap - sorts an array of integers using a combination
 * of shell sort algorithm and Knuth sequence
 * @arr: array to sort
 * @size: length of the array
 * @gap: gap to use for comparison
 * Return: nothing
 */
void sort_with_gap(int *arr, int size, int gap)
{
	int temp, i, j;

	for (i = 0; (i + gap) < size; i++)
	{
		for (j = i + gap; (j - gap) >= 0; j -= gap)
		{
			if (arr[j] < arr[j - gap])
			{
				temp = arr[j];
				arr[j] = arr[j - gap];
				arr[j - gap] = temp;
			}
		}
	}
	print_array(arr, size);
}
/**
 * shell_sort - sorts an array of integers using a combination
 * of shell sort algorithm and Knuth sequence
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}

	while ((gap = (gap - 1) / 3) > 0)
	{
		sort_with_gap(array, size, gap);
	}
}
