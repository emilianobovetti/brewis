#include "Helper.h"

void emptyString(char *str, uint8_t dim)
{
    uint8_t i;

    for (i = 0; i < dim; i++)
    {
        str[i] = '\0';
    }
}

void emptyGlobalBuffer(void)
{
    emptyString(globalBuffer, GLOBAL_STRING_BUFFER_SIZE);
}
