day03-1 : day03-1.o
	gcc -o day03-1 day03-1.o

day03-1.o : day03-1.c
	gcc -c day03-1.c

day03-2 : day03-2.o
	gcc -o day03-2 day03-2.o

day03-2.o : day03-2.c
	gcc -c day03-2.c

run1 : day03-1
	./day03-1

run2 : day03-2
	./day03-2

clean :
	rm -f day03-1 day03-2 result.txt copyResult.txt *.o