#include <stdio.h>


void juniorseven(int n)
{
    printf("input number: %d\n", n);
    n = n & 0177;
    printf("junior seven: %d\n", n);
}

void juniorsix(int n)
{
    printf("input number: %d\n", n);
    n = n & 077;
    printf("junior six: %d\n", n);
}

void shiftright(int n)
{
    printf("input number: %d\n", n);
    n = n >> 1;
    printf("shift right: %d\n", n);
}

void shiftleft(int n)
{
    printf("input number: %d\n", n);
    n = n << 1;
    printf("shift left: %d\n", n);
}

void singleoperation(int n)
{
    printf("input number: %d\n", n);
    n = n & ~ 077;
    printf("single operation: %d\n", n);
}

void viewbinary(unsigned int b) 
{
    printf("input: %d\n", b);
    for (int i = 0; i < 8; i++) 
    {
        printf("%c", (b & 0x80) ? '1' : '0');
        b <<= 1;
    }
    printf("\n");
}
unsigned int getbits(unsigned int x, int p, int n)
{
    return x >> (p + 1 -n) & ~(~0 << n);
}
//
// Get query of bits x and y. Set in query x, n bit, 
// from position p, that gets from query y with same position and bits length.
//
unsigned int setbits(unsigned int x, int p, int n , unsigned int y)
{
    unsigned int y1 = (y >> (p + 1 -n) & ~(~0 << n)) << (p + 1 - n);
    unsigned int y2 = ~((~0 >> (p + 1 -n) & ~(~0 << n)) << (p + 1 - n));
    return x & y2 | y1;
}
unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int x1 = ~((x >> (p + 1 -n) & ~(~0 << n)) << (p + 1 - n));
    unsigned int y = ~((~0 >> (p + 1 -n) & ~(~0 << n)) << (p + 1 - n));
    return x & y | x1;
}
unsigned int rightrot(unsigned int x, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = x >> 7;
        x = x << 1 | temp;
    }
    return x;
}
void test_getbits()
{
    printf("get bits:\n");
    unsigned int x = 223;
    int p = 6;
    int n = 3;
    viewbinary(x);
    viewbinary(p);
    viewbinary(n);    
    x = getbits(x, p, n);
    printf("result x: %d\n", x);
    viewbinary(x);
}
void test_setbits()
{
    printf("\nset bits:\n");
    unsigned int x = 223;
    int p = 6;
    int n = 3;
    unsigned int y = 193;
    viewbinary(x);
    viewbinary(p);
    viewbinary(n);    
    viewbinary(y);
    x = setbits(x, p, n, y);
    viewbinary(x);
}
void test_invert()
{
    printf("\ninvert:\n");
    unsigned int x = 223;
    int p = 6;
    int n = 3;
    viewbinary(x);
    viewbinary(p);
    viewbinary(n);
    x = invert(x, p, n);
    viewbinary(x);
}
void test_rightrot()
{
    printf("\nright rotation:\n");
    unsigned int x = 223;
    int n = 4;
    viewbinary(x);
    viewbinary(n);
    x = rightrot(x, n);
    viewbinary(x);
}
void test_bitoperatons()
{
    juniorseven(11110000);
    juniorsix(11110000);
    shiftright(88);
    shiftleft(11);
    singleoperation(11110000);
}
int main()
{
    test_bitoperatons();
    test_getbits();
    test_setbits();
    test_invert();
    test_rightrot();
}