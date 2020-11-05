#include <string.h>
#include "student.h"

Program program_seats( int8_t ml, int8_t bda, int8_t es )
{
    Program prg = {ml, bda, es, 0, 0, 0};
    return prg;
}

Student new_student( char name[], char program[], char mail[], int32_t rank, float ugGrade )
{
   Student s;
   strcpy(s.name, name);
   strcpy(s.program, program);
   strcpy(s.mail, mail);
   strcpy(s.admissionStatus, "not alloted");
   s.regNumber = 0;
   s.entranceRank = rank;
   s.ugGrade = ugGrade;
   applications = applications + 1;
   return s;
}

int seats_filled(Program prg, char prg_name[])
{
    if (!strcmp(prg_name, "ML"))
        return prg.ml_seats_filled;
    else if (!strcmp(prg_name, "BDA"))
        return prg.bda_seats_filled;
    else if (!strcmp(prg_name, "ES"))
        return prg.es_seats_filled;
    else
        return -1;
}

int seats_vacant(Program prg, char prg_name[])
{
    if (!strcmp(prg_name, "ML"))
        return prg.ml_seats - prg.ml_seats_filled;
    else if (!strcmp(prg_name, "BDA"))
        return prg.bda_seats - prg.bda_seats_filled;
    else if (!strcmp(prg_name, "ES"))
        return prg.es_seats - prg.es_seats_filled;
    else
        return -1;
}

void fill_seat(Program prg, char prg_name[])
{
    if (!strcmp(prg_name, "ML"))
        prg.ml_seats_filled = prg.ml_seats_filled + 1;
    else if (!strcmp(prg_name, "BDA"))
        prg.bda_seats_filled = prg.bda_seats_filled + 1;
    else if (!strcmp(prg_name, "ES"))
        prg.es_seats_filled = prg.es_seats_filled + 1;
}

Student allot_seat(Student s, Program prg, Regnumber r)
{   int vacancy;
    vacancy = seats_vacant(prg, s.program);

    if (s.ugGrade <= 5)
    {
        strcpy(s.admissionStatus, "rejected"); 
        return s; 
    }
    else if (s.ugGrade > 5 && s.ugGrade <= 10 )
    {
        if (vacancy > 0)
        {
            strcpy(s.admissionStatus, "alloted");
            fill_seat(prg, s.program);
            s = allot_regnumber(s, r);
            return s;
        } 

        else if (vacancy = 0)
        {
            strcpy(s.admissionStatus, "waiting");
            return s;
        }
    }   
}

Regnumber initial_regnumber(int ml, int bda, int es)
{
    Regnumber r = {ml, bda, es};
    return r;
}

Student allot_regnumber(Student s, Regnumber r)
{
    if (!strcmp(s.program, "ML"))
    {
        r.ml_number = r.ml_number + 1;
        s.regNumber = r.ml_number;
        return s;
    }
     else if (!strcmp(s.program, "BDA"))
    {
        r.bda_number = r.bda_number + 1;
        s.regNumber = r.bda_number ;
        return s;
    }
    else if (!strcmp(s.program, "ES"))
    {
        r.es_number = r.es_number + 1;
        s.regNumber = r.es_number ;
        return s;
    }

}

Student reallot_seat(Student s, Program prg, Regnumber r, char pref1[], char pref2[])
{
    if (!strcmp(s.admissionStatus, "waiting"))
    {
        int pref1_vacancy, pref2_vacancy;
        pref1_vacancy = seats_vacant(prg, pref1);
        pref2_vacancy = seats_vacant(prg, pref2);

        if (pref1_vacancy > 0)
        {
            strcpy(s.program, pref1);
            strcpy(s.admissionStatus, "alloted");
            fill_seat(prg, s.program);
            allot_regnumber(s, r);
        }

        else if (pref2_vacancy > 0)
        {
            strcpy(s.program, pref2);
            strcpy(s.admissionStatus, "alloted");
            fill_seat(prg, s.program);
            allot_regnumber(s, r);
        }

    }

}

int total_applications()
{
 return applications;
}

int latest_reg_number(Regnumber reg_no, char prg[])
{
     if (!strcmp(prg, "ML"))
    {
        return reg_no.ml_number;
    }
     else if (!strcmp(prg, "BDA"))
    {
        return reg_no.bda_number;
    }
     else if (!strcmp(prg, "ES"))
    {
        return reg_no.es_number;
    }
}

int verify_details(Student s, char name[], char program[], char mail[], int32_t rank, float ugGrade, char status[], int regnumber)
{
if (!strcmp(s.name, name) && 
    !strcmp(s.program, program) && \
    !strcmp(s.mail, mail) && \
    !strcmp(s.admissionStatus, status) && \
    s.entranceRank == rank && \
    s.ugGrade == ugGrade && \
    s.regNumber == regnumber )
{
    return 1;
}

else {
    return 0;
}

}

Student     new_student( char name[], char program[], char mail[], int32_t rank, float ugGrade );
