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

static void *xmalloc_fatal(size_t size)
{
    if (size==0)
        return NULL;
    fprintf(stderr, "Out of memory.");
    exit(1);
}
void *xmalloc (size_t size)
{
    void *ptr = malloc (size);
    if (ptr == NULL)
        return xmalloc_fatal(size);
    return ptr;
}

void *xcalloc (size_t nmemb, size_t size)
{
    void *ptr = calloc (nmemb, size);
    if (ptr == NULL) return xmalloc_fatal(nmemb*size);
    return ptr;
}