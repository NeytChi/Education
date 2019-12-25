#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP  100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
void push(double);
double pop(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
short negative = 0;
short single = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void push(double f)
{
    if (sp < MAXVAL)
    {
        if (negative == 1)
        {
            val[sp++] = -f;
            negative = 0;
        }
        else
            val[sp++] = f;
    }
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
int isdigit(char s)
{
    if (s >= '0' && s <= '9')
        return 1;
    else
        return 0;
}
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-')
    {
        --i;
        c = '0';
        negative = 1;
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))   
            ;
    if (c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
void helps()
{
    printf("expr options:\n");
    printf("[number-1][number-N][operation-1][operation-N]\n");
    printf("available operations: - '+' '-' '*' '/' '%c' 's'(sin) 'e'(exp) 'p'(pow))\n", '%');
}
int main(int argc, char *argv[])
{
    int type, i;
    double op2;
    char s[MAXOP];

    i = 0;
    helps();
    while((type = getop(argv[i++])) < argc) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                single = 1;
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor.\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(((int)pop()) % ((int)op2));
                else
                    printf("error: zero divisor.\n");
                break;
            case '\n':
                if (single == 0)
                    printf("\t%.8g\n", pop());
                else
                    single = 0;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}