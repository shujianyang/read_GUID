#ifndef GUID_H
#define GUID_H

typedef struct{
    uint8_t part_1[4];
    uint8_t part_2[2];
    uint8_t part_3[2];
    uint8_t part_4[8]
} guid;

#endif
