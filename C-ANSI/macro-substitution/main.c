#include <stdio.h>
#include <string.h>

#define paste(front, back) front ## back
#define swap(t,x,y) \
    x = x + y;\
    y = x - y;\
    x = x - y;\
    x = (t)x;
    
void test_paste()
{
    char *h = "Hello, ";
    char *w = "world!";
    char *hw;
    paste(h, w);
    printf("%s\n", hw);
}
void test_swap()
{
    int x, y;
    x = 5; 
    y = 2;
    swap(int, x, y);
    printf("%d\n", x);
    printf("%d\n", y);
}
int main()
{
    test_paste();
    test_swap();
}