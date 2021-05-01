/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include "malloc.h"

data_t base = NULL;

data_t max_heap(data_t *last, size_t size)
{
    void *ptr; data_t new; size_t page = getpagesize() * 2;
    while (page < size)
        page *= 2;
    if ((ptr = sbrk(page)) == (void *)-1)
        return (NULL);
    if (base == NULL) {
        base = ptr;
        base->next = NULL;
        base->prev = NULL;
        base->size = size - sizeof(struct data_s);
        base->used = 1;
        return base;
    } else {
        new = ptr;
        new->used = 1;
        new->next = NULL;
        new->prev = *last;
        new->size = size - sizeof(struct data_s);
        (*last)->next = new;
        return new;
    }
}

data_t get_block(void *ptr)
{
    char *tmp;
    tmp = ptr;
    return (ptr = tmp -= sizeof(struct data_s));
}

int valid(void *ptr)
{
    data_t tmp = base;
    while (tmp) {
        if (((char *)tmp + sizeof(struct data_s)) == ptr)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

data_t find(data_t *last, size_t size)
{
    data_t tmp = base;
    data_t save = NULL;
    while (tmp) {
        if (tmp->size >= size && tmp->used == 0 &&
        (save == NULL || save->size > tmp->size)) {
            save = tmp;
        }
        *last = tmp;
        tmp = tmp->next;
    }
    return save;
}

void *malloc(size_t size)
{
    data_t block = NULL;
    data_t last = NULL;
    size_t align_size = power_of_two(sizeof(struct data_s) + size);
    if (base) {
        last = base;
        block = find(&last, align_size);
        if (block) {
            if (block->size - (align_size - sizeof(struct data_s))
                > sizeof(struct data_s))
                split(block, align_size);
            block->used = 1;
        } else {
            block = max_heap(&last, align_size);
            if (!block)
                return NULL;
        }
    } else {
        block = max_heap(NULL, align_size);
        if (!block)
            return NULL;
        base = block;
    } return (block + 1);
}