#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*  Implementation of a type safe, inmutable linked list using macros. */
#define DECL_LLIST(type)                                                  \
                                                                          \
    typedef struct llist llist;                                           \
                                                                          \
    struct llist                                                          \
    {                                                                     \
        type element;                                                     \
        llist *rest;                                                      \
    };                                                                    \
                                                                          \
    llist *cons(type element, llist *rest)                                \
    {                                                                     \
        llist *new_llist = (llist *)malloc(sizeof(llist));                \
        new_llist->element = element;                                     \
        new_llist->rest = rest;                                           \
        return new_llist;                                                 \
    }                                                                     \
    int length(llist *list)                                               \
    {                                                                     \
        if (list == NULL)                                                 \
            return 0;                                                     \
        else                                                              \
            return 1 + length(list->rest);                                \
    }                                                                     \
    llist *append(llist *list1, llist *list2)                             \
    {                                                                     \
        if (list1 == NULL)                                                \
            return list2;                                                 \
        if (list2 == NULL)                                                \
            return list1;                                                 \
                                                                          \
        return cons(list1->element, append(list1->rest, list2));          \
    }                                                                     \
    type nth(llist *list, int pos)                                        \
    {                                                                     \
        if (pos == 0)                                                     \
            return list->element;                                         \
        else                                                              \
            return nth(list->rest, pos - 1);                              \
    }                                                                     \
    llist *insert(llist *list, int pos, type element)                     \
    {                                                                     \
        if (pos == 0)                                                     \
            return cons(list->element, list->rest);                       \
                                                                          \
        return cons(list->element, insert(list->rest, pos - 1, element)); \
    }

#endif