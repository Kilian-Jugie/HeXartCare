#ifndef CSVPARSER_H_INCLUDED
#define CSVPARSER_H_INCLUDED

typedef struct CSVfile CSVfile;
typedef struct Data Data;

struct CSVfile
{
    int size;
    Data *data;
};

struct Data
{
    Data *nxt;
	int pulsenb, time;
};

CSVfile*readCSV(char*filename, CSVfile *ret);
void freeCSVFile(CSVfile* f);

Data *accessdata (int n, Data*chainlist);

void freechain(Data*chain);
#endif // CSVPARSER_H_INCLUDED
