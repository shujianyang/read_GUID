#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "guid.h"

void guid_encode(char *buffer, guid *g)
{
    snprintf(buffer, LENGTH_OF_GUID, "%08X-%04X-%04X-", 
            g->data_1, g->data_2, g->data_3);
    
    char *append = (char*)malloc(4);
    uint8_t *part = g->data_4;
    snprintf(append, 4, "%02X", *part++);
    strcat(buffer, append);
    snprintf(append, 4, "%02X-", *part++);
    strcat(buffer, append);
    
    int i;
    for(i=0; i<6; ++i){
        snprintf(append, 4, "%02X", *part++);
        strcat(buffer, append);
    }
    
    free(append);
}