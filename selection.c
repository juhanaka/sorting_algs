//
//  selection.c
//  Insertion_Sort
//
//  Created by Juhana Kangaspunta on 07/01/14.
//  Copyright (c) 2014 Juhana Kangaspunta. All rights reserved.
//

#include <stdio.h>

void selection(int * array, int last);

void selection(int * array, int last)
{
    int i, j, min, tmp;
    //Loop through array up until the second last element. Sorted part is left of i:
    for (i=0; i<=last-1; i++) {
        //Set minimum value to be the leftmost element of unsorted part:
        min = i;
        //Find the smallest element of the unsorted part:
        for (j=i+1; j<=last; j++) {
            if (array[j]<array[min]) {
                min = j;
            }
        }
        //Swap the smallest element of unsorted part with the first element of unsorted part.
        //The element added will now be in the sorted part.
        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}