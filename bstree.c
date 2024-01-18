// CS2211
// Assignment 5
// Tianyi Han
// 251296906
// than66
// December 7th, 2023
#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototype
void freeHelper(BStree bst);

//Allocate memory of type BStreenode*, set the value to NULL, and return a pointer to the allocated memory.
BStree bstree_ini(void) {
    BStree bst;
    bst = (BStree)malloc(sizeof(BStree_node));
    if (bst == NULL) {
        printf("Memory allocation was unsuccessful");
    }
    else {
        *bst = NULL;
    }
    return bst;
}

//Insert data with key into bst. If key is in bst, then do nothing.
void bstree_insert(BStree bst, Key key, Data data) {
    if (*bst == NULL) {
        *bst = new_node(key, data);
    } else {
        int compar = key_comp(key, (*bst)->key);

        if (compar > 0) {
            bstree_insert(&((*bst)->right), key, data);
        } else if (compar < 0) {
            bstree_insert(&((*bst)->left), key, data);
        }
    }
}

//helper method for bst operations to create a new node that stores a key and a data
BStree_node *new_node(Key key, Data data) {
    BStree_node *node = (BStree_node *)malloc(sizeof(BStree_node));
    if (node != NULL) {
        node->key = (Key)malloc(sizeof(*key));
        if (node->key != NULL) {
            memcpy(node->key, key, sizeof(*key));
        } else {
            // Handle memory allocation failure
            free(node);
            return NULL;
        }

        node->data = (Data)malloc(sizeof(*data));
        if (node->data != NULL) {
            memcpy(node->data, data, sizeof(*data));
        } else {
            // Handle memory allocation failure
            free(node->key);
            free(node);
            return NULL;
        }
        node->right = NULL;
        node->left = NULL;
    }

    return node;
}

//If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search(BStree bst, Key key) {
    if (*bst == NULL) {
        return NULL;  // Key not found
    }
    int compar_result = key_comp(key, (*bst)->key);

    if (compar_result == 0) {
        return (*bst)->data;  // Key found
    } else if (compar_result > 0) {
        return bstree_search(&((*bst)->right), key);  // Search in the right subtree
    } else {
        return bstree_search(&((*bst)->left), key);   // Search in the left subtree
    }
}

//In order traversal of bst and print each node’s key and data.
void bstree_traverse(BStree bst) {
    if (*bst != NULL) {
        // Traverse the left subtree
        bstree_traverse(&((*bst)->left));

        // Print key and data
        key_print2((*bst)->key);
        data_print((*bst)->data);

        // Traverse the right subtree
        bstree_traverse(&((*bst)->right));
    }
}

//Free all the dynamically allocated memory of bst.
void bstree_free(BStree bst) {
    freeHelper(bst);
    free(bst);
}

//helper function to help with free memory of bst
void freeHelper(BStree bst) {
    if (*bst != NULL) {
        freeHelper(&((*bst)->left));
        freeHelper(&((*bst)->right));
        key_free((*bst)->key);
        data_free((*bst)->data);
        free(*bst);
    }
}
