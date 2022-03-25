#ifndef STACK_H
#define STACK_H

#include "LinkedLists.h"

typedef struct Stack Stack;

/*                                                                              
    Pre: none                                                                   
    Post: An empty stack. NULL if there is no space.                                        
    O(1)                                                   
*/
Stack *init_stack(void);
/*                                                                              
    Pre: a valid stack, not NULL.                                                                  
    Post: true if is empty, false otherwise.                                         
    O(1)                                                  
*/
bool empty_stack(Stack *stack);
/*                                                                              
    Pre: a valid stack.                                                                   
    Post: size of the stack.                                      
    ejecución amortizada O(1)                                                   
*/
int size_stack(Stack *stack);
/*                                                                              
    Pre: valid stack.                                                                   
    Post: the stack has a new top element.                                         
    ejecución amortizada O(1)                                                   
*/
int push(Stack *stack, int element);
/*                                                                              
    Pre: valid stack.                                                                   
    Post: delete the top of the stack, returns the element.                                        
    ejecución amortizada O(1)                                                   
*/
int pop(Stack *stack);
/*                                                                              
    Pre: valid stack.                                                                   
    Post: returns the element at the top                                       
    ejecución amortizada O(1)                                                   
*/
int peek(Stack *stack);
/*                                                                              
    Pre: none                                                                   
    Post: shows in console a representation of the stack.                                         
    O(n)                                                  
*/
void printStack(Stack *stack);

/*                                                                              
    Pre: none                                                                   
    Post: delete all stacks constructed over time.                                         
    ejecución amortizada O(1)                                                   
*/
void free_stacks(void);

#endif