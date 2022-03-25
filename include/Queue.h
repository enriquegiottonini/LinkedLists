#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedLists.h"

typedef struct Queue Queue;

/*                                                                              
    Pre: none                                                                   
    Post: An empty queue. NULL if there is no space.                                        
    O(1)                                                   
*/
Queue *init_queue(void);
/*                                                                              
    Pre: a valid queue, not NULL.                                                                  
    Post: true if is empty, false otherwise.                                         
    O(1)                                                  
*/
bool empty_queue(Queue *queue);
/*                                                                              
    Pre: a valid queue.                                                                   
    Post: size of the queue.                                      
    ejecución amortizada O(1)                                                   
*/
int size_queue(Queue *queue);
/*                                                                              
    Pre: valid stack.                                                                   
    Post: inserted element to the queue from the tail.                                         
    O(1)                                                   
*/
int enqueue(Queue *queue, int element);
/*                                                                              
    Pre: valid queue.                                                                   
    Post: ejected elements from the head of the queue.                                        
    ejecución amortizada O(1)                                                   
*/
int dequeue(Queue *queue);
/*                                                                              
    Pre: valid queue, not empty.                                                                   
    Post: returns the element at the head.                                       
    ejecución amortizada O(1)                                                   
*/
int front(Queue *queue);
/*                                                                              
    Pre: valid queue.                                                                   
    Post: returns the element at the tail.                                       
    O(1)                                                   
*/
int back(Queue *queue);
/*                                                                              
    Pre: none                                                                   
    Post: shows in console a representation of the queue.                                         
    O(n)                                                  
*/
void printQueue(Queue *queue);

/*                                                                              
    Pre: none                                                                   
    Post: delete all queues constructed over time.                                         
    ejecución amortizada O(1)                                                   
*/
void free_queues(void);

#endif