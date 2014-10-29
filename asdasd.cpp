#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int low;
int up;
bool IsOdd(int k) {return (k<up && k>low);}

class PointErasingTwo {
public:

public:

	int getMaximum(vector <int> y) {
		int ret=0;
		for(int i=0;i<y.size()-1;i++)
		{
			for(int j=i+1;j<y.size();j++)
			{
				up = max(y[i],y[j]);
				low = min(y[i],y[j]);
				vector<int>::iterator t1,t2;
				t1 = (y.begin());
				t2 = (y.end());
				int aux = (int) count_if (y.begin(),y.end(), IsOdd);
				ret = max(ret,aux);
			}
		}
		return ret;
	}

};


int main()
{
    PointErasingTwo b;
    int x []= { 1, 2, 1, 1, 0, 4, 3 };
    vector<int> aux(x, x+7);
    cout<<b.getMaximum(aux);
    return 0;

}
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
