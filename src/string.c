#include "calgostr/string.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char* trim(const char* str)
{
    if (str == NULL) return NULL;

    size_t str_index = 0;
    size_t str_len = strlen(str);
    bool can_be_space = false;
    char* str_temp = calloc(str_len + 1, sizeof(char));

    for (size_t i = 0; i < str_len; i++)
    {
        if (!isspace((unsigned char)str[i]))
        {
            str_temp[str_index++] = str[i];
            can_be_space = true;
        }
        else if (isspace((unsigned char)str[i]) && can_be_space)
        {
            str_temp[str_index++] = ' ';
            can_be_space = false;
        }
    }

    printf("str_index: %ld\n", str_index);

    if (str_index > 0 && isspace((unsigned char)str_temp[str_index - 1])) str_index--;

    char* result = calloc(str_index + 1, sizeof(char));

    printf("str_index: %ld\n", str_index);
    printf("str_temp: %ld\n", strlen(str_temp));
    printf("str_temp: %sFIM\n", str_temp);

    strncpy(result, str_temp, str_index);

    printf("result: %ld\n", strlen(result));
    printf("result: %sFIM\n", result);

    free(str_temp);

    return result;
}
