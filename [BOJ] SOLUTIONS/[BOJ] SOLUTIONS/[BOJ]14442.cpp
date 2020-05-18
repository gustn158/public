/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
int map[1001][1001];
bool check[1001][1001][11];
int n, m, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minlen = 987654321;
void Bfs(int x, int y)
{
	queue <tuple<int, int, int, int>> q;
	check[x][y][0] = true;
	q.push({ x,y,0,1 });

	while (!q.empty())
	{
		tuple <int, int, int, int> cp = q.front();
		q.pop();
		if (get<0>(cp) == n && get<1>(cp) == m)
		{
			cout << get<3>(cp);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = get<0>(cp) + dx[i];
			int new_y = get<1>(cp) + dy[i];
			int new_z = get<2>(cp);
			int level = get<3>(cp);
			if (new_x < 1 || new_y < 1 || new_x > n || new_y > m)
				continue;
			if (!check[new_x][new_y][new_z])
			{
				if (map[new_x][new_y] == 1)
				{
					if (new_z < k)
					{
						check[new_x][new_y][new_z + 1] = true;
						q.push({ new_x,new_y,new_z + 1,level + 1 });
					}
					else
						continue;
				}
				else
				{
					check[new_x][new_y][new_z] = true;
					q.push({ new_x,new_y,new_z,level + 1 });
				}
			}
		}
	}
	cout << -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1]-'0';
		}
	}
	
	Bfs(1, 1);
}
*/