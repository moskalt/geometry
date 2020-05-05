#ifndef INPUT_HANDLE_H
#define INPUT_HANDLE_H
char** file_read_function(char** file_data);
int name_check(char* str);
int bracket_check(char* str);
char* get_coordinates(char* str);
int get_name(char* str);
int symbols_in_coordinates_check(char* string);
char** coordinates_separation(char* str, int type);
int* coord_to_int(char* string);
int coordinates_valid_check(int* array, int len);
#endif