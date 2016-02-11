#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "guid.h"


/*Read GUID from file*/
int read_guid_from_file(guid *g, FILE * pf)
{
    if(fread(&(g->data_1), 4, 1, pf) != 1){
        free(g);
        return -1;
    }
    else if(fread(&(g->data_2), 2, 1, pf) != 1){
        free(g);
        return -1;
    }
    else if(fread(&(g->data_3), 2, 1, pf) != 1){
        free(g);
        return -1;
    }
    else if(fread(g->data_4, 8, 1, pf) != 1){
        free(g);
        return -1;
    }
    return 0;
}


/*Encode GUID as a string*/
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


/*Check if GUID matches a given value.*/
int guid_match(guid *g, uint32_t d1, uint16_t d2, uint16_t d3, uint64_t d4)
{
    if(g->data_1 != d1 || g->data_2 != d2 || g->data_3 != d3)
        return 0;
        
    uint64_t p4 = (uint64_t)g->data_4[0];
    int i;
    for(i=1; i<8; ++i){
        p4 = p4 << 8;
        p4 += (uint64_t)g->data_4[i];
    }
    
    if(p4 != d4)
        return 0;
    else
        return 1;
}


/*Get partition type based on GUID value.*/
char * get_guid_type(guid *g)
{
    char *type;
    if(guid_match(g, 0, 0, 0, 0))
        type = "Unused entry";
    else if(guid_match(g, 0xC12A7328, 0xF81F, 0x11D2, 0xBA4B00A0C93EC93B))
        type = "EFI System partition";
    else if(guid_match(g, 0xE3C9E316, 0x0B5C, 0x4DB8, 0x817DF92DF00215AE))
        type = "Microsoft Reserved Partition";
    else if(guid_match(g, 0xBFBFAFE7, 0xA34F, 0x448A, 0x9A5B6213EB736C22))
        type = "Lenovo boot partition";
    else if(guid_match(g, 0xDE94BBA4, 0x06D1, 0x4D40, 0xA16ABFD50179D6AC))
        type = "Windows Recovery Environment";
    else if(guid_match(g, 0xEBD0A0A2, 0xB9E5, 0x4433, 0x87C068B6B72699C7))
        type = "Basic data partition";
    else
        type = "Unkown type";
        
    return type;
}
