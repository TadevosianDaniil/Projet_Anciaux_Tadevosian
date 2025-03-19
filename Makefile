CC = gcc
CFLAGS = -ggdb -Wall -Wno-unused-function -c
objets = ex1.o main_ex1.o

main : $(objets)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $<

%.o : %.c
	$(CC) $(CFLAGS) $<	

clean :
	rm -f projet *.o