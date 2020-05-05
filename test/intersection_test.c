#include <ctest.h>
#include <intersection.h>

CTEST(intersection, perimeter)
{
    // Given
    int first[] = {-3, -2, -1, 0, -3, 2, -3, -2};
    int fourth[] = {3, -2, 0, 0, -3, 5, 3, -2};
    // When
    float res_first = perimeter(first);
    float res_fourth = perimeter(fourth);
    // Then
    float exception_first = 9.656855;
    float exception_fourth = 18.656048;
    ASSERT_EQUAL(exception_first, res_first);
    ASSERT_EQUAL(exception_fourth, res_fourth);
}

CTEST(intersection, perimeter_circle)
{
    // Given
    int first[] = {0, 0, 12};
    // When
    float res_first = perimeter_circle(first);
    // Then
    float exception_first = 75.398224;
    ASSERT_EQUAL(exception_first, res_first);
}

CTEST(intersection, area_triangle)
{
    // Given
    int first[] = {3, -2, 0, 0, -3, 5, 3, -2};
    // When
    float res_first = area_triangle(first);
    // Then
    float exception_first = 4.500003;
    ASSERT_EQUAL(exception_first, res_first);
}
CTEST(intersection, area_circle)
{
    // Given
    int first[] = {0, 0, 12};
    // When
    float res_first = area_circle(first);
    // Then
    float exception_first = 452.389343;
    ASSERT_EQUAL(exception_first, res_first);
}
