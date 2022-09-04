#include "student.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

student_t create_student ( char *_id, char *_name, char *_year, gender_t _gender )
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
    if ( strcmp(student_to_print.name, "") != 0 ) {
        printf( "%s|%s|%s", student_to_print.id,
                            student_to_print.name,
                            student_to_print.year );

        switch ( student_to_print.gender )
        {
            case GENDER_MALE:
                puts("|male");
                break;
            
            case GENDER_FEMALE:
                puts("|female");
                break;
        }
    }
    fflush(stdout);
}

short findStudentIdx ( char *_id, student_t *list, int length ) {
    for ( short i=0; i<length; i++ ) {
        if ( strcmp(list[i].id, _id) == 0 )
            return i;
    }

    return -1;
}

void assign_student ( student_t *student_, dorm_t *dorm_ )
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

void unassign_student ( student_t *student_, dorm_t* dorm_ )
{
    if ( student_->dorm == dorm_ ) {
        student_->dorm = NULL;
        dorm_->residents_num--;
    }
}

void move_student ( student_t *migrant, dorm_t *newResidence , dorm_t *oldResidence )
{
    if ( migrant->dorm != NULL ) {
        unassign_student ( migrant, oldResidence );
    }
    assign_student ( migrant, newResidence );
}

void print_student_detail ( student_t student_to_print )
{
    if ( strcmp(student_to_print.name, "") != 0 ) {
        printf( "%s|%s|%s", student_to_print.id,
                            student_to_print.name,
                            student_to_print.year );

        switch ( student_to_print.gender ) {
            case GENDER_MALE:
                ( student_to_print.dorm != NULL ) ?
                    printf("|male|%s\n", student_to_print.dorm->name) : printf("|male|unassigned\n");
                break;
            
            case GENDER_FEMALE:
                ( student_to_print.dorm != NULL ) ?
                    printf("|female|%s\n", student_to_print.dorm->name) : printf("|female|unassigned\n");
                break;
        }
    }
    fflush( stdout );
}