#include "Stack.h"

DECL_LLIST(llist, int)

struct Stack
{
    int top;
    llist *items;
};

Stack *init_stack(void)
{
    Stack *new_stack = malloc(sizeof(Stack));
    if (new_stack == NULL)
        return NULL;
    
    new_stack->top = 0;
    new_stack->items = NULL;
    return new_stack;
}

bool empty_stack(Stack *stack)
{
    return (stack->top == 0);
}

int size_stack(Stack *stack)
{
    return length(stack->items);
}

int push(Stack *stack, int element)
{
    stack->items = insert(stack->items, stack->top, element);
    stack->top++;
    return nth(stack->items, stack->top - 1);
}

int pop(Stack *stack)
{
    stack->top--;
    int target = nth(stack->items, stack->top);
    stack->items = eject(stack->items, stack->top);
    
    return target;
}

int peek(Stack *stack)
{
    return nth(stack->items, stack->top - 1);
}

void printStack(Stack *stack)
{
    if (stack->top == 0)
    {
        printf("[]\n");
        return;
    }
    printf("\n[ ");
    for (int i = 0; i < stack->top; i++)
    {
        printf("%d ", nth(stack->items, i));
    }
    printf("]\n");
}

void free_stacks(void)
{
    empty_register();
}