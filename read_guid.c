#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

int main()
{
    FILE * pfile;
    
    pfile = fopen("GPT.dd", "r");
    
    if(pfile != NULL){
        guid * c = (guid*)malloc(sizeof(guid));
        
        fread(&(c->data_1), 4, 1, pfile);
        fread(&(c->data_2), 2, 1, pfile);
        fread(&(c->data_3), 2, 1, pfile);
        fread(c->data_4, 8, 1, pfile);
        
        printf("%08X-%04X-%04X-", c->data_1, c->data_2, c->data_3);
        
        uint8_t * part = c->data_4;
        printf("%02X", *part++);
        printf("%02X-", *part++);
        int i;
        for(i=0; i<6; ++i){
            printf("%02X", *part++);
        }
        
        printf("\n");
        
        fclose(pfile);
    }
    
    return 0;
}
