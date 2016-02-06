#include <stdio.h>
#include <stdlib.h>
#include "guid.h"

int main()
{
    FILE * pfile;
    
    pfile = fopen("GPT.dd", "r");
    
    if(pfile != NULL){
        unsigned short int * c = (unsigned short int*)malloc(sizeof(unsigned short int));
        int i;
        fread(c, 2, 1, pfile);
        printf("%hx ", *c);
        if(*c == 0xbba4)
            printf("Yes");
        printf("\n");
        
        fclose(pfile);
    }
    
    return 0;
}