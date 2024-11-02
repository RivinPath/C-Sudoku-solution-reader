#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "headers.h"

#include "shared.h"
#include "validation.h"

/*
 * AUTHOR: Rivin Pathirage
 * UNIT: Opareting System
 * PURPOSE: Validating the given sudoku solution
 * REFERENCES: 
 */

//PURPOSE: Validating a single row of the entire sudoku solution
int validate_row(int row_num, int (*sol)[GRID_SIZE]) 
{
    int row_valid = 1;
    int counts[GRID_SIZE + 1] = {0};

    for (int i = 0; i < GRID_SIZE; i++) 
    {
        int val = sol[row_num][i];
        if (val < 1 || val > GRID_SIZE || counts[val]++) 
        {
            row_valid = 0;
            break;
        }
    }

    return row_valid;
}

//PURPOSE: Validating a single column of the entire sudoku solution
int validate_col(int col_num, int (*sol)[GRID_SIZE]) 
{
    int col_valid = 1;
    int counts[GRID_SIZE + 1] = {0};

    for (int i = 0; i < GRID_SIZE; i++) 
    {
        int val = sol[i][col_num];
        if (val < 1 || val > GRID_SIZE || counts[val]++) 
        {
            col_valid = 0;
            break;
        }
    }

    return col_valid;
}

//PURPOSE: Validating a single sub grid of the entire sudoku solution
int validate_subgrid(int subgrid_num, int (*sol)[GRID_SIZE]) 
{
    int subgrid_valid = 1;
    int counts[GRID_SIZE + 1] = {0};
    int row_start = (subgrid_num / 3) * 3;
    int col_start = (subgrid_num % 3) * 3;

    for (int i = row_start; i < row_start + 3; i++) 
    {
        for (int j = col_start; j < col_start + 3; j++) 
        {
            int val = sol[i][j];

            

            if (val < 1 || val > GRID_SIZE || counts[val]++) 
            {
                subgrid_valid = 0;
                
            }

            
        }
    }

    return subgrid_valid;
}

//PURPOSE: Printing the validated results
void print_validation_results(int *row, int *col, int *sub, int counter) 
{
    printf("Thread ID-1: ");
    if (!row[0] || !row[1] || !row[2] || !sub[0] || !sub[1] || !sub[2]) 
    {
        if (!row[0]) printf("row 1, ");
        if (!row[1]) printf("row 2, ");
        if (!row[2]) printf("row 3, ");
        if (!sub[0]) printf("sub-grid 1, ");
        if (!sub[1]) printf("sub-grid 2, ");
        if (!sub[2]) printf("sub-grid 3, ");
        printf("are invalid\n");
    } 
    else 
    {
        printf("valid\n");
    }

    printf("Thread ID-2: ");
    if (!row[3] || !row[4] || !row[5] || !sub[3] || !sub[4] || !sub[5]) 
    {
        if (!row[3]) printf("row 4, ");
        if (!row[4]) printf("row 5, ");
        if (!row[5]) printf("row 6, ");
        if (!sub[3]) printf("sub-grid 4, ");
        if (!sub[4]) printf("sub-grid 5, ");
        if (!sub[5]) printf("sub-grid 6, ");
        printf("are invalid\n");
    } 
    else 
    {
        printf("valid\n");
    }

    printf("Thread ID-3: ");
    if (!row[6] || !row[7] || !row[8] || !sub[6] || !sub[7] || !sub[8]) 
    {
        if (!row[6]) printf("row 7, ");
        if (!row[7]) printf("row 8, ");
        if (!row[8]) printf("row 9, ");
        if (!sub[6]) printf("sub-grid 7, ");
        if (!sub[7]) printf("sub-grid 8, ");
        if (!sub[8]) printf("sub-grid 9, ");
        printf("are invalid\n");
    } 
    else 
    {
        printf("valid\n");
    }

    printf("Thread ID-4: ");
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        if (!col[i]) 
        {
            printf("column %d, ", i + 1);
        }
    }
    if (counter == GRID_SIZE * 3) 
    {
        printf("\nThere are %d valid sub-grids, and thus the solution is valid.\n", counter);
    } 
    else 
    {
        printf("\nThere are in total %d valid rows, columns, and sub-grids, and the solution is invalid.\n", counter);
    }
}