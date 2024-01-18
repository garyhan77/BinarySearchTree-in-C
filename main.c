// CS2211
// Assignment 5
// Tianyi Han
// 251296906
// than66
// December 7th, 2023
#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
#include <string.h>

//helper function to help process the input
void process_input(Matrix m) {
    Index1 index1;
    Index2 index2 = 0;
    while (1) {
        index1 = malloc(sizeof(char) * 100);
        if (scanf("%d ", &index2) > 0 && fgets(index1, 100, stdin) != NULL) {
            index1[strlen(index1) - 1] = '\0';
            matrix_set(m, index1, index2, 1);
            free(index1);
        } else {
            free(index1);
            break;
        }

    }
}

//programs main function that constructs a matrix, calls helper to process input then prints everything using matrix_list
//and frees all memory at last using matrix_destruction
int main() {
    Matrix m = matrix_construction();
    process_input(m);

    printf("%-20s%-20s%-20s\n", "Number", "Street Name", "Occurrence");
    matrix_list(m);

    matrix_destruction(m);

    return 0;
}
