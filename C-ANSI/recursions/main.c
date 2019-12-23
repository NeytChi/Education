#include <stdio.h>
#include <string.h>

void reverse_r(char s[], int i, int l)
{
    if (i < l / 2)
        reverse_r(s, i + 1, l);
    s[i] = s[i] + s[l - i];
    s[l - i] = s[i] - s[l - i];
    s[i] = s[i] - s[l - i];
}
void reverse_w(char s[])
{
    int i = 0;
    int l = strlen(s) - 1;
    while (i < l / 2) {
        s[i] = s[i] + s[l - i];
        s[l - i] = s[i] - s[l - i];
        s[i] = s[i] - s[l - i];
        ++i;
    }
    for (int i = 0; i < strlen(s); i++)
        printf("%c",s[i]);
}
void itoa(int n)
{
    if (n < 0) {
        printf("-");
        n = -n;
    }
    if (n / 10) 
        itoa(n / 10);
    printf("%d", n % 10);
}

void testitoa()
{
    itoa(12345);
    printf("\n");
    itoa(-12345);
    printf("\n");
    char s[5];
    s[0] = '1';
    s[1] = '2';
    s[2] = '3';
    s[3] = '4';
    s[4] = '5';
    reverse_w(s);
    printf("\n");
    reverse_r(s, 0, strlen(s) - 1);
    printf("reverse_r:\n");
    for (int i = 0; i < strlen(s); i++)
        printf("%c",s[i]);
    printf("\n");
}

int main()
{
    testitoa();
    return 0;
}