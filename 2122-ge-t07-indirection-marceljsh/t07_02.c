// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Hutabarat

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    struct dorm_t dorms[5];
    struct student_t students[10];

    dorms[0] = create_dorm("Pniel", 4, GENDER_FEMALE);
    dorms[1] = create_dorm("Kapernaum", 3, GENDER_MALE);

    print_dorm(dorms[0]);
    print_dorm(dorms[1]);

    students[0] = create_student("12S21001", "Dhino Turnip", "2021", GENDER_MALE);
    students[1] = create_student("12S21002", "Marudut Tampubolon", "2021", GENDER_MALE);
    students[2] = create_student("12S21003", "Jusas Tampubolon", "2021", GENDER_MALE);
    students[3] = create_student("12S21004", "Estomihi pangaribuan", "2021", GENDER_MALE);
    students[4] = create_student("12S21006", "Weny Sitinjak", "2021", GENDER_FEMALE);
    students[5] = create_student("12S21007", "Dame Sitinjak", "2021", GENDER_FEMALE);
    students[6] = create_student("12S21008", "Tuani Manurung", "2021", GENDER_MALE);
    students[7] = create_student("12S21009", "Mikhael Pakpahan", "2021", GENDER_MALE);
    students[8] = create_student("12S21010", "Bobby Siagian", "2021", GENDER_MALE);
    students[9] = create_student("12S21011", "Aldi Simamora", "2021", GENDER_MALE);

    print_student(students[0]);
    print_student(students[4]);
    print_student(students[8]);

    /* defined by me - start */
    for ( size_t i=0; i<10; i++ ) {
        students[i].gender == GENDER_MALE?
            assign_dorm( &students[i], &dorms[1] ):
            assign_dorm( &students[i], &dorms[0] );
    }
    /* defined by me - end */

    print_student(students[0]);
    print_student(students[1]);
    print_student(students[2]);
    print_student(students[3]);
    print_student(students[4]);
    print_student(students[5]);
    print_student(students[6]);
    print_student(students[7]);
    print_student(students[8]);
    print_student(students[9]);

    print_dorm(dorms[0]);
    print_dorm(dorms[1]);

    return 0;
}
