#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*  Implementation of a type safe, inmutable, persistent,
    recursive linked list using macros. */
#define DECL_LLIST(typename, type)                                                       \
                                                                               \
    typedef struct typename typename;                                                \
                                                                               \
    struct typename                                                               \
    {                                                                          \
        type element;                                                          \
        typename *rest;                                                           \
    };                                                                         \
                                                                               \
    typename *heap_register[1024];                                                \
    int register_size = 0;                                                     \
    /*                                                                         \
        Pre: none.                                                             \
        Post: a list with an element and a rest, or null if no available space \
              in heap.                                                         \
        O(1)                                                                   \
    */                                                                         \
    typename *cons(type element, llist *rest)                                     \
    {                                                                          \
        llist *new_llist = (llist *)malloc(sizeof(llist));                     \
        if (new_llist == NULL)                                                 \
            return NULL;                                                       \
                                                                               \
        new_llist->element = element;                                          \
        new_llist->rest = rest;                                                \
        heap_register[register_size] = new_llist;                              \
        register_size++;                                                       \
        return new_llist;                                                      \
    }                                                                          \
    /*                                                                         \
        Pre: none.                                                             \
        Post: number of elements in a list.                                    \
        O(1)                                                                   \
    */                                                                         \
    int length(llist *list)                                                    \
    {                                                                          \
        if (list == NULL)                                                      \
            return 0;                                                          \
                                                                               \
        return 1 + length(list->rest);                                         \
    }                                                                          \
    /*                                                                         \
        Pre: none.                                                             \
        Post: a list from appending two lists argmuents.                       \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    typename *append(llist *list1, llist *list2)                                  \
    {                                                                          \
        if (list1 == NULL)                                                     \
            return list2;                                                      \
        if (list2 == NULL)                                                     \
            return list1;                                                      \
                                                                               \
        return cons(list1->element, append(list1->rest, list2));               \
    }                                                                          \
    /*                                                                         \
        Pre: 0 <= pos < lentgh(list), list is not null.                        \
        Post: the element at position pos from the list.                       \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    type nth(llist *list, int pos)                                             \
    {                                                                          \
        if (pos == 0)                                                          \
            return list->element;                                              \
                                                                               \
        return nth(list->rest, pos - 1);                                       \
    }                                                                          \
    /*                                                                         \
        Pre: 0 <= pos < lentgh(list), list is not null.                        \
        Post: a list with an element inserted at position specified.           \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    typename *insert(llist *list, int pos, type element)                          \
    {                                                                          \
        if (pos == 0)                                                          \
            return cons(element, list);                                        \
                                                                               \
        return cons(list->element, insert(list->rest, pos - 1, element));      \
    }                                                                          \
    /*                                                                         \
        Pre: 0 <= pos < lentgh(list), list is not null.                        \
        Post: a list without the element at position specified.                \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    typename *eject(llist *list, int pos)                                         \
    {                                                                          \
        if (pos == 0)                                                          \
            return list->rest;                                                 \
                                                                               \
        return cons(list->element, eject(list->rest, pos - 1));                \
    }                                                                          \
    /*                                                                         \
        Pre: none.                                                             \
        Post: free all memory allocated with malloc for the construction       \
              of the lists.                                                    \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    void empty_register(void)                                                  \
    {                                                                          \
        register_size--;                                                       \
        while (register_size > 0)                                              \
        {                                                                      \
            if (heap_register[register_size] != NULL)                          \
                free(heap_register[register_size]);                            \
            register_size--;                                                   \
        }                                                                      \
        if (heap_register[register_size] != NULL)                              \
            free(heap_register[register_size]);                                \
    }

#endif