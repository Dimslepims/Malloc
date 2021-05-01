/*
** EPITECH PROJECT, 2021
** B-PSU-400-STG-4-1-malloc-dmitry.yakovlev
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_
#include <unistd.h>

typedef struct data_s {
    int used;
    size_t size;
    struct data_s *next;
    struct data_s *prev;
} *data_t;

void *malloc(size_t);
size_t power_of_two(size_t);
data_t max_heap(data_t *, size_t);
void split(data_t, size_t);
data_t get_block(void *);
void free(void *);
int valid(void *);
void copy_block(data_t, data_t);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
data_t fusion(data_t);
#endif /* !MALLOC_H_ */
