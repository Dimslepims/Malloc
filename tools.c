/*
** EPITECH PROJECT, 2021
** B_PSU_400_STG_4_1_malloc_dmitry_yakovlev
** File description:
** Created by dmitry,
*/

#include "malloc.h"

size_t power_of_two(size_t nbr)
{
    size_t power = 1;

    while (power < nbr)
        power *= 2;
    return (power);
}

void split(data_t block, size_t size)
{
    data_t tmp = NULL;
    tmp = (data_t) ((char *)block + sizeof(struct data_s) + size);
    tmp->prev = block;
    tmp->next = block->next;
    tmp->size = block->size - size - sizeof(struct data_s);
    tmp->used = 0;
    block->next = tmp;
    block->size = size - sizeof(struct data_s);
}