#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

void process_guid(FILE *pf);


int main(int argc, char *argv[])
{
    FILE * pfile;
    
    if(argc == 1){
        printf("Please enter file name: ");
        char filename[31];
        scanf("%30s", &filename);
        pfile = fopen(filename, "r");
        if(pfile != NULL){
            printf("%s:\n", filename);
            process_guid(pfile);
            fclose(pfile);
        }
        else
            printf("%s: File opening has failed.\n", filename);
        printf("==============================================\n");
    }
    else if(argc > 1){
        int i;
        for(i = 1; i < argc; ++i){
            pfile = fopen(argv[i], "r");
    
            if(pfile != NULL){
                printf("%s:\n", argv[i]);
                process_guid(pfile);
                fclose(pfile);
            }
            else
                printf("%s: File opening has failed.\n", argv[i]);
            printf("==============================================\n");
        }
    }
    
    return 0;
}


void process_guid(FILE *pfile)
{
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
}
