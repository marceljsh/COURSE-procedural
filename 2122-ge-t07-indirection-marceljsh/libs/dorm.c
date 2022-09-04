#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

dorm_t create_dorm ( char *_name, unsigned short _capacity, enum gender_t _gender )
{
    dorm_t dorm_;

    dorm_.residents_num = 0;
    strcpy( dorm_.name, _name );
    dorm_.capacity = _capacity;
    dorm_.gender   = _gender;

    return dorm_;
}

void print_dorm ( dorm_t dorm_to_print )
{
    printf( "%s", dorm_to_print.name );

    ( dorm_to_print.gender == GENDER_MALE )?
        printf( "|%d|male|%d\n", dorm_to_print.capacity, dorm_to_print.residents_num ):
        printf( "|%d|female|%d\n", dorm_to_print.capacity, dorm_to_print.residents_num );
        
}
