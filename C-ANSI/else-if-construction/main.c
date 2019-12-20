#include <stdio.h>



unsigned int binsearch(unsigned int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

unsigned int sbinsearch(unsigned int x, int v[], int n)
{
    int temp = n - 1;
    while(temp >= 0) 
    {
        if (v[temp] == x)
            return temp;
        else 
            --temp;
    }
    return -1;
}

void test_binsearch()
{
    int n = 20;
    int v[n];
    for (int i = 0; i < n; i++)
        v[i] = i;
    int x = 3;
    int result_x = binsearch(x, v, n);
    int result_y = sbinsearch(x, v, n);
    printf("%d\n", result_x);
    printf("%d\n", result_y);
}
int main()
{
    test_binsearch();
}