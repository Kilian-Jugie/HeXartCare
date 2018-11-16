#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "stats.h"
#include "generate.h"
#include "cinterface.h"

void menu(struct CSVfile* f) {
	for (;;) {
		int choicemenu;
		system("cls");
		printf("1> Choisir le mode de clignotement\n");
		printf("2> Afficher les donnees dans l ordre du fichier csv\n");
		printf("3> Afficher les donnees en ordre croissant\n");
		printf("4> Afficher les donnees en ordre decroissant\n");
		printf("5> Rechercher et afficher les donnees pour un temps particulier\n");
		printf("6> Afficher la moyenne de pouls dans une plage de temps donnee\n");
		printf("7> Afficher le nombre de lignes de donnees actuellement en memoire\n");
		printf("8> Rechercher et afficher les max/min de pouls (avecle temps associe)\n");
		printf("9> Sortir du menu\n");
		printf("10> Sortir du programme\n");
		scanf("%d", &choicemenu);

		switch (choicemenu) {
		case 1:
		{
			int choice = 0;
			while (choice < 1 || choice>4) {
				printf("\nChoisir le mode parmis les modes suivants: \n");
				printf("\t1> Suite de LEDs\n");
				printf("\t2> Suite de LEDs (1/2)\n");
				printf("\t3> Allumage de toutes les LEDs puis extinctions sucecssives\n");
				printf("\t4> Chennille de LEDs\n");
				scanf("%d", &choice);
				system("cls");
			}
			generateParam(choice);
		}
			break;
		case 2:
			dispFileData(f);
			system("pause");
			break;
		case 3:
		{
			int choice = -1;
			while (choice != 0 && choice != 1) {
				printf("\nTrier les donnees en fonction de quel parametre ?\n");
				printf("\t0> Le temps\n");
				printf("\t1> La valeur de la doonee\n");
				scanf("%d", &choice);
			}
			sortMax(f, choice);
		}
			break;
		case 4:
		{
			int choice = -1;
			while (choice != 0 && choice != 1) {
				printf("\nTrier les donnees en fonction de quel parametre ?\n");
				printf("\t0> Le temps\n");
				printf("\t1> La valeur de la doonee\n");
				scanf("%d", &choice);
			}
			sortMin(f, choice);
		}
			break;
		case 5:
		{
			int tmin = 0, tmax = 0;
			while (tmin <= 0 || tmax <= 0) {
				printf("\nEntrez le temps minimum\n");
				scanf("%d", &tmin);
				printf("Entrez le temps mamimum\n");
				scanf("%d", &tmax);
			}
			printf("\n");
			dispOnTimePeriod(f, tmin, tmax);
			system("pause");
		}
			break;
		case 6: {
			int tmin = 0, tmax = 0;
			while (tmin <= 0 || tmax <= 0) {
				printf("\nEntrez le temps minimum\n");
				scanf("%d", &tmin);
				printf("Entrez le temps mamimum\n");
				scanf("%d", &tmax);
			}
			printf("%d\n", getAverageOnTimePeriod(f, tmin, tmax));
			system("pause");
		}
			break;
		case 7:
			printf("Nombres de lignes de donnees en memoire: %d\n", getLineNumber(f));
			system("pause");
			break;
		case 8: {
			int choice = 0;
			while (choice < 1 || choice>2) {
				printf("\nChoisir le type de valeur recherch:\n");
				printf("\t1> Valeur maximale (BPM)\n");
				printf("\t2> Valeur minimale (BPM)\n");
				scanf("%d", &choice);
			}
			switch (choice) {
			case 1:
				printf("Valeur maximale en BPM trouvee: %d\n", chainMax(f));
				break;
			case 2:
				printf("Valeur minimale en BPM trouvee: %d\n", chainMin(f));
				break;
			}
			system("pause");
		}
			break;
		case 9:
			loop(f);
			break;
		case 10:
			freeAll(f);
			exit(0);
			break;
		default:
			printf("Erreur: %d n'est pas un choix valide\n", choicemenu);
			exit(1);
		}
		system("cls");
	}
}
