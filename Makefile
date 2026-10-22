ng: nap-grep.o
	gcc ng.o -o ng
	rm ng.o
nap-grep.o: ./src/main.c
	gcc -c ./src/main.c -o ng.o

.PHONY: clean
clean:
	rm -f *.o ng
