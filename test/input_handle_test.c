#include <ctest.h>
#include <input_handle.h>

CTEST(input_handle, name_check)
{
    // Given
    char* first = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    char* second = "TriAnglE((-32131";
    char* third = "circle()";
    // When
    int res_first = name_check(first);
    int res_second = name_check(second);
    int res_third = name_check(third);
    // Then
    int exception_first = 0;
    int exception_second = 0;
    int exception_third = 0;
    ASSERT_EQUAL(res_first, exception_first);
    ASSERT_EQUAL(res_second, exception_second);
    ASSERT_EQUAL(res_third, exception_third);
}

CTEST(input_handle, bracket_check)
{
    // Given
    char* first = "trinagle((3213 23123 ))";
    char* second = "triangle(32121))";
    // When
    int res_first = bracket_check(first);
    int res_second = bracket_check(second);
    // Then
    int exception_first = 0;
    int exception_second = 1;
    ASSERT_EQUAL(res_first, exception_first);
    ASSERT_EQUAL(res_second, exception_second);
}
CTEST(input_handle, get_coordinates)
{
    // Given
    char* first = "triangle  (  (-3 -2, -1   0, -3 2, -3  -2))";
    char* second = "triangle((3 -2, 3 2, 1 0, 3 -2))";
    // When
    char* res_first = get_coordinates(first);
    char* res_second = get_coordinates(second);
    // Then
    char* exception_first = "(  (-3 -2, -1   0, -3 2, -3  -2))";
    char* exception_second = "((3 -2, 3 2, 1 0, 3 -2))";
    ASSERT_STR(exception_first, res_first);
    ASSERT_STR(exception_second, res_second);
}

CTEST(input_handle, get_name)
{
    // Given
    char* first = "trIaNgle  (  (-3 -2, -1   0, -3 2, -3  -2))";
    char* second = "CircLe((3 -2, 3 2, 1 0, 3 -2))";
    // When
    int res_first = get_name(first);
    int res_second = get_name(second);
    // Then
    int exception_first = 1;
    int exception_second = 2;
    ASSERT_EQUAL(exception_first, res_first);
    ASSERT_EQUAL(exception_second, res_second);
}

CTEST(input_handle, symbols_in_coordinates_check)
{
    // Given
    char* first = "trIaNgle  (  (-3 -2, -1   0, -3 2, -3  -2))";
    char* second = "circle (0 0, 1.5))";
    char* third = "CircLe (0 0 14)";
    char* fourth = "Circle (dea, boob)";
    // When
    int res_first = symbols_in_coordinates_check(first);
    int res_second = symbols_in_coordinates_check(second);
    int res_third = symbols_in_coordinates_check(third);
    int res_fourth = symbols_in_coordinates_check(fourth);
    // Then
    int exception_first = 0;
    int exception_second = 1;
    int exception_third = 1;
    int exception_fourth = 1;
    ASSERT_EQUAL(exception_first, res_first);
    ASSERT_EQUAL(exception_second, res_second);
    ASSERT_EQUAL(exception_third, res_third);
    ASSERT_EQUAL(exception_fourth, res_fourth);
}
CTEST(input_handle, coordinates_valid_check)
{
    // Given
    int first[] = {-3, -2, -1, 0, -3, 2, -3, -2};
    int second[] = {0, 0, 20};
    int third[] = {0, -1, -5};
    int fourth[] = {3, -2, -1, 0, -3, 2, -8, 7};
    // When
    int res_first = coordinates_valid_check(first, 8);
    int res_second = coordinates_valid_check(second, 3);
    int res_third = coordinates_valid_check(third, 3);
    int res_fourth = coordinates_valid_check(fourth, 8);
    // Then
    int exception_first = 0;
    int exception_second = 0;
    int exception_third = 1;
    int exception_fourth = 1;
    ASSERT_EQUAL(exception_first, res_first);
    ASSERT_EQUAL(exception_second, res_second);
    ASSERT_EQUAL(exception_third, res_third);
    ASSERT_EQUAL(exception_fourth, res_fourth);
}