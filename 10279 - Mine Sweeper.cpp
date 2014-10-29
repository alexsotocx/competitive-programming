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
int dc[] = {-1,0,1,-1,1,-1,0,1};
int dr[] = {-1,-1,-1,0,0,1,1,1};
bool inside(int i,int j)
{
    return i>=0 && i<m && j>=0 && j<m;
}
vector<vector<int> >ret;

int main()
{
    int cases=0;
    scanf("%d",&cases);
    while(cases-- && scanf("%d",&m)==1)
    {


        x = vector<string>(m,"");
        vector<string>game(m,"");
        ret = vector<vector<int> >(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            string c;
            cin>>c;
            x[i]=c;
        }
        bool mine = false;
        for(int i=0; i<m; i++)
        {
            string c;
            cin>>c;
            game[i]=c;
            for(int j=0; j<m; j++)
                if(x[i][j]== '*' && game[i][j]=='x') mine = true;
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(game[i][j]=='x' && x[i][j]!='*')
                {
                    int c = 0;
                    for(int k=0; k<8; k++)
                    {
                        int u = i + dr[k];
                        int v = j + dc[k];
                        if(inside(u,v) && x[u][v]=='*') c++;
                    }
                    printf("%d",c);
                }
                else if(mine && x[i][j]=='*')
                    printf("*");
                else
                    printf(".");

            }
            printf("\n");
        }


        printf((cases)?"\n":"");

    }
    return 0;


}
