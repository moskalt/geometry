#include "input_handle.h"
#include "intersection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_COUNT_OF_SHAPES = 10;

typedef struct shape {
    char* name;
    int type;
    int* coordinates;
    float perimeter;
    float area;
};

int main()
{
    struct shape* shapes_array = (struct shape*)(calloc(
            MAX_COUNT_OF_SHAPES, sizeof(struct shape)));
    const int MAX_LEN = 100;
    char** temp_data = (char**)calloc(MAX_LEN, sizeof(char*));
    for (int i = 0; i < MAX_LEN; i++) {
        temp_data[i] = (char*)calloc(MAX_LEN, sizeof(char));
    }
    char** file_data = (char**)calloc(MAX_LEN, sizeof(char*));
    for (int i = 0; i < MAX_LEN; i++) {
        file_data[i] = (char*)calloc(MAX_LEN, sizeof(char));
    }
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            file_data[i][j] = 0;
        }
    }
    temp_data = file_read_function(file_data);
    for (int i = 0; i < MAX_LEN; i++) {
        if (temp_data[i] != 0) {
            printf("%s", temp_data[i]);
        }
    }
    char* temp_string = temp_data[0];
    char** array = coordinates_separation(temp_string, get_name(temp_string));
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", array[i]);
    }
    printf("\n");

    int* array_int = coord_to_int(temp_string);
    for (int i = 0; i < 8; i++) {
        printf("%d ", array_int[i]);
    }
    printf("\n");
    return 0;
}
