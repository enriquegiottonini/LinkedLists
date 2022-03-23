CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

testLlist.o: testLinkedList.c include/DynamicArrays.h
	$(CC) $(CFLAGS) -o $@ $<

testLlist: testLlist.o
	valgrind --quiet --leak-check=yes ./$<

cleanDynarr:
	rm testLlist.o
