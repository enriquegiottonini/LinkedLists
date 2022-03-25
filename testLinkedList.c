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

bool deleting(void)
{
    llist *nums = cons(1, cons(2, cons(3, cons(4, NULL))));
    //printLlist(nums);
    check((length(nums) == 4), "Expecting to have 4 elements.");

    llist *palindrome = cons(4, cons(3, cons(2, cons(1, nums))));
    //printLlist(palindrome);
    check((length(palindrome) == 8), "Expecting to have 8 elements.");

    empty_register();
    return true;

fail:
    empty_register();
    return false;

}

bool getElement(void)
{
    llist *one = cons(1, NULL);
    llist *two_one = cons(2, one);
    //printLlist(one);
    //printLlist(two_one);
    
    check((nth(two_one, 0) == 2), "Expecting value at pos 0 to be 2.");
    check((nth(two_one, 1) == 1), "Expecting value at pos 1 to be 1.");

    empty_register();
    return true;

fail:
    empty_register();
    return false;
}

bool appending(void)
{
    llist *one = cons(1, NULL);
    llist *two = cons(2, NULL);
    llist *one_two = append(one, two);
    //printLlist(one_two);
    check((nth(one_two, 0) == 1), "Expecting value at pos 0 to be 1.");
    check((nth(one_two, 1) == 2), "Expecting value at pos 1 to be 2.");

    empty_register();
    return true;

fail:
    empty_register();
    return false;
}

bool inserting(void)
{
    llist *one = cons(1, NULL);
    llist *three = cons(3, NULL);
    llist *pair = append(one, three);

    llist *trio = insert(pair, 0, 2);
    check((nth(trio, 0) == 2), "Expecting an element 2 at pos 0.");
    //printLlist(trio);

    trio = insert(pair, 1, 2);
    check((nth(trio, 1) == 2), "Expecting an element 2 at pos 1.");
    //printLlist(trio);

    trio = insert(pair, 2, 2);
    check((nth(trio, 2) == 2), "Expecting an element 2 at pos 2.");
    //printLlist(trio);
    
    empty_register();
    return true;

fail:
    empty_register();
    return false;
}

bool ejecting(void)
{
    llist *one = cons(1, NULL);
    llist *two = cons(2, NULL);
    llist *three = cons(3, NULL);
    llist *seq = append(one, append(two, three));
    //printLlist(seq);

    llist *odd = eject(seq, 1);
    check((length(odd) == 2), "Expecting a size of two elements after ejecting.");
    //printLlist(odd);

    empty_register();
    return true;

fail:
    empty_register();
    return false;
}

int main(void)
{
    run_test(deleting);
    run_test(getElement);
    run_test(appending);
    run_test(inserting);
    run_test(ejecting);
    return 0;
}