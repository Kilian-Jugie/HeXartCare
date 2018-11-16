#include <stdio.h>
#include <stdlib.h>

void generateParam (int choice)
{
    FILE* f = fopen("Arduino\\projet_coeur_de_led\\param.h", "w");
    fputs ("#ifndef _PARAM_h\n#define _PARAM_h\n", f);
    fputs ("#define choice ", f );

    char* buf = malloc(10);
    _itoa(choice, buf, 10);

    fputs(buf, f);

    fputs("\n#endif\n", f);

    free(buf);
    fclose(f);

}
