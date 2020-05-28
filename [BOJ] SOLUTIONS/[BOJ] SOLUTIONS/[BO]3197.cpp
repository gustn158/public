/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int r, c;
char map[1501][1501];
queue <pair<int, int>> SQ, SQCMP, WQ, WQCMP;
int sx=-1, sy;
bool flag = false;
bool check[1501][1501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void SQ_BFS()
{
	while (!SQ.empty() && flag == false)
	{
		pair<int, int> cp = SQ.front();
		SQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x < 1 || new_y < 1 || new_x > r || new_y > c)
				continue;
			if (!check[new_x][new_y])
			{
				if (map[new_x][new_y] == '.')
				{
					check[new_x][new_y] = true;
					SQ.push({ new_x,new_y });
				}
				else if (map[new_x][new_y] == 'L')
				{
					flag = true;
					check[new_x][new_y] = true;
					break;
				}
				else if (map[new_x][new_y] == 'X')
				{
					check[new_x][new_y] = true;
					SQCMP.push({ new_x,new_y });
				}
			}
		}
	}
}
void WQ_BFS()
{
	while (!WQ.empty())
	{
		pair <int, int> cp = WQ.front();
		WQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x< 1 || new_y < 1 || new_x >r || new_y > c)
				continue;
			if (map[new_x][new_y] == 'X')
			{
				map[new_x][new_y] = '.';
				WQCMP.push({ new_x,new_y });
			}
		}
	}
}
int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= c; j++)
		{
			map[i][j] = s[j - 1];
			if (map[i][j] != 'X')
				WQ.push({ i,j });
			if (map[i][j] == 'L' && sx == -1)
			{
				sx = i;
				sy = j;
			}
		}
	}
	int ans = 0;
	SQ.push({ sx,sy });
	check[sx][sy] = true;
	while (flag == false)
	{
		SQ_BFS();
		if (flag == false)
		{
			WQ_BFS();
			SQ = SQCMP;
			WQ = WQCMP;
			while (!SQCMP.empty())SQCMP.pop();
			while (!WQCMP.empty())WQCMP.pop();
			ans++;
		}
	}
	cout << ans;
}
*/