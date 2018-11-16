#include <stdio.h>
#include <stdlib.h>

int choicemode () {
int choice;
printf ("Quel mode d'affichade souhaitez-vous choisir ?\n");
printf ("1: Mode 1\n");
printf ("2: Mode 2\n");
printf ("3: Mode 3\n");
printf ("4: Mode 4\n");
scanf ("%d", &choice);
return choice;


}
