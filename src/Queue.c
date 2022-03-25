#include "Queue.h"

DECL_LLIST(llist, int)

struct Queue
{
    int head;
    int tail;
    llist *items;
};

Queue *init_queue(void)
{
    Queue *new_queue = malloc(sizeof(Queue));
    if (new_queue == NULL)
        return NULL;
    
    new_queue->head = -1;
    new_queue->tail = 0;
    new_queue->items = NULL;
    return new_queue;
}

bool empty_queue(Queue *queue)
{
    return (queue->head == -1);
}

int size_queue(Queue *queue)
{
    return length(queue->items);
}

int enqueue(Queue *queue, int element)
{
    queue->items = insert(queue->items, queue->tail, element);
    queue->head++;
    return nth(queue->items, queue->tail);
}

int dequeue(Queue *queue)
{
    int target = nth(queue->items, queue->head);
    queue->items = eject(queue->items, queue->head);
    queue->head--;
    return target;
}

int front(Queue *queue)
{
    return nth(queue->items, queue->head);
}

int back(Queue *queue)
{
    return nth(queue->items, queue->tail);
}

void printQueue(Queue *queue)
{
    if (queue->head == -1)
    {
        printf("[]\n");
        return;
    }
    printf("\n[ ");
    for (int i = 0; i <= queue->head; i++)
    {
        printf("%d ", nth(queue->items, i));
    }
    printf("]\n");
}

void free_queues(void)
{
    empty_register();
}