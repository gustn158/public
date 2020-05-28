/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int k, n, m;
int map[201][201];
int dx[12] = { -1,1,0,0,-1,-2,-2,-1,1,2,2,1 };
int dy[12] = { 0,0,-1,1,-2,-1,1,2,-2,-1,1,2 };
bool check[201][201][31];
void Bfs()
{
	queue <pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {0,0},{k,0} });
	check[0][0][k] = true;
	
	while (!q.empty())
	{
		pair<int, int> cp = q.front().first;
		int level = q.front().second.second;
		int flag = q.front().second.first;
		q.pop();
		if (cp.first == m - 1 && cp.second == n - 1)
		{
			cout << level;
			exit(0);
		}
		for (int i = 0; i < 12; i++)
		{
			if (i < 4)
			{
				int new_x = cp.first + dx[i];
				int new_y = cp.second + dy[i];

				if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
					continue;
				if (!check[new_x][new_y][flag] && map[new_x][new_y] == 0)
				{
					check[new_x][new_y][flag] = true;

					q.push({ {new_x,new_y},{flag,level + 1 } });
				}
			}
			else if(i >= 4 && flag > 0)
			{
				int new_x = cp.first + dx[i];
				int new_y = cp.second + dy[i];

				if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
					continue;
				if (!check[new_x][new_y][flag-1] && map[new_x][new_y] == 0)
				{
					check[new_x][new_y][flag-1] = true;

					q.push({ {new_x,new_y},{flag-1,level + 1 } });
				}
			}
		}
	}
	cout << -1;
}
int main()
{
	cin >> k;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	Bfs();
}
*/