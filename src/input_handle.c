
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int name_check(char* str)
{
    const char triangle[] = "triangle";
    const char caps_triangle[] = "TRIANGLE";
    const char circle[] = "circle";
    const char caps_circle[] = "CIRCLE";
    int check = 1;
    if (str[0] == 'c' || str[0] == 'C') {
        for (int i = 0; str[i] != '('; i++) {
            if (str[i] != triangle[i] && str[i] != caps_triangle[i]) {
                check = 0;
            }
        }
    } else if (str[0] == 't' || str[0] == 'T') {
        for (int i = 0; str[i] != '('; i++) {
            if (str[i] != circle[i] && str[i] != caps_circle[i]) {
                check = 0;
            }
        }
    }
    if (check == 1) {
        return 1;
    } else
        return 0;
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
        if (name_check(temp_string) == 0) {
            printf("Wrong figure's name");
            return 0;
        }
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
