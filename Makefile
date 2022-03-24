CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

testLlist.o: testLinkedList.c include/LinkedLists.h
	$(CC) $(CFLAGS) -o $@ $<

testLlist: testLlist.o
	valgrind --quiet --leak-check=yes ./$<

cleanLlist:
	rm testLlist.o
