// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Hutabarat

#include <stdio.h>
#include <string.h>

struct Student {
  char name[255];
  char id[9];
  char year[5];
  char sex[7];
};

int main ( int _argv, char **_argc )
{
  char *token;
  char order[10];
  char delim[2] = "|";
  char line[10][255];
  int i=0;
  int keepGoing=1;
  struct Student students[10];
  scanf("%[^\n]s", order);
  int len = strlen(order);
  int a,b;

  for(a = 0; a < len; a++)
  {
    
    if(order[a] == '\r' || order[a] == '\n')
    {
      for(b = a; b < len; b++)
      {
        order[b] = order[b + 1];
      }
      len--;
      a--;	
    }
     
  }

  if ( strcmp(order, "register") == 0 ) {
    while ( keepGoing == 1 ) {
      // scanf("%[^\n]s",line[i]);
      // fgets(line[i],255,stdin);
      scanf("%s", line[i]);
      // line[i][strcspn(line[i], "\r\n")] = '\0';
      for (int o=0; o<strlen(line[i]); o++) {
        if (line[i][o] == '\r'||line[i][o] == '\n') { line[i][o]='\0'; }
      }

      if (strcmp(line[i],"---")==0) keepGoing = 0;
      else i++;
    }
    for ( int o=0; o<i; o++) {
      token = strtok( line[o], delim );
      strcpy( students[o].name, token );
      token = strtok( NULL, delim );
      strcpy( students[o].id, token );
      token = strtok( NULL, delim );
      strcpy( students[o].year, token );
      token = strtok( NULL, delim );
      strcpy( students[o].sex, token );
    }

    int male=0, female=0;
    int maleList[10];
    int femaleList[10];
    for (int o=0; o<i; o++) {
      if ( strcmp( students[o].sex, "MALE" ) == 0 ) {
        maleList[male] = o;
        male++;
      }
      else if ( strcmp( students[o].sex, "FEMALE" ) == 0) {
        femaleList[female] = o;
        female++;
      }
    }

    printf("%d|%d\n", male, female);

    if (male>0&&female>0) {
      for (int x=0; x<male; x++) { printf("%s|", students[maleList[x]].name); }
      printf("\n");
      for (int x=0; x<female; x++) { printf("%s|", students[femaleList[x]].name); }
    }
    else if (male>0&&female<1) { for (int x=0; x<male; x++) { printf("%s|", students[maleList[x]].name); } }
    else if (male<1&&female>0) { for (int x=0; x<female; x++) { printf("%s|", students[femaleList[x]].name); } }
  }
  else { puts("0|0"); }
  
  return 0;

}
