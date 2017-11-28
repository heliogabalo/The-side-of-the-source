/*unsupported*/
#include <stdio.h>

int fpurge(FILE *stream); // con retorno 0 / 1 error

/* supported */

#include <stdio.h>
#include <stdio_ext.h>

void __fpurge(FILE *stream); //sin valor de retorno
