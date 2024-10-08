#include <stdio.h>
#include <stdlib.h>
#include "calgostr/string.h"

int main() {
    char input[] = "   Calgo String Trim Example   ";
    printf("Original string: '%s'\n", input);

    char* trimmed = trim(input);
    if (trimmed != NULL) {
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed);
    } else {
        printf("Failed to trim the string.\n");
    }

    return 0;
}
