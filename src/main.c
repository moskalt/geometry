#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_read_function()
{
    FILE* myfile;
    myfile = fopen("./target.txt", "r");
    if (myfile == NULL) {
        printf("Error while opening file");
        return 1;
    }
    char *temp_string, *ptrFile;
    while (1) {
        temp_string = (char*)malloc(1000 * sizeof(char));
        ptrFile = fgets(temp_string, 1000, myfile);
        if (ptrFile == NULL) {
            if (feof(myfile) != 0) {
                break;
            } else {
                continue;
            }
        }
        printf("%s\n", temp_string);
    }
    fclose(myfile);
    return 0;
}

int main()
{
    const int MAX_LEN = 100;
    char** file_data = (char**)malloc(MAX_LEN * sizeof(char*));
    for (int i = 0; i < MAX_LEN; i++) {
        file_data[i] = (char*)malloc(MAX_LEN * sizeof(char));
    }
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            file_data[i][j] = 0;
        }
    }
    file_read_function();
    return 0;
}
