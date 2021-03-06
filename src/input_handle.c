#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_coordinates(char* str)
{
    int first_bracket_index = 0;
    int last_bracket_index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            first_bracket_index = i;
            break;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ')') {
            last_bracket_index = i;
        }
    }
    char* temp_string = (char*)calloc(
            last_bracket_index - first_bracket_index + 5, sizeof(char));
    int counter = 0;
    for (int i = first_bracket_index; i < last_bracket_index + 1; i++) {
        temp_string[counter] = str[i];
        counter++;
    }
    temp_string[counter] = '\0';
    return temp_string;
}

int bracket_check(char* str)
{
    unsigned int counter_left = 0;
    unsigned int counter_right = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            counter_left++;
        } else if (str[i] == ')') {
            counter_right++;
        }
    }
    if (counter_left != 0 && (counter_left == counter_right)) {
        return 0; // correct brackets
    } else {
        return 1; // wrong brackets
    }
}

int name_check(char* str)
{
    const char triangle[] = "triangle";
    const char circle[] = "circle";
    int check = 1;
    if (str[0] == 't' || str[0] == toupper('t')) {
        for (unsigned int i = 0; i < strlen(triangle); i++) {
            if (str[i] == triangle[i] || str[i] == toupper(triangle[i])) {
                continue;
            } else {
                check = 0;
            }
        }
    } else if (str[0] == 'c' || str[0] == toupper('c')) {
        for (unsigned int i = 0; i < strlen(circle); i++) {
            if (str[i] == circle[i] || str[i] == toupper(circle[i])) {
                continue;
            } else {
                check = 0;
            }
        }
    } else {
        check = 0;
    }
    if (check == 1) {
        return 0; // correct name
    } else {
        return 1;
    }
}

int get_name(char* str)
{
    if (name_check(str) == 0) {
        if (str[0] == 't' || str[0] == 'T') {
            return 1; // is triangle
        } else {
            return 2; // is circle
        }
    } else
        return 0;
}

int symbols_in_coordinates_check(char* string)
{
    char* coord_string = get_coordinates(string);
    int counter_triangle = 0;
    int counter_circle = 0;
    int number_and_dot_check = 0;
    if (bracket_check(string) == 0) {
        if (get_name(string) == 1) {
            for (unsigned int i = 0; coord_string[i] != '\0'; i++) {
                if (coord_string[i] == ',') {
                    counter_triangle++;
                }
            }
        } else if (get_name(string) == 2) {
            for (unsigned int i = 0; coord_string[i] != '\0'; i++) {
                if (coord_string[i] == ',') {
                    counter_circle++;
                }
            }
        } else {
            return 1; // error
        }

    } else {
        return 1; // error
    }
    for (unsigned int i = 0; coord_string[i] != '\0'; i++) {
        if (coord_string[i] != ' ' && coord_string[i] != '('
            && coord_string[i] != ')' && coord_string[i] != ',') {
            if (coord_string[i] == '1' || coord_string[i] == '2'
                || coord_string[i] == '3' || coord_string[i] == '3'
                || coord_string[i] == '4' || coord_string[i] == '5'
                || coord_string[i] == '6' || coord_string[i] == '7'
                || coord_string[i] == '8' || coord_string[i] == '9'
                || coord_string[i] == '0' || coord_string[i] == '.'
                || coord_string[i] == '-') {
                continue;
            } else {
                number_and_dot_check = 1;
            }
        }
    }
    if ((counter_triangle == 3 || counter_circle == 1)
        && number_and_dot_check == 0) {
        return 0; // valid coordinates
    } else {
        return 1; // error
    }
}

char** coordinates_separation(char* str, int type)
{
    // str : coord str;
    int last_left_br_index = 0;
    int first_right_br_index = 0;
    int first_comma_index, second_comma_index, third_comma_index;
    int counter = 0;
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            last_left_br_index = i;
        } else if (str[i] == ')') {
            first_right_br_index = i;
            break;
        }
    }
    if (type == 1) {
        char** temp_string_array = (char**)calloc(4, sizeof(char*));
        for (unsigned int i = 0; i < strlen(temp_string_array); i++)
            temp_string_array[i] = (char*)calloc(10, sizeof(char));
        int temp_string_array_index = 0;
        char* temp_string_1 = (char*)calloc(40, sizeof(char));
        char* temp_string_2 = (char*)calloc(40, sizeof(char));
        char* temp_string_3 = (char*)calloc(40, sizeof(char));
        char* temp_string_4 = (char*)calloc(40, sizeof(char));
        for (unsigned int i = last_left_br_index; i < first_right_br_index;
             i++) {
            if (str[i] == ',' && counter == 0) {
                counter++;
                first_comma_index = i;
            } else if (str[i] == ',' && counter == 1) {
                counter++;
                second_comma_index = i;
            } else if (str[i] == ',' && counter == 2) {
                counter++;
                third_comma_index = i;
            }
        }
        int temp_index = 0;
        for (int i = last_left_br_index + 1; i < first_comma_index; i++) {
            temp_string_1[temp_index] = str[i];
            temp_index++;
        }
        temp_string_1[temp_index + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_1;
        temp_string_array_index++;
        temp_index = 0;
        for (int i = first_comma_index + 1; i < second_comma_index; i++) {
            temp_string_2[temp_index] = str[i];
            temp_index++;
        }
        temp_string_2[temp_index + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_2;
        temp_string_array_index++;
        temp_index = 0;
        for (int i = second_comma_index + 1; i < third_comma_index; i++) {
            temp_string_3[temp_index] = str[i];
            temp_index++;
        }
        temp_string_3[temp_index + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_3;
        temp_string_array_index++;
        temp_index = 0;
        for (int i = third_comma_index + 1; i < first_right_br_index; i++) {
            temp_string_4[temp_index] = str[i];
            temp_index++;
        }
        temp_string_4[temp_index + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_4;
        temp_string_array_index++;
        temp_index = 0;
        return temp_string_array;
    } else if (type == 2) {
        char** temp_string_array = (char**)calloc(2, sizeof(char*));
        for (unsigned int i = 0; i < strlen(temp_string_array); i++)
            temp_string_array[i] = (char*)calloc(10, sizeof(char));
        int temp_string_array_index = 0;
        char* temp_string_1 = (char*)calloc(40, sizeof(char));
        char* temp_string_2 = (char*)calloc(40, sizeof(char));
        int comma_index;
        for (unsigned int i = last_left_br_index + 1; i < first_right_br_index;
             i++) {
            if (str[i] == ',') {
                comma_index = i;
                break;
            }
        }
        int counter = 0;
        for (unsigned int i = last_left_br_index + 1; i < comma_index; i++) {
            temp_string_1[counter] = str[i];
            counter++;
        }
        temp_string_1[counter + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_1;
        temp_string_array_index++;
        counter = 0;
        for (unsigned int i = comma_index + 1; i < first_right_br_index; i++) {
            temp_string_2[counter] = str[i];
            counter++;
        }
        temp_string_2[counter + 1] = '\0';
        temp_string_array[temp_string_array_index] = temp_string_2;
        counter = 0;
        return temp_string_array;
    }
}

int* coord_to_int(char* string)
{
    int type = get_name(string);
    char* string_coord = get_coordinates(string);
    char** separated_array = coordinates_separation(string, type);
    char* temp_string = (char*)calloc(15, sizeof(char));
    char* temp_string_for_int_convert = (char*)calloc(15, sizeof(char));
    int len;
    int checker = 0;
    int temp_index = 0;
    int array_index = 0;
    int temp_j;
    int space_index = 0;
    if (type == 1) {
        len = 4;
    } else {
        len = 2;
    }
    int* array = (int*)malloc(len * 2 * sizeof(int));
    if (type == 1) {
        for (int i = 0; i < len; i++) {
            checker = 0;
            for (int k = strlen(temp_string); k >= 0; k--) {
                temp_string[k] = '\0';
            }
            temp_string = separated_array[i];
            for (unsigned int j = 0; j < strlen(temp_string); j++) {
                if (temp_string[j] == ' ' && checker == 1) {
                    space_index = j;
                    break;
                } else if (temp_string[j] != ' ') {
                    checker = 1;
                }
            }
            for (int j = 0; j < space_index; j++) {
                temp_string_for_int_convert[temp_index] = temp_string[j];
                temp_index++;
            }
            temp_string_for_int_convert[temp_index] = '\0';
            array[array_index] = atoi(temp_string_for_int_convert);
            array_index++;
            temp_index = 0;
            for (int k = strlen(temp_string_for_int_convert); k >= 0; k--) {
                temp_string_for_int_convert[k] = '\0';
            }
            for (unsigned int j = space_index; j < strlen(temp_string); j++) {
                temp_string_for_int_convert[temp_index] = temp_string[j];
                temp_index++;
            }
            array[array_index] = atoi(temp_string_for_int_convert);
            array_index++;
            temp_index = 0;
            for (int k = strlen(temp_string_for_int_convert); k >= 0; k--) {
                temp_string_for_int_convert[k] = '\0';
            }
        }
        for (int k = strlen(temp_string); k >= 0; k--) {
            temp_string[k] = '\0';
        }
    } else if (type == 2) { // working correct
        checker = 0;
        temp_string = separated_array[0];
        for (int i = 0; temp_string[i] != '\0'; i++) {
            if (temp_string[i] != ' ' && checker == 0) {
                temp_string_for_int_convert[temp_index] = temp_string[i];
                temp_index++;
                temp_j = i;
            } else if (temp_string[i] != ' ') {
                checker = 1;
            }
        }
        array_index = 0;
        array[array_index] = atoi(temp_string_for_int_convert);
        array_index++;
        temp_index = 0;
        for (int i = temp_j; temp_string[i] != '\0'; i++) {
            temp_string_for_int_convert[temp_index] = temp_string[i];
            temp_index++;
        }
        array[array_index] = atoi(temp_string_for_int_convert);
        array_index++;
        array[array_index] = atoi(separated_array[1]);
    }
    return array;
}

int coordinates_valid_check(int* array, int len)
{
    float a, b, c;
    if (len == 3) {
        if (array[2] <= 0) {
            return 1; // error
        } else {
            return 0;
        }
    } else {
        if (array[0] == array[6] && array[1] == array[7]) {
            a = sqrt(pow(array[0] - array[2], 2) + pow(array[1] - array[3], 2));
            b = sqrt(pow(array[2] - array[4], 2) + pow(array[3] - array[5], 2));
            c = sqrt(pow(array[4] - array[6], 2) + pow(array[5] - array[7], 2));
            if ((a < b + c) && (b < a + c) && (c < a + b)) {
                return 0;
            }
        } else {
            return 1;
        }
    }
}

char** file_read_function(char** file_data)
{
    FILE* myfile;
    myfile = fopen("./example/target.txt", "r");
    if (myfile == NULL) {
        printf("Error while opening file");
        return 1;
    }
    int i = 0;
    char *temp_string, *ptrFile;
    while (1) {
        temp_string = (char*)calloc(1000, sizeof(char));
        ptrFile = fgets(temp_string, 1000, myfile);
        file_data[i] = temp_string;
        i++;
        if (ptrFile == NULL) {
            if (feof(myfile) != 0) {
                break;
            } else {
                continue;
            }
        }
    }
    fclose(myfile);
    return file_data;
}
