#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10
 
void detab(int count, int m)
{
    int i, j;
    char c;
    char s[SIZE];

    printf("enter a string with tab:\n");

    for (i = 0; i < SIZE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    printf("input: \t%s\n", s);

    
    for (j = m; j < i; j++)
    {
        if (s[j] == '\t')
        {
            for (int x = i; x > j; x--) {
                if (x + count <= SIZE)
                    s[x + count] = s[x];
            }
            for (int v = 0; v < count + 1; v++)
                s[j + v] = '_';
        }
    }
    printf("result: %s\n", s);  
}
void test_arr()
{
    int i, j, c, r, a;
    
    a = 3; c = 4; r = 5;
    int arr[c][r];
    
    for (i = 0; i < c; i++)
        for (j = 0; j < r; j++) {
            arr[i][j] = a;
            a = arr[i][j] * 2;
        }
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) 
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}
void helps()
{
    printf("Usage pattern: detab -[operation];\r\n");
    printf("-h - help info;\r\n");
    printf("-c [1..n] - count of tab's space.\r\n");
}
int main(int argc, char *argv[])
{
    int i, count, m;
    char c;

    i = 1; count = 4; m = 0;
    if (argc < 2)
        helps();
    
    if (argc > i)
    {
        while(--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+')) {
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
            switch (c)
            {
                case '+':
                    count = atoi(*argv);
                    if (count == 0)
                        count = 4;
                    break;
                case '-':
                    m = atoi(*argv);
                    if (m == 0)
                        m = 4;
                    break;
                
                default:
                    break;
            }
        }
    }
    detab(count - 1, m);
    test_arr();
    return 0;
}