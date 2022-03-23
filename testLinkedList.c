#include "LinkedLists.h"

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

/* Test cases for an integer Dynamic Array. */
DECL_LLIST(int)

// Aux
void printLlist(llist *list)
{
    if (list == NULL) {
        printf("[]\n");
        return;
    }
    printf("\n[ ");
    for (int i = 0; i < length(list); i++)
    {
        printf("%d ", nth(list, i));
    }
    printf("]\n");
}

bool getElement(void)
{
    llist *one = cons(1, NULL);
    llist *two_one = cons(2, one);
    printLlist(one);
    printLlist(two_one);
    
    check((nth(two_one, 0) == 2), "Expecting value at pos 0 to be 2.");
    check((nth(two_one, 1) == 1), "Expecting value at pos 1 to be 1.");
    
    free(one);
    free(two_one);
    return true;

fail:
    free(one);
    free(two_one);
    return false;
}

bool concatenate(void)
{
    llist *one = cons(1, NULL);
    llist *two = cons(2, NULL);
    llist *one_two = append(one, two);
    printLlist(one_two);
    check((nth(one_two, 0) == 1), "Expecting value at pos 0 to be 1.");
    check((nth(one_two, 1) == 2), "Expecting value at pos 1 to be 2.");

    free(one);
    free(two);
    free(one_two);
    return true;

fail:
    free(one);
    free(two);
    free(one_two);
    return false;
}

int main(void)
{
    //run_test(getElement);
    run_test(concatenate);
    return 0;
}