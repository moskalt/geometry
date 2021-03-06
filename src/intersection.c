#include "input_handle.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define PI 3.1415926535
typedef struct shape {
    char* name;
    char* type;
    int* coordinates;
    float perimeter;
    float area;
    char** inc;
};

char* squeeze(char s[])
{
    int i, j = 0;
    char* dest = (char*)malloc(((strlen(s) + 1) * sizeof(char)));
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != '.')
            dest[j++] = s[i];
    dest[j] = '\0';
    return dest;
}

float* lines_from_coordinates(int* array)
{
    const int len = 8; // triangle coord array
    float* lines_array = (float*)calloc(3, sizeof(float));
    float a = sqrt(pow(array[0] - array[2], 2) + pow(array[1] - array[3], 2));
    float b = sqrt(pow(array[2] - array[4], 2) + pow(array[3] - array[5], 2));
    float c = sqrt(pow(array[4] - array[6], 2) + pow(array[5] - array[7], 2));
    lines_array[0] = a;
    lines_array[1] = b;
    lines_array[2] = c;
    return lines_array;
}

float perimeter(int* array)
{
    float* lines_array = lines_from_coordinates(array);
    float perimeter = 0;
    for (int i = 0; i < 3; i++) {
        perimeter += lines_array[i];
    }
    return perimeter;
}
float perimeter_circle(int* array)
{
    int radious = array[2];
    float perimeter = 2 * PI * radious;
    return perimeter;
}
float area_triangle(int* array)
{
    float* lines_array = lines_from_coordinates(array);
    float area;
    float semiperimeter = perimeter(array) / 2;
    area
            = sqrt(semiperimeter * (semiperimeter - lines_array[0])
                   * (semiperimeter - lines_array[1])
                   * (semiperimeter - lines_array[2]));
    return area;
}
float area_circle(int* array)
{
    float* lines_array = lines_from_coordinates(array);
    float area;
    int radious = array[2];
    area = PI * radious * radious;
    return area;
}

float side_length(float x, float y, float xx, float yy)
{
    float len = 0;
    len = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    return len;
}

int intersection_cr_tr(struct shape circle, struct shape triangle)
{
    if (circle.type != 'c' || triangle.type != 't') {
        printf("%s\n", "Input ERROR");
        return -1;
    }
    if (side_length(
                triangle.coordinates[0],
                triangle.coordinates[1],
                circle.coordinates[0],
                circle.coordinates[1])
        <= circle.coordinates[2]) {
        return 1;
    }
    if (side_length(
                triangle.coordinates[2],
                triangle.coordinates[3],
                circle.coordinates[0],
                circle.coordinates[1])
        <= circle.coordinates[2]) {
        return 1;
    }
    if (side_length(
                triangle.coordinates[4],
                triangle.coordinates[5],
                circle.coordinates[0],
                circle.coordinates[1])
        <= circle.coordinates[2]) {
        return 1;
    }
    return 0;
}

int intersection_cr_cr(struct shape circle_a, struct shape circle_b)
{
    float d = (circle_a.coordinates[0] - circle_b.coordinates[0])
                    * (circle_a.coordinates[0] - circle_b.coordinates[0])
            + (circle_a.coordinates[1] - circle_b.coordinates[1])
                    * (circle_a.coordinates[1] - circle_b.coordinates[1]);
    if (d <= (circle_a.coordinates[2] + circle_b.coordinates[2])
                        * (circle_a.coordinates[2] + circle_b.coordinates[2])
        && d >= (circle_a.coordinates[2] > circle_b.coordinates[2]
                         ? circle_a.coordinates[2] - circle_b.coordinates[2]
                         : circle_b.coordinates[2] - circle_a.coordinates[2])) {
        return 1;
    } else {
        return 0;
    }
}

float min(float a, float b)
{
    if (a < b)
        return a;
    if (a > b)
        return b;
    return 0;
}
float max(float a, float b)
{
    if (a < b)
        return b;
    if (a > b)
        return a;
    return 0;
}

float det(float a, float b, float c, float d)
{
    return a * d - b * c;
}

float between(float a, float b, float c)
{
    float exp_1;
    float exp_2;
    if (min(a, b) <= c)
        exp_1 = 1;
    else
        exp_1 = 0;
    if (c <= max(a, b))
        exp_2 = 1;
    else
        exp_2 = 0;
    return exp_1 * exp_2;
}

void swap(float* a, float* b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

int intersect(float a, float b, float c, float d)
{
    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    if (max(a, c) <= min(b, d))
        return 1;
    if (max(a, c) > min(b, d))
        return 0;
    return 0;
}

int intersection_tr_tr(struct shape a, struct shape b)
{
    float A1 = 0, B1 = 0, C1 = 0, A2 = 0, B2 = 0, C2 = 0, zn = 0, x = 0, y = 0,
          bool = 0, c = 0, d = 0;
    if (a.type == 't') {
        if (b.type == 't') {
            A1 = a.coordinates[1] - a.coordinates[3],
            B1 = a.coordinates[2] - a.coordinates[0],
            C1 = -A1 * a.coordinates[0] - B1 * a.coordinates[1];
            A2 = b.coordinates[1] - b.coordinates[3],
            B2 = b.coordinates[2] - a.coordinates[0],
            C2 = -A2 * b.coordinates[0] - B2 * b.coordinates[1];
            zn = det(A1, B1, A2, B2);
            if (zn != 0) {
                x = -det(C1, B1, C2, B2) * 1. / zn;
                y = -det(A1, C1, A2, C2) * 1. / zn;
                bool = between(a.coordinates[0], a.coordinates[2], x)
                        * between(a.coordinates[1], a.coordinates[3], y)
                        * between(b.coordinates[0], b.coordinates[2], x)
                        * between(b.coordinates[1], b.coordinates[3], y);
                if (bool == 0) {
                    return 0;
                } else if (bool == 1) {
                    return 1;
                }
            } else {
                if ((det(A1, C1, A2, C2) == 0) && (det(B1, C1, B2, C2) == 0)) {
                    c = (intersect(
                            a.coordinates[0],
                            a.coordinates[2],
                            b.coordinates[0],
                            b.coordinates[2]));
                    d = (intersect(
                            a.coordinates[1],
                            a.coordinates[3],
                            b.coordinates[3],
                            b.coordinates[3]));
                    if ((c * d) == 1) {
                        return 1;
                    }
                }
            }
        }
    } else {
        return 0;
    }
    return 0;
}

void print_shapes(struct shape list[], int n)
{
    for (int i = 0; i < n; i++) {
        printf(" %s\n", list[i].name);
        printf("   perimeter = %.4f\n", list[i].perimeter);
        printf("   area = %.4f\n", list[i].area);
        if (strlen(list[i].inc[0]) > 0) {
            printf("   intersects:\n");
        }
        for (int j = 0; j < n; j++) {
            if (strlen(list[i].inc[j]) > 0) {
                printf("      %s\n", list[i].inc[j]);
            }
        }
        printf("\n");
    }
}

char* caps(char str[])
{
    const char trin[] = "triangle";
    const char cap_trin[] = "TRIANGLE";
    const char circ[] = "circle";
    const char cap_circ[] = "CIRCLE";
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == trin[j] || str[i] == cap_trin[j]) {
            str[i] = cap_trin[j];
            j++;
        } else if (str[i] == circ[j] || str[i] == cap_circ[j]) {
            str[i] = cap_circ[j];
            j++;
        }
    }
    return str;
}

void fill_list(char** data, int count)
{
    struct shape* list = (struct shape*)calloc(count, sizeof(struct shape));
    for (int i = 0; i < count; i++) {
        char* new_name = (char*)calloc(MAX_LEN, sizeof(char));
        new_name[0] = (char)(i + 1 + 48);
        new_name[1] = '.';
        list[i].name = strcat(new_name, squeeze(data[i]));
        list[i].name = caps(list[i].name);
        if (data[i][0] == 't' || data[i][0] == 'T') {
            list[i].type = 't';
        } else {
            list[i].type = 'c';
        }
        list[i].coordinates = coord_to_int(data[i]);
        if (list[i].type == 't') {
            list[i].perimeter = perimeter(list[i].coordinates);
            list[i].area = area_triangle(list[i].coordinates);
        } else {
            list[i].perimeter = perimeter_circle(list[i].coordinates);
            list[i].area = area_circle(list[i].coordinates);
        }
    }
    int k = 0;
    for (int i = 0; i < count; i++) {
        char** intersec_matrix = (char**)malloc(count * sizeof(char*));
        for (int ii = 0; ii < count; ii++) {
            intersec_matrix[ii] = (char*)malloc(MAX_LEN * sizeof(char));
        }
        for (int ii = 0; ii < count; ii++) {
            for (int jj = 0; jj < MAX_LEN; jj++) {
                intersec_matrix[ii][jj] = 0;
            }
        }
        for (int j = 0; j < count; j++) {
            if (i == j) {
                continue;
            }
            if (list[i].type == 'c') {
                if (list[j].type == 'c') {
                    if (intersection_cr_cr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                } else {
                    if (intersection_cr_tr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                }
            } else {
                if (list[j].type == 't') {
                    if (intersection_tr_tr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }

                } else {
                    if (intersection_cr_tr(list[j], list[i])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                }
            }
        }
        list[i].inc = intersec_matrix;
        k = 0;
    }
    print_shapes(list, count);
}