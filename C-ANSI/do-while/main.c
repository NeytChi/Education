#include <stdio.h>
#include <string.h>
#include <limits.h>

void printchars(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        printf("%c", s[i]);
    printf("\n");
}
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printchars(s);
}
void itoa(unsigned long n, char s[])
{
    unsigned long i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    return reverse(s);
}
void itoa_w(unsigned long n, char s[], int w)
{
    unsigned long i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    for (; i < w; i++)
        s[i] = ' ';
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void test_dowhile()
{
    int c = 5;
    int st = 16;
    int et = 8;
    int tt = 3;
    unsigned long n = ULONG_MAX;
    printf("%lu\n", n);
    char s[c];
    itoa(n, s);
    itoa_w(n, s, 5);

}
int main()
{
    test_dowhile();
}