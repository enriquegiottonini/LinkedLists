#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FREE_COLLECTOR arr[100]
#define ITEMS_TO_FREE

/*  Implementation of a type safe, inmutable linked list using macros. */
#define DECL_LLIST(type)                                                       \
                                                                               \
    typedef struct llist llist;                                                \
                                                                               \
    struct llist                                                               \
    {                                                                          \
        type element;                                                          \
        llist *rest;                                                           \
    };                                                                         \
    /*                                                                         \
        Pre: none.                                                             \
        Post: a list with an element and a rest, or null if no available space \
              in heap.                                                         \
        O(1)                                                                   \
    */                                                                         \
    llist *cons(type element, llist *rest)                                     \
    {                                                                          \
        llist *new_llist = (llist *)malloc(sizeof(llist));                     \
        if (new_llist != NULL)                                                 \
        {                                                                      \
            new_llist->element = element;                                      \
            new_llist->rest = rest;                                            \
        }                                                                      \
                                                                               \
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
        else                                                                   \
            return 1 + length(list->rest);                                     \
    }                                                                          \
    /*                                                                         \
        Pre: none.                                                             \
        Post: a list from appending two lists argmuents.                       \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    llist *append(llist *list1, llist *list2)                                  \
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
        else                                                                   \
            return nth(list->rest, pos - 1);                                   \
    }                                                                          \
    /*                                                                         \
        Pre: 0 <= pos < lentgh(list), list is not null.                        \
        Post: a list with an element inserted at position specified.           \
        ejecución amortizada O(1)                                             \
    */                                                                         \
    llist *insert(llist *list, int pos, type element)                          \
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
    llist *remove(llist *list, int pos)                                        \
    {                                                                          \
        if (pos == 0)                                                          \
        {                                                                      \
            return list->rest;                                                 \
        }                                                                      \
        return cons(list->element, remove(list->rest, pos - 1));               \
    }

#endif