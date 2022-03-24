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
    printLlist(nums);
    check((length(nums) == 4), "Expecting to have 4 elements.");
    //check((delete(nums) == 2), "Expecting to delete 4 elements.");

    llist *palindrome = cons(4, cons(3, cons(2, cons(1, nums))));
    printLlist(palindrome);
    check((length(palindrome) == 8), "Expecting to have 8 elements.");
    /* check((delete(palindrome) == 8), "Expecting to delete 8 elements."); */
    empty_history();

    return true;

fail:
    return false;

}
bool getElement(void)
{
    llist *one = cons(1, NULL);
    llist *two_one = cons(2, one);
    printLlist(one);
    printLlist(two_one);
    
    check((nth(two_one, 0) == 2), "Expecting value at pos 0 to be 2.");
    check((nth(two_one, 1) == 1), "Expecting value at pos 1 to be 1.");

    //check((delete(two_one) == 2), "Expecting to delete 2 constructions.");
    return true;

fail:
   /*  if (two_one != NULL)
        delete(two_one);
    if (one != NULL)
        delete(one); */
    return false;
}

bool appending(void)
{
    llist *one = cons(1, NULL);
    llist *two = cons(2, NULL);
    llist *one_two = append(one, two);
    printLlist(one_two);
    check((nth(one_two, 0) == 1), "Expecting value at pos 0 to be 1.");
    check((nth(one_two, 1) == 2), "Expecting value at pos 1 to be 2.");

    //free(one);
    //free(two);
    //free(one_two);
    //check((delete(one_two) == 2), "Expecting to delete 2 constructions.");
    //check((delete(one) == 1), "Expecting to delete 1 construction.");
    //check((delete(two) == 1), "Expecting to delete 1 construction.");
    return true;

fail:
    /* if (one_two != NULL)
        delete(one_two);
    else if (one != NULL)
        delete(one);
    else if (two != NULL)
        delete(two); */
    return false;
}

bool inserting(void)
{
    llist *one = cons(1, NULL);
    llist *three = cons(3, NULL);
    llist *pair = append(one, three);
    llist *trio = insert(pair, 0, 2);
    printLlist(trio);
    /* free(trio); */

    trio = insert(pair, 1, 2);
    printLlist(trio);
    /* free(trio->rest); // Before trio
    free(trio); */

    trio = insert(pair, 2, 2);
    printLlist(trio);
    
   /*  free(one);
    free(three);
    free(pair);
    free(trio->rest->rest); // Before trio
    free(trio->rest);       // Before trio
    free(trio); */
    empty_history();
    return true;
}

bool ejecting(void)
{
    llist *one = cons(1, NULL);
    llist *two = cons(2, NULL);
    llist *three = cons(3, NULL);
    llist *seq = append(one, append(two, three));
    printLlist(seq);
    llist *odd = eject(seq, 1);
    printLlist(odd);
    return true;
}

int main(void)
{
    //run_test(deleting);
    //run_test(getElement);
    //run_test(appending);
    run_test(inserting);
    //run_test(ejecting);
    return 0;
}