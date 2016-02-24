P = read_guid
CFLAGS = -g -Wall

read_guid : read_guid.o guid.o
	gcc -o $(P) read_guid.o guid.o $(CFLAGS)

read_guid.o : read_guid.c guid.h
	gcc -c read_guid.c $(CFLAGS)

guid.o : guid.c guid.h
	gcc -c guid.c $(CFLAGS)

clean :
	rm *.out 

