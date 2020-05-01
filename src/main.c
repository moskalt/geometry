#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct first_handle {
  char string[40];
} ex;

int string_counter() {}

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

int main() {
  const int MAX_LEN = 100;
  char **temp_data = (char **)calloc(MAX_LEN, sizeof(char *));
  for (int i = 0; i < MAX_LEN; i++) {
    temp_data[i] = (char *)calloc(MAX_LEN, sizeof(char));
  }
  char **file_data = (char **)calloc(MAX_LEN, sizeof(char *));
  for (int i = 0; i < MAX_LEN; i++) {
    file_data[i] = (char *)calloc(MAX_LEN, sizeof(char));
  }
  for (int i = 0; i < MAX_LEN; i++) {
    for (int j = 0; j < MAX_LEN; j++) {
      file_data[i][j] = 0;
    }
  }
  temp_data = file_read_function(file_data);
  return 0;
}
