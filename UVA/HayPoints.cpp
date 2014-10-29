#include <iostream>
#include <math.h>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;
#define forn(i,a,b) for(int i=a;i<b;i++)
#define PB(x) push_back(x)
int main()
{
    //freopen("in.txt","r",stdin);//Leer desde archivo
    int a,b;
    map<string,long>d;//Crear un mapa de string a long
    scanf("%d %d",&a,&b);//Se leen las condiciones iniciales
    string k;
    long s;
    forn(i,0,a)
    {
        cin>>k>>s;//Se lee el string y el numero
        d[k]=s;//Se agregan al map
    }
    long sum=0;
    string ok;
    while(cin>>ok)//El cin lee por espacios "abc acg" lo leeria como "abc","acg"
    {
        if(ok==".")
        {
            printf("%ld\n",sum);//Se imprime el resultado
            sum=0;
            continue;
        }
        sum+=d[ok];//Se le suma el valor de cada palabra, si la palabra no esta en el map no se suma nada

    }
    return 0;
}
