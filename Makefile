CC=gcc
C_FLAGS= -g -O2 -Wall

main: main.c
	$(CC) main.c $(C_FLAGS) -o binary
	
clean:
	rm *.o;rm binary
