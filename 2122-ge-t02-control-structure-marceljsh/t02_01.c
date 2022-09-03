// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int main(int _argv, char **_argc)
{
  int num, price;
  float subtotal;

  scanf("%d",&num);
  scanf("%d",&price);
  subtotal = num*price;

  if ( subtotal >= 50000 && subtotal <= 100000 ) { printf("%.2f\n%.2f",subtotal*0.05,subtotal*(1-0.05)); }
  else if ( subtotal > 100000 && subtotal < 500000 ) { printf("%.2f\n%.2f",subtotal*0.1,subtotal*(1-0.1)); }
  else if ( subtotal > 500000 ) { printf("%.2f\n%.2f",subtotal*0.15,subtotal*(1-0.15)); }
  else { printf("---\n%.2f",subtotal); }
  
  return 0;

}
