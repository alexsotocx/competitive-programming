#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
string s;
bool comp(const char &a, const char &b) {
	int delta = tolower(a) - tolower(b);
	return delta ? delta < 0 : a <b;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T-- && cin >> s) {
		sort(s.begin(), s.end(), comp);
		do
			printf("%s\n",s.c_str());
		while (next_permutation(s.begin(), s.end(), comp));
	}
	return 0;
}

