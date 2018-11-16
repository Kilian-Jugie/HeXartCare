#include "cinterface.h"
#include <stdio.h>
#include <stdlib.h>
#include "csvparser.h"
#include "menu.h"
#include "stats.h"
#include <Windows.h>

int cinterface() {
	

	CSVfile*f = readCSV("Arduino\\pulsations.csv", NULL);
	if (!f) {
		printf("ERROR: Arduino\\pulsations.csv needed !\n");
		system("pause");
		return 1;
	}
	remove("Arduino\\pulsations.csv");
	menu(f);

	
	Sleep(1010);

	loop(f);

	freeAll(f);

	system("pause");
}

void loop(CSVfile* f) {
	printf("Capture de donnees en cours... Appuyez sur ESC pour ouvrir le menu...\n");
	while (!GetKeyState(VK_ESCAPE)) {
		readCSV("Arduino\\pulsations.csv", f);
		remove("Arduino\\pulsations.csv");
		Sleep(1000);
	}
	menu(f);
}

void freeAll(CSVfile* f) {
	freeCSVFile(f);
}