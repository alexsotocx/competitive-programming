#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string k;
    while(cin>>k)
    {
        int x = -1;
        for(int i=0;i<10 && x==-1;i++)
        {
            string aux = "";
            aux+= (char)(i+'0');
            x=k.find(aux);
        }

        if (x!=-1) cout<<"Encoded";
    }
    return 0;
}
