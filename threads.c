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
 * PURPOSE: Implementing and synchronizing the threads
 * REFERENCES: 
 */

//PURPOSE: Implementation of thread 1
void *thread_func_1(void *arg) 
{
    for (int i = 0; i < 3; i++) 
    {
        pthread_mutex_lock(&mutex);
        row[i] = validate_row(i, sol);
        sub[i] = validate_subgrid(i, sol);
        counter += row[i] + sub[i];
        pthread_mutex_unlock(&mutex);
        
    }
    sleep(delay);

    return NULL;
}

//PURPOSE: Implementation of thread 2
void *thread_func_2(void *arg) 
{
    for (int i = 3; i < 6; i++) 
    {
        pthread_mutex_lock(&mutex);
        row[i] = validate_row(i, sol);
        sub[i] = validate_subgrid(i + 3, sol);
        counter += row[i] + sub[i];
        pthread_mutex_unlock(&mutex);
        
    }
    sleep(delay);

    return NULL;
}

//PURPOSE: Implementation of thread 3
void *thread_func_3(void *arg) 
{
    for (int i = 6; i < 9; i++) 
    {
        pthread_mutex_lock(&mutex);
        row[i] = validate_row(i, sol);
        sub[i] = validate_subgrid(i, sol);
        counter += row[i] + sub[i];
        pthread_mutex_unlock(&mutex);
        
    }
    sleep(delay);

    return NULL;
}

//PURPOSE: Implementation of thread 4
void *thread_func_4(void *arg) 
{
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        pthread_mutex_lock(&mutex);
        col[i] = validate_col(i, sol);
        counter += col[i];
        pthread_mutex_unlock(&mutex);
        
    }
    sleep(delay);

    printf("Thread ID-4 is the last thread\n");
    pthread_cond_signal(&cond_var);

    return NULL;
}