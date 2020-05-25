/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int map[51][51];
int full[51][51];
bool check[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sum = 0;
int max_height;
int min_height;
void bfs(int i, int j,int height)
{
	check[i][j] = true;
	queue <pair<int, int>> q;
	q.push({ i,j });
	
	while (!q.empty())
	{
		pair <int, int> cp = q.front();
		q.pop();
		full[cp.first][cp.second]--;
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (check[new_x][new_y])
				continue;
			if (new_x == 1 || new_y == 1 || new_x == n || new_y == m)
				continue;
			if (map[new_x][new_y] + full[new_x][new_y] == height && full[new_x][new_y] > 0)
			{
				q.push({ new_x,new_y });
				check[new_x][new_y] = true;
			}

		}
	}

}
void SLV()
{
	for (int h = max_height; h > min_height; h--)
	{
		memset(check, false, sizeof(check));
		for (int i = 2; i < n; i++)
		{
			for (int j = 2; j < m; j++)
			{
				if (full[i][j] > 0 && !check[i][j])
				{
					for (int k = 0; k < 4; k++)
					{
						int new_x = i + dx[k];
						int new_y = j + dy[k];
						if (map[new_x][new_y] + full[new_x][new_y] < map[i][j] + full[i][j])
						{
							bfs(i, j, h);
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			if(full[i][j] > 0)
				sum += full[i][j];
		}
	}
	cout << sum;
}
int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1]-'0';
			max_height = max(max_height, map[i][j]);
			min_height = min(min_height, map[i][j]);
		}
	}
	for (int i = 2; i <= n-1; i++)
	{
		for (int j = 2; j <= m-1; j++)
		{
			full[i][j] = max_height - map[i][j];
		}
	}
	SLV();
}
*/