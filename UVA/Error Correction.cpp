#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int> >x;
    int n;

    while(scanf("%d",&n)==1 && n)
    {
        x=vector<vector<int> >(n,vector<int> (n,0));
        int filas,columnas,f,c;
        filas=columnas=f=c=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&x[i][j]);
                sum+=x[i][j];
            }
            if((sum & 1)==1){filas++;f=i;}
        }
        if(n==1 && filas==1) {printf("Change bit (1,1)\n");continue;}
        else if(n==1 && filas==0) {printf("Ok\n");continue;}
        if(filas>1) {printf("Corrupt\n");continue;}
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=x[i][j];
            }
            if((sum & 1)==1){columnas++;c=j;}
        }
        if(columnas>1) {printf("Corrupt\n");continue;}
        if(!columnas && !filas){printf("Ok\n");continue;}
        printf("Change bit (%d,%d)\n",f+1,c+1);

    }

    return 0;
}
