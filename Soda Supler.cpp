#include<stdio.h>
int bottles(int a,int b, int c)
{
    if(c>a+b)
        return 0;
    return ((a+b)/c) + bottles((a+b)/c,(a+b)%c,c);

}
int main()
{
    freopen("in.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int e,f,c;
        scanf("%d%d%d",&e,&f,&c);
        printf("%d\n",bottles(e,f,c));
    }
}
