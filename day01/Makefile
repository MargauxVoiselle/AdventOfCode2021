day01-1 : day01-1.o
	gcc -o day01-1 day01-1.o

day01-1.o : day01-1.c
	gcc -c day01-1.c

day01-2 : day01-2.o
	gcc -o day01-2 day01-2.o

day01-2.o : day01-2.c
	gcc -c day01-2.c

run1 : day01-1
	./day01-1

run2 : day01-2
	./day01-2

clean :
	rm -f day01-1 day01-2 *.o