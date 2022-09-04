#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

dorm_t create_dorm ( char *_name, unsigned short _capacity, gender_t _gender )
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
        printf( "|%d|male\n", dorm_to_print.capacity ):
        printf( "|%d|female\n", dorm_to_print.capacity );

    fflush( stdout );    
}

void print_dorm_detail ( dorm_t dorm_to_print )
{
    printf( "%s|%d", dorm_to_print.name, dorm_to_print.capacity );

    ( dorm_to_print.gender == GENDER_MALE )?
        printf( "|male" ) : printf( "|female" );
    
    printf( "|%d\n", dorm_to_print.residents_num );

    fflush( stdout );  
}

short findDormIdx ( char* _name, dorm_t *list, int length )
{
    for ( short i=0; i<length; i++ ) {
        if ( strcmp( list[i].name, _name ) == 0 )
            return i;
    }

    return -1;
}
