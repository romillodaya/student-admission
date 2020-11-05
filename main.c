#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <assert.h>
#include "student.c"

void test_program_seats()
{
    Program pg = program_seats(40, 40, 20);
    assert (seats_filled(pg, "ML") == 0);

    Regnumber reg_no_2020 = initial_regnumber(20201000, 20202000, 20203000);
    assert (reg_no_2020.bda_number == 20202000);

    Student s1 =  new_student( "Romil Lodaya", "ML", "romillodaya3007@gmail.com", 137, 7.5 );
    assert(s1.entranceRank == 137);
    


}

int main()
{

    test_program_seats();


    return 0;
}