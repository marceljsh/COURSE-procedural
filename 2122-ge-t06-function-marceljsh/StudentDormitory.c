// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Hutabarat

#include "StudentDormitory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_t create_student(char *_id, char *_name, char *_year, char *_study_program, enum gender_t _gender)
{
  struct student_t std;
  
  strcpy( std.id, _id );
  strcpy( std.name, _name );
  strcpy( std.year, _year );
  strcpy( std.study_program, _study_program );
  std.gender = _gender;
  
  return std;
}

struct dorm_t create_dorm(char *_dormitory_name, unsigned short _capacity, enum status_t _status, enum type_t _type)
{
  struct dorm_t dorm_;

  strcpy( dorm_.dormitory_name, _dormitory_name );
  dorm_.capacity = _capacity;
  dorm_.status   = _status;
  dorm_.type     = _type;
  dorm_.residents_num = 0;

  return dorm_;
} 
  
void print_students(struct student_t *_students, int size )
{
  
  puts("Students:");
  for ( size_t i=0; i<size; i++ ) {
    switch ( _students[i].gender ) {
      case MALE: printf("%s#%s#%s#%s#MALE\n", _students[i].id,
                                              _students[i].name,
                                              _students[i].year,
                                              _students[i].study_program); break;
      
      case FEMALE: printf("%s#%s#%s#%s#FEMALE\n", _students[i].id,
                                                  _students[i].name,
                                                  _students[i].year,
                                                  _students[i].study_program); break;
    }

  }

  printf("\n");

}

void print_dorms(struct dorm_t *_dorm, int size){

  puts("Dorms:");
  for ( size_t i=0; i<size; i++ ) {
    print_dorm( _dorm[i] );
  }
  printf("\n");

}

void print_dorm(struct dorm_t _dorm ){
  
  switch ( _dorm.type ) {
      case FOR_MALE:
        _dorm.status == A ? printf("%s#%d#Available#For Male\n",     _dorm.dormitory_name, _dorm.capacity) :
                            printf("%s#%d#Not available#For Male\n", _dorm.dormitory_name, _dorm.capacity);
        break;
      
      case FOR_FEMALE:
        _dorm.status == A ? printf("%s#%d#Available#For Female\n",     _dorm.dormitory_name, _dorm.capacity) :
                            printf("%s#%d#Not available#For Female\n", _dorm.dormitory_name, _dorm.capacity);
        break;
    }
}

void print_students_dorm(struct student_dormitory_t *students_dorms, int students_size, struct dorm_t *_dorm, int droms_size){
  
  for ( size_t i=0; i<droms_size; i++ ) {
    if ( _dorm[i].residents_num > 0 ) {
      switch ( _dorm[i].type ) {
        case FOR_MALE:
          _dorm[i].capacity > 0? printf("%s#%d#Available#For Male\n", _dorm[i].dormitory_name, _dorm[i].capacity ):
                                 printf("%s#%d#Not Available#For Male\n", _dorm[i].dormitory_name, _dorm[i].capacity );
          break;
        
        case FOR_FEMALE:
          _dorm[i].capacity > 0? printf("%s#%d#Available#For Female\n", _dorm[i].dormitory_name, _dorm[i].capacity ):
                                 printf("%s#%d#Not Available#For Female\n", _dorm[i].dormitory_name, _dorm[i].capacity );
          break;
      }
      for ( size_t j=0; j<students_size; j++ ) {
        if ( strcmp( students_dorms[j].dorm.dormitory_name, _dorm[i].dormitory_name) == 0 ) {
          printf("%s#%s#%s#%s\n", students_dorms[j].student.id,
                                  students_dorms[j].student.name,
                                  students_dorms[j].student.year,
                                  students_dorms[j].student.study_program);
        }
      }
      printf("\n");
    }
    else {
      switch ( _dorm[i].type ) {
        case FOR_MALE:
          printf("%s#%d#Available#For Male\n", _dorm[i].dormitory_name, _dorm[i].capacity );
          puts("0");
          break;
        case FOR_FEMALE:
          printf("%s#%d#Available#For Female\n", _dorm[i].dormitory_name, _dorm[i].capacity );
          puts("0");
          break;
      }
      printf("\n");
    }
  }
  
}

void assign_students(struct student_dormitory_t *students_dorms, struct dorm_t *dorms, struct student_t *students, int size_dorms, int size_students){
  
  print_students( students, size_students );
  print_dorms( dorms, size_dorms );

  for ( size_t i=0; i<size_students; i++ ) {
    switch ( students[i].gender ) {
      case MALE:
        students_dorms[i].student = students[i];
        if ( dorms[1].status == A ) {
          students_dorms[i].dorm = dorms[1];
          dorms[1].residents_num++;
          dorms[1].capacity--;
          if ( dorms[1].capacity == 0 ) {
            dorms[1].status = NA;
          }
          
        }
        else {
          students_dorms[i].dorm = dorms[2];
          dorms[2].residents_num++;
          dorms[2].capacity--;
          if ( dorms[2].capacity == 0 ) {
            dorms[2].status = NA;
          }
        }
        break;
      
      case FEMALE:
        students_dorms[i].student = students[i];
        if ( dorms[0].status == A ) {
          students_dorms[i].dorm = dorms[0];
          dorms[0].residents_num++;
          dorms[0].capacity--;
          if ( dorms[0].capacity == 0 ) {
            dorms[0].status = NA;
          }
          
        }
        else {
          students_dorms[i].dorm = dorms[3];
          dorms[3].residents_num++;
          dorms[3].capacity--;
          if ( dorms[3].capacity == 0 ) {
            dorms[3].status = NA;
          }
        }
        break;
    }
  }

}


struct dorm_t check_dorm(struct dorm_t *dorms, int size, enum type_t gender)
{
  struct dorm_t temp;
  
  for ( size_t i=0; i<size; i++ ) {
    if ( dorms[i].type == gender ) { temp = dorms[i]; }
  }

  return temp;
}