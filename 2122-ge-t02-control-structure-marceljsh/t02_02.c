// 12S20003 - Marcel Joshua
// 12S20040 - Esphi Aphelina Hutabarat

#include <stdio.h>

int main(int _argv, char **_argc)
{
    int choice;
    char _out[10][30] = { "milk","fruits","vegetables","side dishes","staple food",
                          "you need side dishes","you need vegetables","good","very good","perfect" };
    scanf("%d",&choice);
    for (int i=5-choice; i<5; i++) { printf("%s\n",_out[i]); }
    printf("%s\n\n",_out[choice+4]);

    return 0;

}
