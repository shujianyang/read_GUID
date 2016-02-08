#ifndef GUID_H
#define GUID_H

#include <stdint.h>

typedef struct{
    uint32_t data_1;
    uint16_t data_2;
    uint16_t data_3;
    uint64_t data_4;
}guid;

#endif
