#include "sort.h"
/**
 * shell_sort - sorts an array of integers using a combination
 * of shell sort algorithm and Knuth sequence
 * @array: array to sort
 * @size: length of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, gap;

	gap = 1;
	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
				j -= gap;
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}
