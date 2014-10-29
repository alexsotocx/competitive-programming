#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        string aux;
        cin>>aux;
        sort(aux.begin(),aux.end());
        do
        {
            printf("%s\n",aux.c_str());
        }while(next_permutation(aux.begin(),aux.end()));
        printf("\n");
    }
}
