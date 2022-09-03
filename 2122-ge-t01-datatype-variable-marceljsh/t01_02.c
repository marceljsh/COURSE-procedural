// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int main(int _argv, char **_argc)
{
  float num[4], total=0;
  for (int i=0; i<4; i++) { scanf("%f",&num[i]); }
  for (int i=0; i<4; i++) { total += num[i]; }
  
  printf("%.3f\n",total); printf("%.3f",total/4);

  return 0;
}
