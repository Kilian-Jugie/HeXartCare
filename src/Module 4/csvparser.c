#include <stdio.h>
#include <stdlib.h>
#include "csvparser.h"

void freeCSVFile(CSVfile* f) {
	freechain(f->data);
	free(f->data);
	free(f);
}

CSVfile*readCSV(char*filename, CSVfile *ret)
{
    FILE* f = fopen(filename, "r");
	if (!f) return NULL;

    if (!ret)
    {
        ret = malloc(sizeof(CSVfile));
        ret->size = 0;
        ret->data = malloc(sizeof(Data));
		ret->data->pulsenb =0;
		ret->data->time = 0;

    }

    while (!feof(f))
    {
        char result[100];
        fgets(result,100,f);
		int converted = atoi(result);
		if (!converted) return ret;
        Data*newcase = malloc(sizeof(Data));
        newcase->pulsenb=0;
        newcase->nxt=NULL;
        Data*lastcase=accessdata(ret->size,ret->data);
        ret->size++;
        lastcase->nxt=newcase;
        
        newcase->pulsenb = converted;
		newcase->time = ret->size;
    }
	fclose(f);
	return ret;
}

Data *accessdata (int n, Data*chainlist)
{
    if (!n)
    {
        return chainlist;
    }
    else
    {
        return accessdata (n-1,chainlist->nxt);
    }

}
void freechain(Data*chain)
{
    if (chain->nxt==NULL)
    {
        return;
    }
    freechain(chain->nxt);
    free(chain->nxt);
}
