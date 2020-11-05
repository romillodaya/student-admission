#include <stdint.h>
#include "appconstants.h"

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

int applications = 0;

typedef struct _student_ Student;

struct _student_
{
    char    name[STUDENT_NAME_LEN];
    char    program[PROGRAM_NAME_LEN];
    char    mail[MAIL_ID_LEN];
    char    admissionStatus[ADMISSION_STATUS_LEN];

    int32_t regNumber;
    int32_t entranceRank;
    float   ugGrade;
    
};

typedef struct _program_ Program;

struct _program_
{
    int8_t  ml_seats;
    int8_t  bda_seats;
    int8_t  es_seats;

    int8_t  ml_seats_filled;
    int8_t  bda_seats_filled;
    int8_t  es_seats_filled;
};

typedef struct _regnumber_ Regnumber;

struct _regnumber_
{
    int  ml_number;
    int  bda_number;
    int  es_number;
};

Regnumber update_reg(Regnumber reg_no, char prg[]);
Program     program_seats( int8_t ml, int8_t bda, int8_t es ); 
Student     new_student( char name[], char program[], char mail[], int32_t rank, float ugGrade );
Student     allot_seat(Student s, Program prg, Regnumber r); 
Student     reallot_seat(Student s, Program prg, Regnumber r, char pref1[], char pre2[]);
Student     allot_regnumber(Student s, Regnumber r); 
int         seats_filled(Program prg, char prg_name[]);


#endif // STUDENT_H_INCLUDED