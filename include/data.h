#ifndef _DATA_H
#define _DATA_H

/* Structure defining the data
*/
struct data_t {
    int datasize; // data block size
    void *data; // data content
};

/* Function that creates a new element of data (data_t), reserving
* the necessary amount of memory specified by the parameter 'size'.
*/
struct data_t *data_create(int size);

/* Function that creates a new element of data (data_t),
* initializing the field 'data' with the given parameter 'data',
* without having to reserve memory for it.
*/ 
struct data_t *data_create2(int size, void *data);

/* Function that eliminates a block of data, pointed by the parameter
* 'data', freeing all the memory occupied by it.
*/
void data_destroy(struct data_t *data);

/* Function that duplicates a struct data_t, reserving the 
* memory needed for it, including the imbedded data.
*/
struct data_t *data_dup(struct data_t *data);

/* Function that replaces the content of the struct data_t referenced 
* by the parameter 'data.
*/
void data_replace(struct data_t *data, int new_size, void *new_data);

#endif