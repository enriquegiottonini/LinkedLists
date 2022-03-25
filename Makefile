CC=gcc
CFLAGS= -Wall -Wpedantic -Werror -g3 -Iinclude/

all: testLlist.o testStack.o testQueue.o

clean: cleanLlist cleanStack cleanQueue

testLlist.o: testLinkedList.c include/LinkedLists.h
	$(CC) $(CFLAGS) -o $@ $<

testStack.o: testStack.c include/Stack.h
	$(CC) $(CFLAGS) $< src/Stack.c -o $@

testQueue.o: testQueue.c include/Queue.h
	$(CC) $(CFLAGS) $< src/Queue.c -o $@

testLlist: testLlist.o
	valgrind --quiet --leak-check=yes ./$<

testStack: testStack.o
	valgrind --quiet --leak-check=yes ./$<

testQueue: testQueue.o
	valgrind --quiet --leak-check=yes ./$<

cleanLlist:
	rm testLlist.o

cleanStack:
	rm testStack.o

cleanQueue:
	rm testQueue.o