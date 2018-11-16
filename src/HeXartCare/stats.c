#include "stats.h"
#include "csvparser.h"
#include <stdlib.h>
#include <stdio.h>

void _dispFileData(Data * d, int n) {
	printf("Pusation nb %d at time %d\n", d->pulsenb, d->time);
	if (!n) {
		return;
	}
	_dispFileData(d->nxt, n - 1);
}

void swap(Data *a, Data *b)
{
	int temp = a->pulsenb;
	a->pulsenb = b->pulsenb;
	b->pulsenb = temp;
}

void dispFileData(CSVfile * d) {
	_dispFileData(d->data, d->size);
}

CSVfile* sortMax(CSVfile * d, int comparatorMode) {
	int swapped, i;
	Data *ptr1;
	Data *lptr = NULL;
	if (d == NULL)
		return;
	/*Data newD;
	newD.pulsenb = INT_MAX - 1;
	newD.time = INT_MAX - 1;
	newD.nxt = NULL;
	accessdata(d->size-1, d->data)->nxt = &newD;*/
	do
	{
		swapped = 0;
		ptr1 = d->data;

		while (ptr1->nxt)
		{
			if (comparatorMode==1 && (ptr1->pulsenb > ptr1->nxt->pulsenb)) {
				swap(ptr1, ptr1->nxt);
				swapped = 1;
			}
			else if (comparatorMode == 0 && ptr1->time > ptr1->nxt->time) {
				swap(ptr1, ptr1->nxt);
				swapped = 1;
			}
			ptr1 = ptr1->nxt;
		}
		lptr = ptr1;
	} while (swapped);
	//accessdata(d->size - 1, d->data)->nxt = NULL;
	//d->size--;
	return d;
}

CSVfile* sortMin(CSVfile * d, int comparatorMode) {
	int swapped, i;
	Data *ptr1;
	Data *lptr = NULL;
	if (d == NULL)
		return;
	/*Data newD;
	newD.pulsenb = 0;
	newD.time =0;
	newD.nxt = NULL;
	accessdata(d->size - 1, d->data)->nxt = &newD;*/
	do
	{
		swapped = 0;
		ptr1 = d->data;

		while (ptr1->nxt)
		{
			if (comparatorMode==1 && (ptr1->pulsenb < ptr1->nxt->pulsenb)) {
				swap(ptr1, ptr1->nxt);
				swapped = 1;
			}
			else if (comparatorMode==0&&ptr1->time < ptr1->nxt->time) {
				swap(ptr1, ptr1->nxt);
				swapped = 1;
			}
			ptr1 = ptr1->nxt;
		}
		lptr = ptr1;
	} while (swapped);
	//accessdata(d->size - 1, d->data)->nxt = NULL;
	//d->size--;
	return d;
}

void _dispOnTimePeriod(Data* d, int tmin, int tmax, int n) {
	if (!n)
		return;
	if (d->time >= tmin && d->time < tmax)
		printf("%d\n", d->pulsenb);
	_dispOnTimePeriod(d->nxt, tmin, tmax, n - 1);
}

void dispOnTimePeriod(CSVfile * f, int tmin, int tmax) {
	_dispOnTimePeriod(f->data, tmin, tmax, f->size);
}

int _getAverageOnTimePeriod(Data* d, int tmin, int tmax, int n, int ct, int size) {
	if (!n) {
		if (size != 0)
			return ct / size;
		else
			return 0;
	}
		
	if (d->time >= tmin && d->time < tmax) {
		ct += d->pulsenb;
		size++;
	}
	_getAverageOnTimePeriod(d->nxt, tmin, tmax, n - 1, ct, size);
}

int getAverageOnTimePeriod(CSVfile * f, int tmin, int tmax) {
	return _getAverageOnTimePeriod(f->data, tmin, tmax, f->size, 0, 0);
}

int getLineNumber(CSVfile * f) {
	return f->size;
}

int _max(Data * d, int n, int * max) {
	if (!n)
		return *max;
	if (d->pulsenb > *max)
		*max = d->pulsenb;
	return _max(d->nxt, n - 1, max);
}

int _min(Data * d, int n, int * min) {
	if (!n)
		return *min;
	if (d->pulsenb&&d->pulsenb < *min)
		*min = d->pulsenb;
	return _min(d->nxt, n - 1, min);
}

int chainMax(CSVfile * f) {
	int nbMax;
	return _max(f->data, f->size, &nbMax);
}

int chainMin(CSVfile * f) {
	int nbMin = INT_MAX - 10;
	return _min(f->data, f->size, &nbMin);
}
