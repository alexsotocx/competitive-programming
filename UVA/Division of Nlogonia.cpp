#include<iostream>
#include<cstdio>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int cx,cy;
        scanf("%d%d",&cx,&cy);
        while(n--)
        {
            int px,py;
            scanf("%d%d",&px,&py);
            if(px==cx || py==cy)
                printf("divisa\n");
            else if(px>cx && py>cy)
                printf("NE\n");
            else if(px>cx && py<cy)
                printf("SE\n");
            else if(px<cx && py<cy)
                printf("SO\n");
            else
                printf("NO\n");

        }

    }
    return 0;
}
