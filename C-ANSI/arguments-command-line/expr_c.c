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
short negative = 0;

/*int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}*/
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
    else 
        printf("error: stack empty\n");
    return 0.0;
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
    printf("parameter - %s\n", s);
    int i, c;

    i = 0;
    
    while ((c = s[i++]) == ' ' || c == '\t')
        ;
    
    if (!isdigit(c) && c != '.' && c != '-')
    {
        s[i] = '\0';
        return c;
    }
    if (c == '-')
    {
        --i;
        c = '0';
        negative = 1;
    }
    if (isdigit(c))
        while (isdigit(c = s[i++]))   
            ;
    if (c == '.')
        while(isdigit(c = s[i++]))
            ;
    //s[i] = '\0';
    //if (c != EOF)
        //ungetch(c);
    return NUMBER;
}
void helps(char s[])
{
    if (s[0] == '-' && s[1] == 'h')
    {
        printf("expr options:\n");
        printf("[number-1] [number-N] [operation-1] [operation-N]\n");
        printf("available operations: - '+' '-' '*' '/' '%c')\n", '%');
    }
}
void getresult()
{
    double v = pop();
    printf("\t%.8g\n", v);
    push(v);
}
int main(int argc, char *argv[])
{
    int type, i;
    double op2;
    char s[MAXOP];
    
    i = 1;
    if (argc >= i) 
        helps(argv[i]);
    while(i < argc) {
        type = getop(argv[i]);
        switch(type) {
            case NUMBER:
                push(atof(argv[i]));
                break;
            case '+':
                push(pop() + pop());
                getresult();
                break;
            case 'x':
                push(pop() * pop());
                getresult();
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                getresult();
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                    getresult();
                }
                else
                    printf("error: zero divisor.\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(((int)pop()) % ((int)op2));
                    getresult();
                }
                else
                    printf("error: zero divisor.\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
        ++i;
    }
    return 0;
}