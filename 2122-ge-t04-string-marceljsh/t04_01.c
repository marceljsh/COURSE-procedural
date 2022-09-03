// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Hutabarat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc)
{
  char line[255];
  int stretch;
  fgets( line, 255, stdin );
  scanf( "%d",   &stretch );
  line[strcspn(line, "\n\r")] = '\0';
  int num[ strlen( line ) ];

  if ( stretch > 255 || stretch < 0) { stretch %= 255; }
  for ( int i=0; i<strlen( line ) ; i++ ) {
    num[i] = line[i] + stretch;
    // if ( num[i] > 255 ) num[i] -= 255;
    printf( "%03d", num[i] );
  }
  printf("\n");
  
  return 0;

}
