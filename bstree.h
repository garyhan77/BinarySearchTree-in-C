// CS2211
// Assignment 5
// Tianyi Han
// 251296906
// than66
// December 7th, 2023

#ifndef ASN5_BSTREE_H
#define ASN5_BSTREE_H
#include "datatype.h"

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;

BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traverse(BStree bst);
void bstree_free(BStree bst);
#endif
