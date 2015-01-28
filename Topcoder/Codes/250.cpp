#include<bits/stdc++.h>
using namespace std;
struct LotteryTicket
{
	int *coins;
	string buy(int price, int a, int b, int c, int d){
		coins = {a,b,c,d};
	}

	bool solve(accomulate, goal){
		if(goal > accomulate)
			return false;
		else if(goal == accomulate)
			return true;
		else{
			for(int i = 0; i < 4; i++){
				if(solve(accomulate + coins[i], goal))
					return true;
			}
		}
	}
};