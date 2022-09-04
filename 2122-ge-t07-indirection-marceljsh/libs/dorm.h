#ifndef DORM_H
#define DORM_H

#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

typedef struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
} dorm_t;

dorm_t create_dorm ( char *_name, unsigned short _capacity, enum gender_t _gender );
void print_dorm ( dorm_t dorm_to_print );

#endif
