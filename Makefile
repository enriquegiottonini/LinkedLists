CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

testLlist.o: testLinkedList.c include/LinkedLists.h
	$(CC) $(CFLAGS) -o $@ $<

testLlist: testLlist.o
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./$<

cleanLlist:
	rm testLlist.o

testStack.o: testStack.c include/Stack.h
	$(CC) $(CFLAGS) $< src/Stack.c -o $@

testStack: testStack.o
	valgrind --quiet --leak-check=yes ./$<

cleanStack:
	rm testStack.o