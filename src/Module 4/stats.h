#ifndef _STATS_H_
#define _STATS_H_
struct CSVfile;
struct Data;

void dispFileData(struct CSVfile* d);
struct CSVfile* sortMax(struct CSVfile* d, int comparatorMode);
struct CSVfile* sortMin(struct CSVfile* d, int comparatorMode);
void dispOnTimePeriod(struct CSVfile* f, int tmin, int tmax);
int getAverageOnTimePeriod(struct CSVfile* f, int tmin, int tmax);
int getLineNumber(struct CSVfile* f);
int chainMax(struct CSVfile* f);
int chainMin(struct CSVfile* f);


#endif
