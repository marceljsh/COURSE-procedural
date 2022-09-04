// 12S20003 - Marcel Joshua

#include <stdio.h>
#include <string.h>

// a,a,a,c,c,b,b,b,z,d\r\n
int main()
{
    char inp[255];
    gets(inp);
    int coma = strlen(inp);			// 23
    int foo;
    int amount=0;
    for (int i = 0; i < coma; i++)
    {   
        if (inp[i]==','){
           amount++;				// 10
        }
    }
    amount++;
    
    char line[coma-amount];
    int buff=0;
    for (int i = 0; i < coma; i++)
    {   
        if (inp[i]!=','){
           line[buff]=inp[i];
           buff++;
        }
    }
    for (int i = 0; i < amount; i++)
    {
        for(int buff = i + 1; buff < amount; buff++)
        {
            if (line[i] > line[buff])
            {
                foo = line[i];
                line[i] = line[buff];
                line[buff] = foo;
            }
        }
    }
    for (int i = 0; i < amount; i++)
    {
        if (i == amount-1) printf("%c", line[i]);
        else printf("%c,", line[i]);
    }

    return 0;
}