#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    gender_t gender;
    dorm_t *dorm;
} student_t;

student_t create_student ( char *_id, char *_name, char *_year, gender_t _gender );
short findStudentIdx ( char *_id, student_t *list, int length );
void print_student ( student_t student_to_print );
void assign_student ( student_t *student_, dorm_t *dorm_ );
void unassign_student ( student_t *student_, dorm_t* dorm_ );
void move_student ( student_t *migrant, dorm_t *newResidence , dorm_t *oldResidence );
void print_student_detail ( student_t student_to_print );

#endif
