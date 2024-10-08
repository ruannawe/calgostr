#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calgostr/string.h"

void test_trim(const char* input, const char* expected) {
    char* result = trim(input);
    if (result == NULL && expected == NULL) {
        printf("PASS: trim(\"%s\") returned NULL as expected.\n", input ? input : "NULL");
    } else if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        printf("PASS: trim(\"%s\") == \"%s\"\n", input, result);
    } else {
        printf("FAIL: trim(\"%s\") == \"%s\", expected \"%s\"\n", input ? input : "NULL", result ? result : "NULL", expected);
    }
    free(result);
}

int main() {
    printf("Running tests for trim function...\n");

    test_trim("   Hello World!   ", "Hello World!");
    test_trim("NoSpaces", "NoSpaces");
    test_trim("   Leading spaces", "Leading spaces");
    test_trim("Trailing spaces   ", "Trailing spaces");
    test_trim("   Both sides   ", "Both sides");
    test_trim("", "");
    test_trim("      ", "");
    test_trim(NULL, NULL); 

    return 0;
}
