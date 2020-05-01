#include <ctest.h>
#include <input_handle.h>

CTEST(input_handle, name_check)
{
    // Given
    char* first = "tRiAngLe((";
    // When
    int exception_first = name_check(first);
    // Then
    int res_first = 1;
}