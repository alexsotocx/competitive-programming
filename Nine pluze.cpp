#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
typedef vector<vector<int> > vii;
map<vii, bool> visited;
map<vii, string> le;
vii final(3,vector<int>(3,0));
vii H(vii k,int row)
{
    int aux = k[row][0];
    k[row][0]= k[row][2];
    int aux2 = k[row][1];
    k[row][1]= aux;
    k[row][2]=aux2;
    return k;
}
vii V(vii k,int col)
{
    int aux = k[0][col];
    k[0][col]= k[2][col];
    int aux2 = k[1][col];
    k[1][col]= aux;
    k[2][col]=aux2;
    return k;
}
bool equal(vii &x, vii &y)
{
    for(int i=0;i<3; i++)
        for(int j=0;j<3;j++)
            if(x[i][j]!= y[i][j]) return false;

    return true;
}
void imprimir(vii &x)
{
    for(int i=0;i<3; i++){
        for(int j=0;j<3;j++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
}
void bfs(vii s)
{
    queue<vii >q;
    queue<string>cost;
    q.push(s);
    cost.push("");
    visited[s]=1;
    imprimir(s);
    while(!q.empty())
    {
        vii  x = q.front();
        q.pop();
        string w = cost.front();
        cost.pop();
        //cout<<w<<endl;
        for(int i=0; i<3; i++)
        {
            vii aux = H(x,i);
            if(!visited[aux])
            {
                string t = w+'H' + (char)((i+1)+'0');
                le[aux]=t;
                q.push(aux);
                visited[aux]=1;
                cost.push(t);
            }

            vii aux2 = V(x,i);
            if(!visited[aux2])
            {
                string t = w+'V' + (char)((i+1)+'0');
                le[aux2]=t;
                q.push(aux2);
                visited[aux2]=1;
                cost.push(t);
            }
        }
    }


}
int main()
{
    final[0][0]=1;
    final[0][1]=2;
    final[0][2]=3;
    final[1][0]=4;
    final[1][1]=5;
    final[1][2]=6;
    final[2][0]=7;
    final[2][1]=8;
    final[2][2]=9;
    bfs(final);
    while (true)
    {
        vii x(3, vector<int>(3,0));
        bool lol = false;

        for(int i=0; i<3 && !lol; i++)
            for(int j=0; j<3 && !lol; j++)
            {
                scanf("%d",&x[i][j]);
                if(!x[i][j]) lol=true;
            }
        if(lol) break;
        if(le.find(x)!=le.end())printf("%d %s\n",le[x].length()/2, le[x].c_str());
        else printf("Not solvable");

    }
    return 0;
}
