#include <stdio.h>
#include <string.h>

#define COUNT 0
#define SIZE 10
 
void detab()
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

    
    for (j = 0; j < i; j++)
    {
        if (s[j] == '\t')
        {
            for (int x = i; x > j; x--) {
                if (x + COUNT <= SIZE)
                    s[x + COUNT] = s[x];
            }
            for (int v = 0; v < COUNT + 1; v++)
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
int main(int argc, char *argv[])
{
    detab();
    test_arr();
    return 0;
}