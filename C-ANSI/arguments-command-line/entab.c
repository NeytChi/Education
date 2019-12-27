#include <stdio.h>
#include <string.h>

#define COUNT 3
#define SIZE 20
 
void entab()
{
    int i, j, sp, v, x;
    char c;
    char s[SIZE];

    printf("enter a string with space:\n");

    for (i = 0; i < SIZE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    printf("input: \t%s\n", s);

    for (j = 0; j < i; j++)
        for (sp = j; s[sp] == ' '; ++sp)
        {
            if (sp == j + COUNT)
            {
                for (x = j + 1; x < i - COUNT + 1; x++)
                    s[x] = s[x + COUNT];
                s[j] = '\t';   
            }
        }
    printf("result: %s\n", s);  
}
int main(int argc, char *argv[])
{
    entab();
    return 0;
}