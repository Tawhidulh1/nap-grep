ng: nap-grep.o
	gcc ng.o search.o -o ng
	rm ng.o search.o
nap-grep.o: ./src/main.c search.o
	gcc -c ./src/main.c -o ng.o

search.o: ./src/search.c
	gcc -c ./src/search.c -o search.o

.PHONY: clean
clean:
	rm -f *.o ng
