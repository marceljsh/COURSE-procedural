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

int main ( int _argc, char **_argv )
{

  char *token;
  char *command;
  char delim[2] = "#";
  char data[3][100];
  char userInput[100][255];
  struct student_t siswa[100];
  int idx = 0;
  int len = 0;

  while ( 1 ) {
    scanf( " %[^\n]s", userInput[idx] );
    // fgets( userInput[idx], 255, stdin );
    // gets(userInput[idx]);

    len = strlen(userInput[idx]);
    for( int a = 0; a < len; a++ ) {
      if ( userInput[idx][a] == '\r' || userInput[idx][a] == '\n') {
        for( int b = a; b < len; b++) { userInput[idx][b] = userInput[idx][b + 1]; }
        len--; a--;	
      }
    }

    token = NULL;
    if ( strcmp( userInput[idx], "---" ) == 0 ) break;
    else if ( strcmp( userInput[idx], "student-show-all" ) == 0 ) {
      for ( size_t i=0; i<idx; i++ ) { puts( siswa[i].fmt ); }
    }
    else {
      idx++;
      token = strtok( userInput[idx-1], delim );
      command = token;
      if ( strcmp( command, "student-add" ) == 0 ) {
        
        for ( size_t i=0; i<3; i++ ) {
          token = strtok( NULL, delim );
          strcpy( data[i], token );
        }

        siswa[idx-1] = toStudent( data[0], data[1], strtof( data[2], NULL ) );
        // fmt_str(siswa[idx-1])
        sprintf( siswa[idx-1].fmt, "%s|%s|%.2f", data[0], data[1], strtof(data[2], NULL ) );
      }
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

// mengatasi \r\n
    // len = strlen(userInput[idx]);
    // for( int a = 0; a < len; a++ ) {
    //   if ( userInput[idx-1][a] == '\r' || userInput[idx-1][a] == '\n') {
    //     for( int b = a; b < len; b++) { userInput[idx-1][b] = userInput[idx-1][b + 1]; }
    //     len--; a--;	
    //   }
    // }