/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
char map[51][51];
bool check[64][51][51];
int sx, sy;
int ex, ey;
int sum;
bool key[27];
vector <pair<int, int>> loc;
int Bfs()
{
	check[0][sx][sy] = true;
	queue < pair<pair<int, int>, pair<int,int> >> q;
	q.push({ {sx,sy},{0,0} });

	while (!q.empty())
	{
		pair<int, int> cp = q.front().first;
		int cnt = q.front().second.first;
		int key = q.front().second.second;
		q.pop();
		if (map[cp.first][cp.second] == '1')
			return cnt;
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && !check[key][new_x][new_y] && map[new_x][new_y] != '#')
			{
				if (map[new_x][new_y] == '.' || map[new_x][new_y] == '0' || map[new_x][new_y] == '1')
				{
					check[key][new_x][new_y] = true;
					q.push({ {new_x,new_y},{cnt+1,key} });
				}
				else if (map[new_x][new_y] >= 'a' && map[new_x][new_y] <= 'z')
				{
					int new_key = key | (1 << (int)(map[new_x][new_y] - 97));

					if (!check[new_key][new_x][new_y])
					{
						check[new_key][new_x][new_y] = true;
						check[key][new_x][new_y] = true;
						q.push({ {new_x,new_y},{cnt+1,new_key} });
					}
				}
				else if (map[new_x][new_y] >= 'A' && map[new_x][new_y] <= 'Z')
				{
					if (key & (1 << (int)(map[new_x][new_y] - 65)))
					{
						check[key][new_x][new_y] = true;
						q.push({ {new_x,new_y},{cnt+1,key} });
					}
				}
			}
			
		}
	}

	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1];
			if (map[i][j] == '0')
			{
				sx = i;
				sy = j;
			}
		}
	}
	cout << Bfs();

	
}
*/