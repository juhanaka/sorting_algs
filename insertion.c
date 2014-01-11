//
//  insertion.c
//  Insertion_Sort
//
//  Created by Juhana Kangaspunta on 07/01/14.
//  Copyright (c) 2014 Juhana Kangaspunta. All rights reserved.
//

#include <stdio.h>

void insertionSort(int * array, int length);

void insertionSort(int * array, int length)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    
    //Loop from second element to last element. Unsorted part is right from i (including i):
    for( i=1; i<= length; i++)
    {
        j = i;
        //Get the first element of unsorted part. Loop left swapping adjacent variables with each other until
        //the moved element is no longer greater than the previous one:
        while(j >= 0 && array[j] < array[j-1])
        {
            tmp = array[j];
            array[j] = array[j-1];
            array[j-1] = tmp;
            j--;
        }
    }
}
