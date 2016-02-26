/** \file read_guid.c
  * Main function.
  */

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
        scanf("%30s", (char*)(&filename));
        pfile = fopen(filename, "r");
        printf("%s:\n", filename);
        if(pfile != NULL){
            process_guid(pfile);
            fclose(pfile);
        }
        else
            perror("File opening failed");
        printf("==============================================\n");
    }
    else if(argc > 1){
        int i;
        for(i = 1; i < argc; ++i){
            pfile = fopen(argv[i], "r");
            printf("%s:\n", argv[i]);
    
            if(pfile != NULL){
                process_guid(pfile);
                fclose(pfile);
            }
            else
                perror("File opening failed");
            printf("==============================================\n");
        }
    }
    
    return 0;
}


/**
  * Read GUIDs from a file and print partition types.
  *
  * \param pfile Pointer to input file.
  *
  * \return None.
  */
void process_guid(FILE *pfile)
{
    int count = 0;
    int empty_entries = 0;
    int not_empty = 0;
    while(!feof(pfile)){
        GUID * g = (GUID*)malloc(sizeof(GUID));
        int err = read_guid_from_file(g, pfile);
        
        if(err == -1){
            printf("Extra bytes less than GUID length left in file.\n");
            break;
        }
        else if(err){
            break;
        }
                    
        char *s = (char*)malloc(LENGTH_OF_GUID_STRING + 1);
        if(guid_encode(s, g)){
            if(empty_entries){
                printf("------------------%d Unused Entries------------------\n", empty_entries);
            }
            printf("%03d. %s %s\n", count, s, get_guid_type(g));
            ++not_empty;
            empty_entries = 0;
        }
        else
            empty_entries++;

        ++count;
        
        free(s);
        free(g);
    }
    if(empty_entries){
        printf("------------------%d Unused Entries------------------\n", empty_entries);
    }
    printf("Total:%d  Not empty:%d\n", count, not_empty);
}
