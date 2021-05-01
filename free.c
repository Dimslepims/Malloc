/*
** EPITECH PROJECT, 2021
** B_PSU_400_STG_4_1_malloc_dmitry_yakovlev
** File description:
** Created by dmitry,
*/

#include "malloc.h"
extern data_t base;

data_t fusion(data_t block)
{
    if (block->next && block->next->used == 0) {
        block->size += sizeof(struct data_s) + block->next->size;
        block->next = block->next->next;
        if (block->next)
            block->next->prev = block;
    }
    return block;
}

void free(void *ptr)
{
    data_t block;
    if (ptr == NULL)
        return;
    if (valid(ptr)) {
        block = get_block(ptr);
        block->used = 0;
        if (block->prev && block->prev->used == 0)
            block = fusion(block->prev);
        if (block->next && block->next->used == 0)
            block = fusion(block);
        else {
            if (block->prev)
                block = NULL;
        }
    }
}