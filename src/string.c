#include "calgostr/string.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim(const char* str)
{
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len;

    while (start < len && isspace((unsigned char)str[start])) start++;
    if (start == len) {
        char* result = calloc(1, sizeof(char));
        if (result != NULL) result[0] = '\0';
        return result;
    }
    end = len - 1;
    while (end > start && isspace((unsigned char)str[end])) end--;
    
    size_t trimmed_length = end - start + 1;
    char* result = calloc(trimmed_length + 1, sizeof(char));
    if (result == NULL) return NULL;
    
    strncpy(result, str + start, trimmed_length);
    result[trimmed_length] = '\0';
    
    return result;
}
