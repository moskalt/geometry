#include "input_handle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **file_read_function(char **file_data) {
  FILE *myfile;
  myfile = fopen("./target.txt", "r");
  if (myfile == NULL) {
    printf("Error while opening file");
    return 1;
  }
  int i = 0;
  char *temp_string, *ptrFile;
  while (1) {
    temp_string = (char *)calloc(1000, sizeof(char));
    ptrFile = fgets(temp_string, 1000, myfile);
    file_data[i] = ptrFile;
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