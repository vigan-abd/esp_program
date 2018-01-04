#include <stdlib.h>
#include <stdio.h>
#include "test_bcd.h"
#include "test_r_buffer.h"


int main ()
{
    printf("Test Case >> test_r_buffer_empty\n");
    if (!test_r_buffer_empty())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    printf("Test Case >>test_r_buffer_push\n");
    if (!test_r_buffer_push())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    printf("Test Case >> test_r_buffer_pop\n");
    if (!test_r_buffer_pop())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    printf("Test Case >> test_r_buffer_empty_pop\n");
    if (!test_r_buffer_empty_pop())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    printf("Test Case >> test_r_buffer_overflow\n");
    if (!test_r_buffer_overflow())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    printf("Test Case >> test_r_buffer_rotate\n");
    if (!test_r_buffer_rotate())
    {
        printf("Result >> error\n");
        exit(1);
    }
    else
    {
        printf("Result >> success\n");
    }

    return 0;
}