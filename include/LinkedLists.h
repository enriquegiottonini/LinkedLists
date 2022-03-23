#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

/*  Implementation of a type safe, inmutable linked list using macros. */
#define DECL_LLIST(type)                                                  \
                                                                          \
    typedef struct                                                        \
    {                                                                     \
        type element;                                                     \
        llist *rest;                                                      \
    } llist;                                                              \
                                                                          \
    llist *cons(type element, llist *rest)                                \
    {                                                                     \
        llist *new_llist = malloc(sizeof(llist));                         \
        \ new_llist->element = element;                                   \
        new_llist->rest = rest;                                           \
        return new_llist;                                                 \
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
    llist *insert(llist *list, int pos, type element)                     \
    {                                                                     \
        if (pos == 0)                                                     \
            return cons(list->element, list->rest);                       \
                                                                          \
        return cons(list->element, insert(list->rest, pos - 1, element)); \
        \                                                                 \
    }


#endif