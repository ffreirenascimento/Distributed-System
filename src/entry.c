#include <string.h>
#include <stdlib.h>

#include "../include/entry.h"

/* Function that creates an entry, reserving the necessary memory
* for the structure and initializing the fields 'key' and 'value'
* with the given parameters
*/  
struct entry_t *entry_create(char *key, struct data_t *data) {
    if (!key || !data) {
        return NULL;
    }

    struct entry_t *entry = (struct entry_t *) malloc(sizeof(struct entry_t));
    if (!entry) 
        return NULL;
    
    entry -> key = key;
    entry -> value = data;

    return entry;
}

/* Function that eliminates an entry, freeing the occupied memory
*/
void entry_destroy(struct entry_t *entry) {
    if (entry && entry -> key) {
        data_destroy(entry -> value);
        free(entry -> key);
        free(entry);
    }
}

/* Duplicates an entry
*/
struct entry_t *entry_dup(struct entry_t *entry) {
    if (!entry || !entry -> value) 
        return NULL;

    struct entry_t *entry_copy = (struct entry_t *)
    malloc(sizeof(entry));
    if (!entry_copy) {
        return NULL;
    }

    entry_copy -> key = strdup(entry -> key);
    if (!entry_copy -> key) {
        entry_destroy(entry);
        return NULL;
    }

    entry_copy -> value = data_dup(entry -> value);

    return entry_copy;
}

/* Substitutes the content of the entry given as a parameter.
*/
void entry_replace(struct entry_t *entry, char *new_key, 
struct data_t *new_value) {
    if (entry && new_key && new_value) {
        // free memory from previous fields
        if (entry -> key)
            free(entry -> key);
        if (entry -> value)
            data_destroy(entry -> value);

        // assign new pointers
        entry -> key = new_key;
        entry -> value = new_value;
    }
}

/* Compares two entries and returns their order.
* Entry order is defined by the keys.
* Returns 0 if equal,
*        -1 if entry1<entry2,
*         1 if entry1>entry2.
*/
int entry_compare(struct entry_t *entry1, struct entry_t *entry2) {
    if (!entry1 || !entry2) {
        return NULL;
    }
    return strcmp(entry1 -> key, entry2 -> key);
}

