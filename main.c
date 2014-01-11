//
//  main.c
//  Insertion_Sort
//
//  Created by Juhana Kangaspunta on 06/01/14.
//  Copyright (c) 2014 Juhana Kangaspunta. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int * getArray(char * filename, int lines)
{
    int num = 0, i = 0;
    FILE *file = fopen(filename, "r");
    
    int * array = malloc(lines * sizeof(int));
    
    while(fscanf(file, "%d", &num) == 1)
    {
        array[i] = num;
        i++;
    }
    fclose(file);
    return array;
}

int getFileSize(char * filename)
{
    int ch = 0, lines = 0;
    FILE *file = fopen(filename, "r");

    do {
        ch = fgetc(file);
        if(ch == '\n')
            lines++;
    } while (ch != EOF);
    fclose(file);

    return lines;
}


int main(int argc, const char * argv[])
{
    clock_t begin, end;
    double timeSpent;
    int lines = 0, i = 0, test = 0;
    char fileName[40];
    char algorithm[20];
    char yesOrNo;
    int * array;
    
    printf("Enter filename (file must be a .txt file with one integer in each row):\n");
    scanf("%39s", fileName);
    fpurge(stdin);
    
    lines = getFileSize(fileName);
    array = getArray(fileName, lines);
    for(i=0; i<lines+1; i++)
        test = array[i];
    
    printf("Enter sorting algorithm. \nAvailable algorithms: INSERTION, MERGE, SELECTION, QUICK\n");
    scanf("%19s", algorithm);
    fpurge(stdin);
    
    printf("Do you want to print the results to stdout? (y/n)\n");
    scanf("%c", &yesOrNo);
    begin = clock();
    
    if(strcmp(algorithm, "INSERTION") == 0)
        insertionSort(array, lines);
    
    if(strcmp(algorithm, "MERGE") == 0)
        mergeSort(array, 0, lines);

    if(strcmp(algorithm, "SELECTION") == 0)
        selection(array, lines);
    
    if(strcmp(algorithm, "QUICK") == 0)
        quickSort(array, 0, lines);
    
    end = clock();
    timeSpent = (double)(end-begin) / CLOCKS_PER_SEC;
    
    printf("Finished sorting a list of %d integers. Time spent: %f seconds.\n", lines+1, timeSpent);
    
    if (yesOrNo == 'y' || yesOrNo == 'Y')
    {
        for(i=0; i <= lines; i++)
         printf("%d, ", array[i]);
    }
    
    return 0;
}

