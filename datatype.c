// CS2211
// Assignment 5
// Tianyi Han
// 251296906
// than66
// December 7th, 2023
#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create and initialize a key with dynamic memory allocation
Key key_ini() {
    Key nkey = (Key) malloc(sizeof(Key_struct));
    if (nkey == NULL) {
        fprintf(stderr, "Memory allocation was unsuccessful");
        exit(!(1));
    }
    nkey->key1 = NULL;
    nkey->key2 = 0;
    return nkey;
}

//Set dynamic allocation memory and copy string and set integer
void key_set(Key key, Key1 string, Key2 integer) {
    // Free existing key1 if it is not NULL
    if (key->key1 != NULL) {
        free(key->key1);
    }


    key->key1 = strdup(string);
    if (key->key1 == NULL) {
        fprintf(stderr, "Memory allocation was unsuccessful");
        exit(EXIT_FAILURE);
    }


    key->key2 = integer;
}

//compare 2 keys, it will return value <0 if key1 < key2. return 0 if key1 = key2, return value >0 if key1 > key2
int key_comp(Key key1, Key key2) {
    int str_comp = strcmp(key1->key1, key2->key1);

    if (str_comp == 0) {
        if (key1->key2 > key2->key2) {
            return 1;
        } else if (key1->key2 < key2->key2) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return str_comp;
    }
}

//print a key, key1 then key2
void key_print1(Key key) {
    printf("%-20s %-5d", key->key1, key->key2);
}

//print a key, key2 then key1
void key_print2(Key key) {
    printf("%-20d %-20s", key->key2, key->key1);
}

//free memory allocation for key
void key_free(Key key) {
    free(key->key1);
    free(key);
}

//Create and initialize a data with dynamic memory allocation.
Data data_ini() {
    Data ndata = (Data)malloc(sizeof(float));

    if (ndata == NULL) {
        fprintf(stderr, "Memory allocation was unsuccessful");
        exit(EXIT_FAILURE);
    }

    *ndata = 0.0;
    return ndata;
}

//Assign value of data with intdata.
void data_set(Data data, float intdata) {
    *data = intdata;
}

//Print a data
void data_print(Data data) {
    printf("%5.0f\n", *data);
}

//free memory allocation for data
void data_free(Data data) {
    free(data);
}

