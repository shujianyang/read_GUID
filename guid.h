#ifndef GUID_H
#define GUID_H

#include <stdint.h>

#define BYTES_OF_GUID 128
#define LENGTH_OF_GUID 37

typedef struct{
    uint32_t data_1;
    uint16_t data_2;
    uint16_t data_3;
    uint8_t data_4[8];
}guid;

void guid_encode(char *s, guid *g);

#endif
