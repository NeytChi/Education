#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
 
void inputline(int count)
{
    int i, j;
    char c;
    
    char s[SIZE][SIZE];

    printf("enter a string with tab:\n");

    for (i = 0; c != '~'; i++) {
        for (j = 0; j < SIZE - 1 && (c = getchar()) != EOF && c != '\n'; ++j) {
            if (c == '~')
                break;
            s[i][j] = c;
        }
        s[i][j] = '\0';
    }
    if (count > i)
        count = 0;
    else
        count = i - count - 1;    
    for (; count  < i - 1; count++)
        printf("line %d) %s\n", count, s[count]);
}
void helps()
{
    printf("Usage pattern: tail -[operation];\r\n");
    printf("-h - help info;\r\n");
    printf("-[1..n] - count of last lines.\r\n");
}
int main(int argc, char *argv[])
{
    int i, n;
    char c;

    i = 1; c = 4;
    if (argc < 2)
        helps();
    
    if (argc > i)
    {
        while(--argc > 0 && ((c = (*++argv)[0]) == '-')) {
            switch (c)
            {
                case '-':
                    n = atoi(*argv);
                    if (n == 0)
                        n = 0;
                    n = -n;
                    break;
                case 'h':
                    helps();
                    break;
                default:
                    break;
            };
        }
    }
    inputline(n);
    return 0;
}