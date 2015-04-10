#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={1,2,3,4,15,6,7};
    int *point;
    point=a;
    while(*point!=7)
    {
        printf("%d",*point);
        point++;
    }
    return 0;
}
