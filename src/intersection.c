#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926535
typedef struct shape {
    char* name;
    int type;
    int* coordinates;
    float perimeter;
    float area;
};

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

double side_length(double x, double y, double xx, double yy)
{
    double len = 0;
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
    double d = (circle_a.coordinates[0] - circle_b.coordinates[0])
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
