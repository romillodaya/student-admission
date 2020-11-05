#include <stdio.h>
#include <stdlib.h>
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

    Student s1 =  new_student( "Romil Lodaya", "ML", "romillodaya@gmail.com", 100, 9.5 );
    Student s2 =  new_student( "Mayank Raj", "ES", "mayankraj@gmail.com", 200, 8.5 );
    Student s3 =  new_student( "Neha Kala", "ES", "nehakala@gmail.com", 300, 7.5 );
    Student s4 =  new_student( "Sukanya Vaidya", "ES", "sukanyavaidya@gmail.com", 400, 6.5 );
    Student s5 =  new_student( "Piyush Tayade", "ES", "piyushtayade@gmail.com", 500, 4.5 );

    s1 = allot_seat(s1, pg, reg_no_2020);
    s2 = allot_seat(s2, pg, reg_no_2020);
    s3 = allot_seat(s3, pg, reg_no_2020);
    s4 = allot_seat(s4, pg, reg_no_2020);
    s5 = allot_seat(s5, pg, reg_no_2020);

    printf("%d \n", s2.regNumber);
    printf("%d \n", s3.regNumber);

/*
    assert(verify_details(s1, "Romil Lodaya", "ML", "romillodaya@gmail.com", 100, 9.5, "alloted", 20201001 ) == 1);
    assert(verify_details(s2, "Mayank Raj", "ES", "mayankraj@gmail.com", 200, 8.5, "alloted", 20203001 ) == 1);
    assert(verify_details(s3, "Neha Kala", "ES", "nehakala@gmail.com", 300, 7.5, "alloted", 20203002 ) == 1);
    assert(verify_details(s4, "Sukanya vaidya", "ES", "sukanyavaidya@gmail.com", 400, 6.5, "waiting", 0 ) == 1);
    assert(verify_details(s5, "Piyush Tayade", "ES", "piyushtayade@gmail.com", 500, 4.5, "rejected", 0 ) == 1);
*/
    assert(total_applications() == 5);

}

int main()
{

    test_program_seats();


    return 0;
}