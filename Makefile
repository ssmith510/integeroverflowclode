all : main

test : main.o
	gcc -o main main.o 

test.o : main.c
	gcc -c main.c

clean :
	rm main *.o
