//
//  quick.c
//  Insertion_Sort
//
//  Created by Juhana Kangaspunta on 07/01/14.
//  Copyright (c) 2014 Juhana Kangaspunta. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int choosePivot(int first, int last);
int partition(int * array, int left, int right, int pivot);
void quickSort(int * array, int left, int right);

//Choose pivot value randomly between first and last.
int choosePivot(int first, int last)
{
    double scaled;
    srand((unsigned int)time(NULL));
    scaled = (double)rand()/RAND_MAX;
    return first + (int)round(scaled * (last-first +1));
}

//Partition the array so that elements left of pivot are <= pivot and elements right of pivot are > pivot:
int partition(int * array, int left, int right, int pivot)
{
    int pivotVal, tmp, storeLeft, i;
    
    //Swap pivot with end:
    pivotVal = array[pivot];
    tmp = array[right];
    array[right] = pivotVal;
    array[pivot] = tmp;
    
    //Create running index.
    storeLeft = left;
    
    for (i=left; i<right; i++)
    {
        if (array[i] <= pivotVal)
        {
            //Swap value less than pivot with value at running index.
            tmp = array[i];
            array[i] = array[storeLeft];
            array[storeLeft] = tmp;
            storeLeft++;
        }
    }
    //Swap pivot with value at running index.
    tmp = array[right];
    array[right] = array[storeLeft];
    array[storeLeft] = tmp;
    
    return storeLeft;
}

void quickSort(int * array, int left, int right)
{
    int pivotIndex;
    
    //If left == right, consider array sorted.
    if (left < right )
    {
        //Choose pivot with random function.
        pivotIndex = choosePivot(left, right);
        
        //Partition the array so that elements left of pivot are <= than pivot and elements right of pivot are > than pivot.
        pivotIndex = partition(array, left, right, pivotIndex);
        
        //Recursively apply quickSort to both partitions.
        quickSort(array, left, pivotIndex-1);
        quickSort(array, pivotIndex+1, right);
    }

}
