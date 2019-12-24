#include <stdio.h>

void strcat(char *s, char *t)
{
    while(*s++ != '\0')
        ;
    *s--;
    while((*s++ = *t++) != '\0')
        ;
}
void test_strcat()
{
    char sa[] = "Hello, ";
    char ta[] = "world!\n";
    strcat(sa, ta);
    printf("%s", sa);
} 
/// * * * *
/// 24.12.2019 - Can be improve and simplified
/// * * * *
int strend(char *s, char *t)
{
    int e;

    e = 0;
    while(*s != '\0')
    {
        if (e == 1) {
            if (*s++ != *++t)
                return 0;
        }
        else if (*s++ == *t)
            e = 1;
    }
    return e;
}
void test_strend()
{
    char sa[] = "ssh_connect";
    char ta[] = "connect";
    char fa[] = "lose";
    printf("test_strend:\n");
    printf("input: %s\n", sa);
    printf("end 1: %s\n", ta);
    printf("end 2: %s\n", fa);
    int t = strend(sa, ta);
    int f = strend(sa, fa);
    printf("result: %d\n", t);
    printf("result: %d\n", f);
}
int strncmp(char *s, char *t, int n)
{
    while (n-- > 0)
        if (*s++ != *t++)
            return 0;
    return 1;
}
void test_strncmp()
{
    int t, f;
    char sa[] = "Hello, ";
    char ta[] = "world!\n";
    printf("test_strncmp:\n");
    printf("input: %s\n", sa);
    printf("cmp 1: %s\n", sa);
    printf("cmp 2: %s\n", ta);    
    t = strncmp(sa, sa, 3);
    f = strncmp(sa, ta, 3);
    printf("result: %d\n", t);
    printf("result: %d\n", f);
} 
void strncat(char *s, char *t, int n)
{
    while (*s++ != '\0')
        ;
    *s--;
    while (n-- > 0)
        *s++ = *t++; 
    *s++ = '\0'; 
}
void test_strncat()
{
    char sa[] = "Hello, ";
    char ta[] = "world!\n";
    printf("test_strncat:\n");
    strncat(sa, ta, 3);
    printf("%s\n", sa);
} 
void strncpy(char *s, char *t, int n)
{
    while (n-- > 0)
        *s++ = *t++;
}
void test_strncpy()
{
    char sa[] = "Hello, ";
    char ta[] = "world!\n";
    printf("test_strncpy:\n");
    strncpy(sa, ta, 3);
    printf("%s\n", sa);
} 
void reverse(char *s)
{
    int c, i, j;

    j = 0;
    while (s[j++] != '\0')
        ;
    for (i = 0, j = j - 2; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void test_reverse()
{
    char s[] = "Hello, world!";
    printf("test_reverse:\n");
    printf("input: \t%s\n", s);
    reverse(s);
    printf("result: \t%s\n", s);
}
void itoa(long n, char *s)
{
    long i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do 
        s[i++] = n % 10 + '0';
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void test_itoa()
{
    char s[7];
    long n = -123456;
    printf("\ntest_itoa:\n");
    printf("input: \t%ld\n", n);
    itoa(n, s);
    printf("result: %s\n", s);
}
int isspace(char a)
{
    return a == ' ' ? 1 : 0;
}
int isdigit(char a)
{
    return a >= '0' && a <= '9' ? 1 : 0;
}
double atof(char *s)
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
void test_atof()
{
    double r;
    char s[25] = "-1323.1234";

    printf("test_atof:\n");
    r = atof(s);
    printf("result: %f\n", r);
}
int getline(char *s, int lim)
{
    int c, i;
    
    i = 0;
    while(--lim > 0 && ((c = getchar()) != EOF && c != '\n'))
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] ='\0';
    return i + 1;
}
void test_getline()
{
    int c, lim;
    lim = 20;
    char s[lim];

    printf("test_getline:\n");
    c = getline(s, lim);
    printf("line size: %d\n", c);
}
int strindex(char *s, char *t)
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
void test_strindex()
{
    char s[] = "Hello, world!";
    char t[] = "world!";
    printf("\test_strindex:\n");
    printf("input: %s\n", s);
    printf("input: %s\n", t);
    int a = strindex(s, t);
    printf("result: %d\n", a);
}
int main()
{
    test_strcat();
    test_strend();
    test_strncat();
    test_strncpy();
    test_strncmp();
    test_reverse();
    test_itoa();
    test_atof();
    test_getline();
    test_strindex();
    return 0;
}