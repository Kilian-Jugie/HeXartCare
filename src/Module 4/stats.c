#include "stats.h"
#include "csvparser.h"
#include <stdlib.h>
#include <stdio.h>

void _dispFileData(Data * d, int n) {
	printf("Il y a eu %d pulsation(s) a la seconde numero %d\n", d->pulsenb, d->time);
	if (!n) {
		return;
	}
	_dispFileData(d->nxt, n - 1);
}

void swap(Data *a, Data *b)
{
	int tempPulse = a->pulsenb;
	int tempTime = a->time;
	a->pulsenb = b->pulsenb;
	a->time = b->time;
	b->pulsenb = tempPulse;
	b->time = tempTime;
}

void dispFileData(CSVfile * d) {
	_dispFileData(d->data, d->size);
}

CSVfile* sortMax(CSVfile * d, int comparatorMode) {
	int swapped;
	Data *ptr1;
	Data *lptr = NULL;
	if (d == NULL)
		return d;
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
	return d;
}

CSVfile* sortMin(CSVfile * d, int comparatorMode) {
	int swapped;
	Data *ptr1;
	Data *lptr = NULL;
	if (d == NULL)
		return d;
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
	return _getAverageOnTimePeriod(d->nxt, tmin, tmax, n - 1, ct, size);
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
