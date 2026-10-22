nap-grep: nap-grep.o
	gcc nap-grep.o -o nap-grep	
nap-grep.o: ./src/main.c
	gcc -c ./src/main.c -o nap-grep.o

