#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char* key;
    char* value;
}ht_item;

typedef struct
{
    int size;
    int count;
    ht_item** items;
}ht_hash_table;

