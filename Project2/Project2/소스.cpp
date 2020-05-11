#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[101][101];
void Bfs(int x, int y, int cnt)
{
	check[x][y] = true;
	queue <pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = cnt;
	while (!q.empty())
	{
		pair <int, int> cp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
				continue;
			if (!check[new_x][new_y] && map[new_x][new_y] == 1)
			{
				check[new_x][new_y] = true;
				q.push({ new_x,new_y });
				map[new_x][new_y] = cnt;
			}
		}
	}
}
int far(int x, int y)
{
	queue <pair<pair<int, int>, int>> q;
	check[x][y] = true;
	q.push({ {x,y} ,0 });
	int color = map[x][y];

	while (!q.empty())
	{
		pair <int, int> cp = q.front().first;
		int level = q.front().second;
		q.pop();
		if (map[cp.first][cp.second] != color)
		{
			if (map[cp.first][cp.second] != 0)
				return level;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
				continue;
			if (!check[new_x][new_y] && (map[new_x][new_y] != color))
			{
				check[new_x][new_y] = true;
				q.push({ { new_x,new_y },level + 1 });

			}
		}

	}
	return 999999999;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 1 && !check[i][j])
			{
				Bfs(i, j, cnt);
				cnt++;
			}
	int mindist = 999999999;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			memset(check, false, sizeof(check));
			if (map[i][j] != 0)
				mindist = min(mindist, far(i, j));
		}
	}
	cout << mindist - 1;
}
//¼öÁ¤