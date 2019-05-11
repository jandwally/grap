all: listtest

List.o: List.c List.h
	clang -c List.c

listtest: listtest.c List.o
	clang -o listtest listtest.c List.o

clean:
	rm -rf *.o
	rm -rf listtest
