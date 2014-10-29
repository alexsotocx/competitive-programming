#include<bits/stdc++.h>
using namespace std;

#define yo pair<int, int>
#define xyo pair<int, yo >

int n, m;
vector<vector<int> >graph;
string orientation;
int Xi, Yi, Xf, Yf;
map<string, int> orientationtoNum;
bool visited[51][51][5];

bool valid(int x, int y, int dir)
{
	return x >= 0 && x <= n && y >= 0 && y <= m && !visited[x][y][dir] && graph[x][y]!=1;
}

void move(int &x, int &y, int dir)
{
	if (dir == 0)
		x--;
	else if (dir == 1)
        y++;
    else if(dir ==2)
        x++;
    else
        y--;
}

int BFS()
{
	memset(visited, 0, sizeof(visited));
	queue<xyo>q;
	queue<int>distance;
	int ors = orientationtoNum[orientation];
	q.push(xyo(Xi, yo(Yi, ors)));
	visited[Xi][Yi][orientationtoNum[orientation]] = 1;
	distance.push(0);
	while (!q.empty())
	{
		xyo pos = q.front(); q.pop();
		int d = distance.front(); distance.pop();
		int x = pos.first, y = pos.second.first, dir = pos.second.second;
		if (x == Xf && Yf == y)
			return d;
		int auxdir = (dir + 1 + 4) % 4;
		if (valid(x, y, auxdir))
		{
			q.push(xyo(x, yo(y, auxdir)));
			visited[x][y][auxdir] = 1;
			distance.push(d+1);
		}
		auxdir = (dir - 1 + 4) % 4;
		if (valid(x, y, auxdir))
		{
			q.push(xyo(x, yo(y, auxdir)));
			visited[x][y][auxdir] = 1;
			distance.push(d+1);
		}
        move(x,y,dir);
        if(valid(x,y,dir))
        {
            q.push(xyo(x, yo(y, dir)));
			visited[x][y][dir] = 1;
			distance.push(d+1);
        }
	}
	return -1;
}
int main()
{
	orientationtoNum["north"] = 0;
	orientationtoNum["west"] = 1;
	orientationtoNum["south"] = 2;
	orientationtoNum["east"] = 3;
	while (cin >> n >> m && n + m)
	{
		graph = vector<vector<int> >(n+1, vector<int>(m+1, 0));
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
		cin >> Xi >> Yi >> Xf >> Yf >> orientation;
		Xi--, Yi--, Xf--, Yf--;
		cout << BFS() << endl;

	}
	return 0;
}
