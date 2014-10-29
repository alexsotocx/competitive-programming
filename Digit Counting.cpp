#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x[10]={0};
        int num;
        scanf("%d",&num);
        for(int i=1;i<=num;i++)
        {
            int aux =i;
            while(aux>0)
            {
                x[aux%10]++;
                aux/=10;
            }
        }
        printf("%d",x[0]);
        for(int i=1;i<10;i++)
            printf(" %d",x[i]);
        printf("\n");
    }
}
