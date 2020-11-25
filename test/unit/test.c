#include <criterion/criterion.h>

#include "add/add.h"
#include "mul/mul.h"

Test(add, positive)
{
    cr_assert_eq(2, add(1, 1));
}

Test(add, negative)
{
    cr_assert_eq(-2, add(-4, 2));
}

Test(mul, mul)
{
    cr_assert_eq(9, mul(3, 3));
}
