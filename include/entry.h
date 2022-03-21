#ifndef _ENTRY_H
#define _ENTRY_H

#include "data.h"

/* Defines the pair {key, value} for the tree
*/
struct entry_t {
    char *key;
    struct data_t *value; // data block
};

/* Function that creates an entry, reserving the necessary memory
* for the structure and initializing the fields 'key' and 'value'
* with the given parameters
*/  
struct entry_t *entry_create(char *key, struct data_t *data);

/* Function that eliminates an entry, freeing the occupied memory
*/
void entry_destroy(struct entry_t *entry);

/* Duplicates an entry
*/
struct entry_t *entry_dup(struct entry_t *entry);

/* Substitutes the content of the entry given as a parameter.
*/
void entry_replace(struct entry_t *entry, char *new_key, 
struct data_t *new_value);

/* Compares two entries and returns their order.
* Entry order is defined by the keys.
* Returns 0 if equal,
*        -1 if entry1<entry2,
*         1 if entry1>entry2.
*/
int entry_compare(struct entry_t *entry1, struct entry_t *entry2);

#endif