#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

student_t create_student ( char *_id, char *_name, char *_year, enum gender_t _gender )
{
    student_t student_;

    strcpy( student_.id, _id );
    strcpy( student_.name, _name );
    strcpy( student_.year, _year );
    student_.gender = _gender;
    student_.dorm   = NULL;

    return student_;
}

void print_student ( student_t student_to_print )
{
    printf( "%s|%s|%s", student_to_print.id,
                        student_to_print.name,
                        student_to_print.year );

    switch ( student_to_print.gender )
    {
        case GENDER_MALE:
            (student_to_print.dorm == NULL)?
                puts("|male|unassigned") : printf( "|male|%s\n", student_to_print.dorm->name );
            break;
        
        case GENDER_FEMALE:
            (student_to_print.dorm == NULL)?
                puts("|female|unassigned") : printf( "|female|%s\n", student_to_print.dorm->name );
            break;
    }
}

void assign_dorm ( student_t *student_, dorm_t *dorm_ )
{
    if ( student_->gender == dorm_->gender && dorm_->residents_num < dorm_->capacity )
    {
        student_->dorm = dorm_;
        dorm_->residents_num++;
    }
    else {
        student_->dorm = NULL;
    }
}