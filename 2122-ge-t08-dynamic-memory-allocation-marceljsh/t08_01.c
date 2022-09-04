// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Hutabarat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    student_t *students = malloc(12 * sizeof(student_t));
    unsigned short totalStudent = 0;
    char line[255];
    char delim[2] = "#";
    char* token;
    char* _id;
    char* _name;
    char* _year;

    while ( 1 )
    {
        line[0] = '\0';
        fgets(line, 255, stdin);

        /* declared in scope level --> temporary
           but the result remains */
        {
            int len = strlen(line);
            for (size_t a = 0; a < len; a++) {
                if(line[a] == '\r' || line[a] == '\n') {
                    for(size_t b = a; b < len; b++) { line[b] = line[b + 1]; }
                    len--;
                    a--;
                }
            }
        }

        
        if ( strcmp(line, "---") == 0 ) break;
        else if ( strcmp(line, "student-print-all") == 0 ) {
            for (size_t i=0; i<totalStudent; i++) {
                print_student(students[i]);
            }
        }
        else {
            token = strtok(line, delim);
            if ( strcmp(token,"student-add") == 0 ) {
                token = strtok(NULL, delim); _id = token;
                token = strtok(NULL, delim); _name = token;
                token = strtok(NULL, delim); _year = token;
                
                token = strtok(NULL, delim);
                if ( strcmp(token, "male") == 0 ) {
                    students[totalStudent] = create_student(_id, _name, _year, GENDER_MALE);
                    totalStudent++;
                }
                else if ( strcmp(token, "female") == 0 ) {
                    students[totalStudent] = create_student(_id, _name, _year, GENDER_FEMALE);
                    totalStudent++;
                }
            }
        }
        
    }
    
    

    return 0;
}
