// 12S20003 - Marcel Joshua

#include <stdio.h>
#include <string.h>

// a,a,a,c,c,b,b,b,z,d\r\n
void swap(char *a, char *b );
void sort(char *word);

int main()
{
    char satu[200];
    char dua[200];
    fgets(satu,100,stdin);
    dua[0] = satu[0];
    for (int i=2; i<strlen(satu)-5; i+=2) {
        dua[i/2] = satu[i];
        // printf("%c ", dua[i]);
    }
    dua[strlen(dua)] = '\0';
    for (int i=0; i<strlen(dua); i++) { printf("%c",dua[i]);}
    printf("\n%ld",strlen(dua));
    sort(dua);
    printf("\n");
    for (int i=0; i<strlen(dua); i++) {
        if (i==strlen(dua)-1) printf("%c",dua[i]);
        else printf("%c,",dua[i]);
    }
    
    

    return 0;
}

void swap(char *a, char *b )
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort(char *word)
{
	for (unsigned int i = 0; i < strlen(word) - 1; i++)
		for (unsigned int j = i + 1; j < strlen(word); j++)
			if (word[i] > word[j]) 
				swap(&word[i], &word[j]); // simply swap the characters
}