#ifndef GUID_H
#define GUID_H

#include <stdio.h>
#include <stdint.h>

#define BYTES_OF_GUID 128
#define LENGTH_OF_GUID_STRING 36

typedef struct{
    uint32_t data_1;
    uint16_t data_2;
    uint16_t data_3;
    uint8_t data_4[8];
}guid;

/*Read GUID from file*/
int read_guid_from_file(guid *g, FILE *pf);

/*Encode GUID as a string*/
int guid_encode(char *s, guid *g);


/*Check if GUID matches a given value.*/
int guid_match(guid *, uint32_t, uint16_t, uint16_t, uint64_t);


/*Get partition type based on GUID value.*/
char * check_guid_type(guid *);

#endif
