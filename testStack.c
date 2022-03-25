#include "Stack.h"

/*
  Cortesía de nuestro querido maestro de Estructura de Datos:
  Prof. Eduardo Acuña.

  Macros para organizar pruebas.

  Las pruebas se escriben con check(expresión, mensaje), una prueba
  pasa cuando la expresión tiene valor verdadero y falla cuando tiene
  valor falso, en cuyo caso se imprime el mensaje como error.

  Las pruebas se agrupan en funciones de cero argumentos que regresan
  un booleano, si alguna de las pruebas falla esta función debe
  regresar falso, si todas pasan debe regresar verdadero.

  Dentro de estas funciones, utiliza una etiqueta fail para
  identificar el código que libera recursos (como la memoria) cuando
  una prueba falla.
 */
#define run_test(test)                             \
    do                                             \
    {                                              \
        fprintf(stderr, "* Testing " #test "..."); \
        bool ok = test();                          \
        if (!ok)                                   \
            return -1;                             \
        fprintf(stderr, "ok\n");                   \
    } while (0)

#define check(expr, message)                             \
    if (!(expr))                                         \
    {                                                    \
        fprintf(stderr, "\nError (%s:%d) " message "\n", \
                __FILE__, __LINE__);                     \
        goto fail;                                       \
    }

bool empty(void)
{
    Stack *stack = init_stack();
    //printStack(stack);
    check(stack != NULL, "Expecting enough memory.");
    check(empty_stack(stack), "Expecting an empty stack.")
    
    free(stack);
    free_stacks();
    return true;
fail:
    if(stack != NULL)
        free(stack);
    free_stacks();
    return false;
}

bool pushing(void)
{
    Stack *stack = init_stack();
    //printStack(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    check((peek(stack) == 3), "Expecting top element to be 3.");
    check((size_stack(stack) == 3), "Expecting size to be 3");
    //printStack(stack);

    free(stack);
    free_stacks();
    return true;
fail:
    if(stack != NULL)
        free(stack);
    free_stacks();
    return false;
}
 
bool popping(void)
{
    Stack *stack = init_stack();
    check(stack != NULL, "Expecting enough memory.");
    check(empty_stack(stack), "Expecting an empty stack.");

    push(stack, 1);
    push(stack, 2); 
    push(stack, 3);
    check((pop(stack) == 3), "Expecting to pop 3.");

    check((peek(stack) == 2), "Expecting top element to be 2.");
    check((size_stack(stack) == 2), "Expecting size to be 2");
 
    check((pop(stack) == 2), "Expecting to pop 2.");
    check((pop(stack) == 1), "Expecting to pop 1.");
    check(empty_stack(stack), "Expecting an empty stack.")
    //printStack(stack);
    
    free(stack);
    free_stacks();
    return true; 
fail:
    if(stack != NULL)
        free(stack);
    free_stacks();
    return false;
}
int main(void)
{
    run_test(empty); 
    run_test(pushing);
    run_test(popping);
    return 0;
}