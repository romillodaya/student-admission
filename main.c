#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <assert.h>
#include "student.c"

void test_program_seats()
{
    Program pg = program_seats(10, 10, 2);
    assert (seats_filled(pg, "ML")  == 0 && \
            seats_filled(pg, "BDA") == 0 && \
            seats_filled(pg, "ES")  == 0);

    Regnumber reg_no_2020 = initial_regnumber(20201000, 20202000, 20203000);
    assert (latest_reg_number(reg_no_2020, "ML")  == 20201000 && \
            latest_reg_number(reg_no_2020, "BDA") == 20202000 && \
            latest_reg_number(reg_no_2020, "ES")  == 20203000 );

    Student s1 =  new_student( "Romil Lodaya", "ML", "romillodaya3007@gmail.com", 137, 7.5 );
    s1 = allot_seat(s1, pg, reg_no_2020);

    assert(verify_details(s1, "Romil Lodaya", "ML", "romillodaya3007@gmail.com", 137, 7.5, "alloted", 20201001 ) == 1);


    assert(total_applications() == 1);
    


}

int main()
{

    test_program_seats();


    return 0;
}