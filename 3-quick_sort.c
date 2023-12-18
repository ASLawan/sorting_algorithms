#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - separates an array into sub-arrays
 * @arr: array to partition
 * @l: lower bound
 * @h: upper bound
 * @size: length of array
 * Return: nothing
 */
void partition(int *arr, int l, int h, int size)
{
	int pvt, pvt_idx, i;

	if (l < h)
	{
		pvt = h;
		pvt_idx = l;
		for (i = l; i < h; i++)
		{
			if (arr[i] < arr[pvt])
			{
				if (i != pvt_idx)
				{
					swap(&arr[i], &arr[pvt_idx]);
					print_array(arr, size);
				}
				pvt_idx++;
			}
		}

		if (pvt_idx != pvt && arr[pvt_idx] != arr[pvt])
		{
			swap(&arr[pvt_idx], &arr[pvt]);
			print_array(arr, size);
		}
		partition(arr, l, pvt_idx - 1, size);
		partition(arr, pvt_idx + 1, h, size);
	}

}
/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @size: length of the array to be sorted
 * Return: sorted array
 */

void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}
