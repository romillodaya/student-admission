#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <assert.h>
#include "student.c"

void test_program_seats()
{
    Program pg = program_seats(40, 40, 20);
    assert (pg.ml_seats == 40);
}

int main()
{

    test_program_seats();


    return 0;
}