#include <stdio.h>
int main()
{
    long int h,o;
    while(scanf("%ld %ld",&h,&o)==2)
        printf("%ld\n",(h>=o)? (h-o):(o-h));
    return 0;
}
