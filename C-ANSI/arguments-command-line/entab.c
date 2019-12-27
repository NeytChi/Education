#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

void entab(int count)
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
            if (sp == j + count)
            {
                for (x = j + 1; x < i - count + 1; x++)
                    s[x] = s[x + count];
                s[j] = '\t';   
            }
        }
    printf("result: %s\n", s);  
}
void helps()
{
    printf("Usage pattern: entab -[operation];\r\n");
    printf("-h - help info;\r\n");
    printf("-c [1..n] - count of tab's space.\r\n");
}
int main(int argc, char *argv[])
{
    int i, count;

    i = 1; count = 4;
    if (argc < 2)
        helps();
    
    if (argc > i)
    {
        while(--argc > 0 && (*++argv)[0] == '-') {
            switch ((*argv)[1])
            {
                case 'c':
                    count = atoi(*++argv);
                    *--argv;
                    if (count == 0)
                        count = 4;
                    break;
                case 'h':
                    helps();
                    break;
                default:
                    break;
            };
        }
    }
    entab(count - 1);
    return 0;
}