/*
** EPITECH PROJECT, 2021
** B_PSU_400_STG_4_1_malloc_dmitry_yakovlev
** File description:
** Created by dmitry,
*/

#include <string.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    size_t align_size; data_t block; void *new_ptr;
    if (!ptr)
        return malloc(size);
    if (valid(ptr)) {
        align_size = power_of_two(sizeof(struct data_s) + size);
        block = get_block(ptr);
        if (block->size > align_size - sizeof(struct data_s)) {
            if (align_size - sizeof(struct data_s) < block->size)
                split(block, align_size);
        } else {
            new_ptr = malloc(size);
            if (!new_ptr)
                return NULL;
            memcpy(new_ptr, ptr, block->size);
            free(ptr);
            return new_ptr;
        } return ptr;
    } return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, (size * nmemb)));
}