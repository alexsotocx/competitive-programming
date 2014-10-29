#include<vector>
#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
vector<string> x;
int count;
int m,n;
vector<vector<bool> >visited;
int dc[] = {-1,0,1,-1,0,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,0,1,1,1};
bool inside(int i,int j)
{
    return i>=0 && i<m && j>=0 && j<n;
}
vector<vector<int> >ret;

int main()
{
    int cases=1;
    count =0;
    while(scanf("%d%d",&m,&n)==2 && m && n)
    {
        printf((count)?"\n":"");
        x = vector<string>(m,"");
        ret = vector<vector<int> >(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            string c;
            cin>>c;
            x[i]=c;
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<9; k++)
                {
                    int u = i+dr[k];
                    int v = j+dc[k];
                    if(inside(u,v) && x [u][v]=='*')
                        ret[i][j]++;
                }
            }
        }
        printf("Field #%d:\n",++count);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(x[i][j]=='*') printf("*");
                else printf("%d",ret[i][j]);

            }
            printf("\n");
        }

    }
    return 0;


}
