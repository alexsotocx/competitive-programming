#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

class team
{
public:
    string name;
    string nameM;
    int goaldiff;
    int matches;
    int wins;
    int tie;
    int loses;
    int goalscored;
    int goalsagainst;
    int points;
public:
    team() {}
    team(string name)
    {
        this -> name = name;
        goaldiff =  matches = points = wins=tie=loses = goalscored=goalsagainst = 0;
        nameM = name;
        transform(nameM.begin(), nameM.end(), nameM.begin(), ::toupper);
    }
    void mod(int a,int b)
    {
        goalscored+=a;
        goalsagainst += b;
        goaldiff+=(a-b);
        matches++;
        if(a==b)
            tie++,points++;
        else if(a>b)
            wins++,points+=3;
        else
            loses++;


    }
};
bool comp(const team &a, const team &b)
{
    if(a.points!=b.points) return a.points>b.points;
    if(a.wins!=b.wins) return a.wins>b.wins;
    if(a.goaldiff!=b.goaldiff) return a.goaldiff>b.goaldiff;
    if(a.goalscored!=b.goalscored) return a.goalscored>b.goalscored;
    if(a.matches!=b.matches) return a.matches<b.matches;
    return a.nameM < b.nameM;
}
int main()
{
    int n,t,m;
    scanf("%d\n",&n);
    team x[31];
    while(n--)
    {
        map<string,int>mp;
        char namet[101];
        gets(namet);
        scanf("%d\n",&t);
        for(int i=0; i<t; i++)
        {
            string s;
            getline(cin,s);
            x[i] = team(s);
            mp[s] =i;
        }

        scanf("%d",&m);
        getchar();
        string name1;
        string name2;
        while(m--)
        {
            stringstream ss;
            int a,b;
            string in;
            getline(cin,in);
            int fa = in.find('#');
            name1=string(in.begin(),in.begin()+fa);
            in.erase(in.begin(),in.begin()+fa+1);
            fa = in.find('#');
            sscanf(string(in.begin(),in.begin()+fa).c_str(),"%d@%d#",&a,&b);
            in.erase(in.begin(),in.begin()+fa+1);
            name2 = in;
            int f1 = mp[name1];
            x[f1].mod(a,b);
            f1 = mp[name2];
            x[f1].mod(b,a);
        }
        sort(x,x+t,comp);
        printf("%s\n",namet);
        for(int i=0; i<t; i++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,x[i].name.c_str(),x[i].points,x[i].matches,x[i].wins,x[i].tie,x[i].loses,x[i].goaldiff,x[i].goalscored,x[i].goalsagainst);
        if(n)printf("\n");
    }
    return 0;
}
