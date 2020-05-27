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
    for (int i = 0; i < MAX_COUNT_OF_SHAPES; i++) {
        if (temp_data[i][0] != '\0') {
            if (get_name(temp_data[i]) == 1) {
                shapes_array[i].name = "triangle";
                shapes_array[i].type = 1;
                int len;
                if (coordinates_valid_check(coord_to_int(temp_data[i]), 8)
                    == 0) {
                    shapes_array[i].coordinates = coord_to_int(temp_data[i]);
                    shapes_array[i].perimeter
                            = perimeter(shapes_array[i].coordinates);
                    shapes_array[i].area
                            = area_triangle(shapes_array[i].coordinates);
                } else {
                    return 10; // error
                }

            } else if (get_name(temp_data[i]) == 2) {
                shapes_array[i].name = "circle";
                shapes_array[i].type = 2;
                if (coordinates_valid_check(coord_to_int(temp_data[i]), 3)
                    == 0) {
                    shapes_array[i].coordinates = coord_to_int(temp_data[i]);
                    shapes_array[i].perimeter
                            = perimeter_circle(shapes_array[i].coordinates);
                    shapes_array[i].area
                            = area_circle(shapes_array[i].coordinates);
                } else {
                    return 10; // error
                }
            }
        }
    }
    for (int i = 0; i < MAX_COUNT_OF_SHAPES; i++) {
        if (shapes_array[i].type == 0) {
            continue;
        }
        printf("\n name - %s\n", shapes_array[i].name);
        if (shapes_array[i].type == 1) {
            printf("   coordinates :{");
            for (int j = 0; j < 8; j++) {
                printf("%d  ", shapes_array[i].coordinates[j]);
            }
            printf("}\n");
            printf("   perimeter: %f \n", shapes_array[i].perimeter);
            printf("   area: %f \n", shapes_array[i].area);
        } else if (shapes_array[i].type == 2) {
            printf("   coordinates :{");
            for (int j = 0; j < 3; j++) {
                printf("%d  ", shapes_array[i].coordinates[j]);
            }
            printf("}\n");
            printf("   perimeter: %f \n", shapes_array[i].perimeter);
            printf("   area: %f \n", shapes_array[i].area);
        }
        printf("\n");
    }
    return 0;
}