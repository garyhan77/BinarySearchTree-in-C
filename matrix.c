// CS2211
// Assignment 5
// Tianyi Han
// 251296906
// than66
// December 7th, 2023
#include "matrix.h"
#include <stdlib.h>

//Matrix construction using bstree_ini();
Matrix matrix_construction(void) {
    return bstree_ini();
}
//
// If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) {
    Key nkey = key_ini();
    key_set(nkey, index1, index2);

    Data result_data = bstree_search(m, nkey);

    key_free(nkey);

    return (result_data != NULL);
}

//If location (index1, index2) is defined in Matrix m,then return a pointer to the associated value. Otherwise, return NULL.
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2) {
    Key nkey = key_ini();
    key_set(nkey, index1, index2);

    const Value *result_value = bstree_search(m, nkey);

    key_free(nkey);

    return result_value;
}

//Assign value to Matrix m at location (index1, index2). If that location already has value, then overwrite.
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
    Key nkey = key_ini();
    key_set(nkey, index1, index2);
    if (bstree_search(m, nkey) != NULL) {
        data_set(bstree_search(m, nkey), value + 1);
        key_free(nkey);
    } else {

        Data nData = data_ini();
        data_set(nData, value);
        bstree_insert(m, nkey, nData);

   }

}

//Print indices and values in the Matrix m (with bstree_traverse()).
void matrix_list(Matrix m) {
    bstree_traverse(m);
}

//Free allocated space (with bstree_free()).
void matrix_destruction(Matrix m) {
    bstree_free(m);
}