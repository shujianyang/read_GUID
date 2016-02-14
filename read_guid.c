#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

int main(int argc, char *argv[])
{
    FILE * pfile;
    
    if(argc == 1){
        printf("Please enter file name: ");
        char filename[31];
        scanf("%30s", &filename);
        pfile = fopen(filename, "r");
    }
    else if(argc == 2)
        pfile = fopen(argv[1], "r");
    else{
        printf("Error: Please provide 0 or 1 argument.\n");
        exit(1);
    }
    
    if(pfile != NULL){
        int count = 0;
        while(!feof(pfile)){
            guid * g = (guid*)malloc(sizeof(guid));
            int err = read_guid_from_file(g, pfile);
            
            if(err == -1){
                printf("Extra bytes less than GUID length left.\n");
                break;
            }
            else if(err){
                break;
            }
                        
            char *s = (char*)malloc(LENGTH_OF_GUID_STRING + 1);
            guid_encode(s, g);
            printf("%03d. %s %s\n", ++count, s, get_guid_type(g));
            
            free(s);
            free(g);
        }
        
        fclose(pfile);
    }
    else
        printf("File opening has failed.\n");
    
    return 0;
}
