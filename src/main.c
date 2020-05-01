#include "input_handle.h"
#include "intersection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  for (int i = 0; i < MAX_LEN; i++) {
    if (temp_data[i] != 0) {
      printf("%s", temp_data[i]);
    }
  }
  printf("\n");
  return 0;
}
