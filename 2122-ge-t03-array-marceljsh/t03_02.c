// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int biggest ( int x, int y ) { return (x > y) ? x : y; }
int smallest( int x, int y ) { return (x < y) ? x : y; }

int main(int _argc, char **_argv)
{

  int _size; scanf("%d", &_size);

  int num[_size];
  for (int i=0; i<_size; i++) { scanf("%d", &num[i]); }

  int SMALL = num[0];
  for (int i=0; i<_size; i++) { SMALL = smallest( SMALL, num[i] ); }
  printf("%d\n", SMALL);

  int BIG = num[0];
  for (int i=0; i<_size; i++) { BIG = biggest( BIG, num[i] ); }
  printf("%d\n", BIG);

  float AVE = 0;
  for (int i=0; i<_size; i++) { AVE += num[i]; }
  AVE /= _size;
  printf("%.2f\n", AVE);


  return 0;
}
