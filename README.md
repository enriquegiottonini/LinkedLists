# DynamicArrays
Pequeña biblioteca de listas ligadas genéricas, inmutables y persistentes con implementación recursiva de tiempo de ejecución amortizado O(1).
Implementación de Colas y de Pilas usando listas ligadas.

## Autor
Enrique Alejandro Giottonini Herrera.
Estructura de Datos.
LCC.

## Descripción
El projecto incluye dos folders:
    - include, para los headers.
    - src, para el código fuente.

Las listas ligadas fueron diseñadas con el enfoque de que las listas son NULL ó una cosa con un elemento y otra cosa. Las inicializo con una función constructor que reserva memoría con malloc.

Por el hecho de que las listas son inmutables, cualquier operación que le haga a una lista generara otra nueva, por lo tanto para llevar un registro de los mallocs que tengo que liberar al final de ejecutar el programa se utilizó un arreglo global que fuera guardando todas las direcciones donde se reservó memoría.

Implementar Colas y Pilas con listas ligadas fue más sencillo de lo que esperaba. Para las pilas solo se van insertando y eliminando los elementos en la cabeza. Para las colas dejé en la posición 0 a la tail y solo la head se va moviendo.


### Ejecutar el programa
Se utiliza GNU Makefile donde:

    make,
    make all: Genera todas los ejecutables de las pruebas.

    Para las prueba de cada implementación.
    make testLlist.
    make testQueue.
    make testStack.

    Para limpiar los ejecutables:
    make clean.