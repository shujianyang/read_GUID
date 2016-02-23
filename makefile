P = read_guid

read_guid : read_guid.o guid.o
	gcc -o $(P) read_guid.o guid.o -Wall

read_guid.o : read_guid.c guid.h
	gcc -c read_guid.c

guid.o : guid.c guid.h
	gcc -c guid.c

clean :
	rm *.out 

