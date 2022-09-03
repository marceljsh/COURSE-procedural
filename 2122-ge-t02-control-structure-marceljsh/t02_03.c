// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int main(int _argv, char **_argc)
{
  int koef,var;
  char operator;
  scanf("%c",&operator);

  switch ( operator )
  {
    case '+':
      scanf("%d",&var);
      if ( var == -1 ) { printf("0"); break; }
      koef = var;
      printf("%d\n",koef);

      for (int i=0; i<3; i++) {
        scanf("%d",&var);
        if ( var == -1 ) { printf("0"); break; }
        koef += var;
        printf("%d\n",koef);
      }
      break;
    
    case '-':
      scanf("%d",&var);
      if ( var == -1 ) { printf("0"); break; }
      koef = var;
      printf("%d\n",koef);

      for (int i=0; i<3; i++) {
        scanf("%d",&var);
        if ( var == -1 ) { printf("0"); break; }
        koef -= var;
        if ( koef < 0 ) { koef = -koef; }
        printf("%d\n",koef);
      }
      break;
    
    case '*':
      scanf("%d",&var);
      if ( var == -1 ) { printf("0"); break; }
      koef = var;
      printf("%d\n",koef);

      for (int i=0; i<3; i++) {
        scanf("%d",&var);
        if ( var == -1 ) { printf("0"); break; }
        koef *= var;
        printf("%d\n",koef);
      }
      break;
  }

  printf("\n");


  return 0;
}
