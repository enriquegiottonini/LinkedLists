#include "Queue.h"

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
    Queue *queue = init_queue();
    //printQueue(queue);
    check(queue != NULL, "Expecting enough memoty.");
    check(empty_queue(queue), "Expecting an empty queue.");
    check((size_queue(queue) == 0), "Expecting 0 elements in queue.");

    free(queue);
    free_queues();
    return true;

fail:
    free(queue);
    free_queues();
    return false;
}

bool enqueing(void)
{
    Queue *queue = init_queue();
    check(queue != NULL, "Expecting enough memory.");
    
    check((enqueue(queue, 1) == 1), "Expecting to enqueue a 1.");
    check((front(queue) == 1), "Expecting element 1 at head.");
    check((back(queue) == 1), "Expecting element 1 at back.");
    check((size_queue(queue) == 1), "Expecting size of 1.");
    check(!empty_queue(queue), "Expecting not an empty queue.");
    //printQueue(queue);

    check((enqueue(queue, 2) == 2), "Expecting to enqueue a 2.");
    check((front(queue) == 1), "Expecting element 1 at head.");
    check((back(queue) == 2), "Expecting element 2 at tail.");
    //printQueue(queue);

    check((enqueue(queue, 3) == 3), "Expecting to enqueue a 3.");
    check((enqueue(queue, 4) == 4), "Expecting to enqueue a 4.");
    check((enqueue(queue, 5) == 5), "Expecting to enqueue a 5.");
    check((enqueue(queue, 6) == 6), "Expecting to enqueue a 6.");
    check((front(queue) == 1), "Expecting element 1 at head.");
    check((back(queue) == 6), "Expecting element 6 at tail.");
    check((size_queue(queue) == 6), "Expecting size of 1.");
    //printQueue(queue);

    free(queue);
    free_queues();
    return true;

fail:
    free(queue);
    free_queues();
    return false;
}

bool dequeing(void)
{
    Queue *queue = init_queue();
    check(queue != NULL, "Expecting enough memory.");

    check((enqueue(queue, 1) == 1), "Expecting to enqueue a 1.");
    check((dequeue(queue) == 1) , "Expecting to dequeue a 1."); 
    check(empty_queue(queue), "Expecting an empty queue.");

    check((enqueue(queue, 2) == 2), "Expecting to enqueue a 2.");
    check((enqueue(queue, 4) == 4), "Expecting to enqueue a 4.");
    check((enqueue(queue, 6) == 6), "Expecting to enqueue a 6.");
    check((enqueue(queue, 8) == 8), "Expecting to enqueue a 8.");
    //printQueue(queue);
    check((dequeue(queue) == 2), "Expecting to dequeue head two.");
    check((size_queue(queue) == 3), "Expecting size of 3.");
    check((front(queue) == 4), "Expecting element 4 at head.");
    check((back(queue) == 8), "Expecting element 8 at tail.");
    //printQueue(queue);
    check((enqueue(queue, 2) == 2), "Expecting to enqueue a 2.");
    check((dequeue(queue) == 4), "Expecting to dequeue head two.");
    check((front(queue) == 6), "Expecting element 4 at head.");
    check((back(queue) == 2), "Expecting element 2 at tail.");
    //printQueue(queue);
   
    free(queue);
    free_queues();
    return true;

fail:
    free(queue);
    free_queues();
    return false;
}

int main(void)
{
    run_test(empty);
    run_test(enqueing);
    run_test(dequeing);
    return 0;
}
