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

    e = 10;
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
int main()
{
    test_strcat();
    test_strend();
    test_strncat();
    test_strncpy();
    test_strncmp();
    return 0;
}