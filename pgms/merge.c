#include<stdio.h>

void merge_sort(int *arr, int n)
{
	if (n <= 1)
	{
        	return; 
	}


	// arr is indexed 0 through n-1, inclusive
	mid = floor(n/2)
    	first_half = merge_sort(arr, mid - 1);
    	second_half = merge_sort(arr + mid, n - mid])
    	return merge(first_half, second_half)
}

function merge(arr1, arr2)
{
    result = []
    while arr1.length() > 0 and arr2.length() > 0:
        if arr1[0] < arr2[0]:
            print '1' // for debugging
            result.append(arr1[0])
            arr1.remove_first()
        else:
            print '2' // for debugging
            result.append(arr2[0])
            arr2.remove_first()
            
    result.append(arr1)
    result.append(arr2)
    return result
