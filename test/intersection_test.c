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