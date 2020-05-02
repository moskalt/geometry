#include <ctype.h>
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
                || coord_string[i] == '3' || coord_string == '3'
                || coord_string[i] == '4' || coord_string == '5'
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
