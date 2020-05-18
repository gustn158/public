/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sx, sy;
int ex, ey;
int map[1002][1002];
int ans = 0;
bool check[1002][1002];
int cache[1001][1001][2];
void BFS(int x, int y)
{
	bool ret = false;
	queue<tuple <int, int, int> > q;
	q.push({ sx,sy,1 });
	check[sx][sy] = true;
	cache[sx][sy][1] = 0;
	while (!q.empty())
	{
		tuple <int, int, int> cp = q.front();
		q.pop();

		if (get<0>(cp) == ex && get<1>(cp) == ey)
		{
			cout << cache[ex][ey][get<2>(cp)];
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = get<0>(cp) +dx[i];
			int new_y = get<1>(cp) + dy[i];
			int new_z = get<2>(cp);
			if (new_x <= 0 || new_y <= 0 || new_x > n || new_y > m)
				continue;
			if (map[new_x][new_y])
			{
				if (new_z == 0)
					continue;
				else
					new_z = 0;
			}
			if (cache[new_x][new_y][new_z] == -1)
			{
				q.push({ new_x,new_y,new_z });
				cache[new_x][new_y][new_z] = cache[get<0>(cp)][get<1>(cp)][get<2>(cp)]+1;
			}
		}
	
	}
	cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> ex >> ey;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		
		}
	}
	memset(cache, -1, sizeof(cache));
	BFS(sx, sy);
	
}
*/