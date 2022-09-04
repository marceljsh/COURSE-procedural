// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t {
  char id[10];
  char name[255];
  float gpa;
  char fmt[100];
};

struct student_t toStudent ( char* ID, char* NAME, float GPA );
// struct student_t fmt_str( struct student_t X );

int main(int _argc, char **_argv)
{

  char *token;
  char *command;
  char delim[2] = "#";
  char data[3][20];
  char userInput[100][255];
  struct student_t siswa[100];
  int idx = 0;
  // int len = 0;

  while ( 1 ) {
    scanf(" %[^\n]s", userInput[idx]);
    token = NULL;
    token = strtok(userInput[idx],delim);
    if (strcmp(token,"---") == 0) break;
    else if (strcmp(token,"student-show-all") != 0)idx++;

    // mengatasi \r\n
    // len = strlen(userInput[idx]);
    // for( int a = 0; a < len; a++ ) {
    //   if ( userInput[idx-1][a] == '\r' || userInput[idx-1][a] == '\n') {
    //     for( int b = a; b < len; b++) { userInput[idx-1][b] = userInput[idx-1][b + 1]; }
    //     len--; a--;	
    //   }
    // }

    command = token;
    if (strcmp(command,"student-show-all") == 0) {
      for (size_t i=0; i<idx; i++) { printf("%s\n",siswa[i].fmt); }
    }
    else if (strcmp(command,"student-add") == 0) {
      for (size_t i=0; i<3; i++) {
        token = strtok(NULL,delim);
        strcpy(data[i],token);
      }
      siswa[idx-1] = toStudent(data[0],data[1],strtof(data[2],NULL));
      // fmt_str(siswa[idx-1])
      sprintf( siswa[idx-1].fmt, "%s|%s|%.2f", data[0], data[1], strtof(data[2],NULL) );
    }

  }

  return 0;
}

struct student_t toStudent ( char* ID, char* NAME, float GPA )
{
  struct student_t siswa;
  strcpy( siswa.id, ID );
  strcpy( siswa.name, NAME );
  siswa.gpa = GPA;
  return (siswa);
  
}

// struct student_t fmt_str ( struct student_t X )
// {
//   sprintf( X.fmt, "%s|%s|%.2f", X.id, X.name, X.gpa );
//   return (X);
// }

// for ( size_t i=0; i<3; i++ ) {
//           token = strtok( NULL, delim );
//           strcpy( data[i], token );
//         }