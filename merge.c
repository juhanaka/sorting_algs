//
//  merge.c
//  Insertion_Sort
//
//  Created by Juhana Kangaspunta on 07/01/14.
//  Copyright (c) 2014 Juhana Kangaspunta. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int * array, int start, int end);
void merge(int * array, int start, int mid, int end);


void mergeSort(int * array, int start, int end)
{
    int mid = 0;
    //If array length == 1, consider array sorted:
    if(end - start < 1)
        return;
    //Calculate midpoint of array:
    mid = (end + start) / 2;
    //Recursively call mergesort to right and left partitions of the array:
    mergeSort(array, start, mid);
    mergeSort(array, mid+1, end);
    //Merge the sorted left and right partitions:
    merge(array, start, mid+1, end);
}

void merge(int * array, int start, int mid, int end)
{
    //Save starting index and midpoint:
    int saveStart = start;
    int saveMid = mid;
    //Declare and init other variables:
    int k = start;
    int i = 0;
    //Create new result array to store the sorted part:
    int * result = malloc((end - start + 1) * sizeof(int));
    //Loop through until result array is filled:
    for(i=0; i <= end-saveStart; i++)
    {
        //If there are elements left in both partitions, compare the elements and add smaller to result array:
        if(start < saveMid && mid <= end) {
            if(array[start] <= array[mid])
            {
                result[i] = array[start];
                start++;
            }
            else
            {
                result[i] = array[mid];
                mid++;
            }
        }
        //If there are only elements in left partition, add the first element to result array:
        else if (start < saveMid)
        {
            result[i] = array[start];
            start++;
        }
        //If there are only elements in right partition, add the first element to result array:
        else if (mid <= end)
        {
            result[i] = array[mid];
            mid++;
        }
    }
    //Copy result array to original array:
    for(k=saveStart; k <= end; k++)
        array[k] = result[k - saveStart];
    //Free the memory allocated to result array:
    free(result);
}