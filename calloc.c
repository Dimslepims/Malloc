/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** malloc
*/

#include <memory.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t *new;
    size_t s4 = 0;
    new = malloc(nmemb * size);
    if (new) {
        s4 = power_of_two(nmemb * size);
        memset(new, 0, s4);
    }
    return (new);
}