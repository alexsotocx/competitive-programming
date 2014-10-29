#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<map>
using namespace std;
int main()
{
    //freopen("in.in","r",stdin);
    map<char,char> mymap;
    map<char,char>::iterator it;
    mymap['B'] = '1';
    mymap['F'] = '1';
    mymap['P'] = '1';
    mymap['V'] = '1';

    //mymap["CGJKQSXZ"]='2';
    mymap['C'] = '2';
    mymap['G'] = '2';
    mymap['J'] = '2';
    mymap['K'] = '2';
    mymap['Q'] = '2';
    mymap['S'] = '2';
    mymap['X'] = '2';
    mymap['Z'] = '2';

    //mymap["DT"]='3';
    mymap['D'] = '3';
    mymap['T'] = '3';
    mymap['L'] = '4';
    //mymap["MN"]='5';
    mymap['M'] = '5';
    mymap['N'] = '5';
    mymap['R'] = '6';
    //mymap["AEIOUHWY"]=32;
    mymap['A'] = ' ';
    mymap['E'] = ' ';
    mymap['I'] = ' ';
    mymap['O'] = ' ';
    mymap['U'] = ' ';
    mymap['H'] = ' ';
    mymap['W'] = ' ';
    mymap['Y'] = ' ';
    string in;
    stringstream ss;
    while(cin>>in)
    {
        char it2='0';
        for(int i=0; i<in.length(); i++)
        {
            it = mymap.find(in[i]);
            if(it2==it->second)
                continue;
            else if(it->second != 32)
                ss<<it->second;
            it2 = it->second;
        }
        ss<<"\n";
    }
    printf("%s",ss.str().c_str());
    return 0;
}

