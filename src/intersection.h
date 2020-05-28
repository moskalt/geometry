#ifndef INTERSECTION_H
#define INTERSECTION_H
struct shape {
    char* name;
    int type;
    int* coordinates;
    float perimeter;
    float area;
    char** inc;
};
float* lines_from_coordinates(int* array);
float perimeter(int* array);
float perimeter_circle(int* array);
float area_triangle(int* array);
float area_circle(int* array);
float side_length(float x, float y, float xx, float yy);
int intersection_cr_tr(struct shape circle, struct shape triangle);
int intersection_cr_cr(struct shape circle_a, struct shape circle_b);
float min(float a, float b);
float max(float a, float b);
float det(float a, float b, float c, float d);
float between(float a, float b, float c);
void swap(float* a, float* b);
int intersect(float a, float b, float c, float d);
int intersection_tr_tr(struct shape a, struct shape b);
void print_shapes(struct shape list[], int n);
char* caps(char str[]);
void fill_list(char** data, int count);
char* squeeze(char s[]);
#endif