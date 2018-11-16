#ifndef _CINTERFACE_H_
#define _CINTERFACE_H_

struct CSVfile;

int cinterface();
void loop(struct CSVfile* f);
void freeAll(struct CSVfile* f);

#endif
