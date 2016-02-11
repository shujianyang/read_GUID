#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

int main(int argc, char *argv[])
{
    FILE * pfile;
    
    if(argc == 1)
        pfile = fopen("GPT.dd", "r");
    else
        pfile = fopen(argv[1], "r");
    
    if(pfile != NULL){
        while(!feof(pfile)){
            guid * g = (guid*)malloc(sizeof(guid));
            int err = read_guid_from_file(g, pfile);
            
            if(err){
                /*printf("Error while reading GUID from file.\n");*/
                break;
            }
                        
            char *s = (char*)malloc(LENGTH_OF_GUID);
            guid_encode(s, g);
            printf("%s %s\n", s, get_guid_type(g));
            
            free(s);
            free(g);
        }
        
        fclose(pfile);
    }
    
    return 0;
}
