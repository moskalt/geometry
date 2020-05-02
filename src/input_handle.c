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
        return 0;
    } else {
        return 1;
    }
}

char* get_name(char* str)
{
    int check = 0;
    if (name_check(str) == 1) {
        if (str[0] == 't' || str[0] == 'T') {
            return "triangle";
        } else {
            return "circle";
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
