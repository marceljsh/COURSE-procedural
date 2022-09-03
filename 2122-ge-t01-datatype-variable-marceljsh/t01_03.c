// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int main(int _argv, char **_argc)
{
  int num[3];
  for (int i=0; i<3; i++) { scanf("%d",&num[i]); };
  num[0] = num[0] >> num[1];

  printf("%d\n",num[0]); printf("%d\n",num[2]==num[0]);
  
  return 0;
}
