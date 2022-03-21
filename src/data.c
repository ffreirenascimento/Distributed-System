#include <stdlib.h>
#include <stdio.h>
#include "../include/data.h"

/* Function that creates a new element of data (data_t), reserving
* the necessary amount of memory specified by the parameter 'size'.
*/
struct data_t *data_create(int size) {

    // verify size
    if (!size || size < 0)
        return NULL;

    struct data_t *new_data = 
        (struct data_t *) malloc(sizeof(int) + size);
    if (!new_data) 
        exit(1);

    new_data -> datasize = size;
    new_data -> data = malloc(size);
    
    return new_data; 
}

/* Function that creates a new element of data (data_t),
* initializing the field 'data' with the given parameter 'data',
* without having to reserve memory for it.
*/ 
struct data_t *data_create2(int size, void *data) {

    // Verify data
    if (!data)
        return NULL;
    
    struct data_t *new_data = data_create(size);

    free(new_data -> data);
    new_data -> data = data;

    return new_data; 
}

/* Function that eliminates a block of data, pointed by the parameter
* 'data', freeing all the memory occupied by it.
*/
void data_destroy(struct data_t *data) {
    if (data) {
        free(data -> data);
        free(data);
    }
}

/* Function that duplicates a struct data_t, reserving the 
* memory needed for it, including the imbedded data.
*/
struct data_t *data_dup(struct data_t *data) {
    if (!data) {
        return NULL;
    }

    struct data_t *dup = data_create(data -> datasize);

    dup -> data = memcpy(dup -> data, data -> data, data -> datasize);

    return dup;
}

/* Function that replaces the content of the struct data_t referenced 
* by the parameter 'data.
*/
void data_replace(struct data_t *data, int new_size, void *new_data) {
    if (data || new_size > 0 || new_data) {
        free(data -> data);
        data -> datasize = new_size;
        data -> data = new_data;
    }
}




