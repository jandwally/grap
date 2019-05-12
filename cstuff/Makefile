all: listtest dequetest digraphtest

List.o: List.c List.h
	clang -c List.c

Deque.o: Deque.c Deque.h
	clang -c Deque.c

Digraph.o: Digraph.c Digraph.h
	clang -c Digraph.c

listtest: listtest.c List.o
	clang -o listtest listtest.c List.o

dequetest: dequetest.c Deque.o
	clang -o dequetest dequetest.c Deque.o

digraphtest: digraphtest.c Digraph.o Deque.o
	clang -o digraphtest digraphtest.c Digraph.o Deque.o

clean:
	rm -rf *.o
	rm -rf listtest
	rm -rf dequetest
	rm -rf digraphtest
