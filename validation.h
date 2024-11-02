#ifndef VALIDATION_H
#define VALIDATION_H

int validate_row(int row_num, int (*sol)[GRID_SIZE]);
int validate_col(int col_num, int (*sol)[GRID_SIZE]);
int validate_subgrid(int subgrid_num, int (*sol)[GRID_SIZE]);
void print_validation_results(int *row, int *col, int *sub, int counter);

#endif