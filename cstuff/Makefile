all: listtest dequetest

List.o: List.c List.h
	clang -c List.c

Deque.o: Deque.c Deque.h
	clang -c Deque.c

listtest: listtest.c List.o
	clang -o listtest listtest.c List.o

dequetest: dequetest.c Deque.o
	clang -o dequetest dequetest.c Deque.o

clean:
	rm -rf *.o
	rm -rf listtest
	rm -rf dequetest
