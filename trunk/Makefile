CC = gcc
#LD_LIBRARY_PATH = /usr/local/lib/
C_FLAGS= -g -O2 -Wall
# -lcunit -L$(LD_LIBRARY_PATH)

main: main.c dlist.c darray.c
	$(CC) main.c dlist.c darray.c $(C_FLAGS) -o binary
	
clean:
	rm *.o;rm binary
