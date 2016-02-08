#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

int main()
{
    FILE * pfile;
    
    pfile = fopen("GPT.dd", "r");
    
    if(pfile != NULL){
        int n;
        guid * c = (guid*)malloc(sizeof(guid));
        for(n=0; n<15; ++n){
            fread(&(c->data_1), 4, 1, pfile);
            fread(&(c->data_2), 2, 1, pfile);
            fread(&(c->data_3), 2, 1, pfile);
            fread(c->data_4, 8, 1, pfile);
                        
            char *s = (char*)malloc(LENGTH_OF_GUID);
            guid_encode(s, c);
            printf("%s\n", s);
        }
        
        free(c);
        fclose(pfile);
    }
    
    return 0;
}
