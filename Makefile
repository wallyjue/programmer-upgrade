CC = gcc
#LD_LIBRARY_PATH = /usr/local/lib/
C_FLAGS= -g -O2 -Wall
# -lcunit -L$(LD_LIBRARY_PATH)

OBJ = main.o dlist.o darray.o

%.o: %.c
	$(CC) $(C_FLAGS) -c -o $@ $<

main: $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $@
	
clean:
	rm *.o;rm binary
